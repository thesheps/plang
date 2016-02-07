using System;
using System.Collections.Generic;
using System.IO;
using NUnit.Framework;
using Plang.Core.Tokens;

namespace Plang.Core.UnitTests
{
    public class GivenMathematicalExpressions
    {
        [TestCase("1+1", 2)]
        [TestCase("5-1", 4)]
        [TestCase("7*7", 49)]
        [TestCase("9/3", 3)]
        public void WhenIParseTheExpression_ThenTheResultIsAsExpected(string expression, int expectedResult)
        {
            var parser = new Parser();
            var stream = new MemoryStream();
            var writer = new StreamWriter(stream);
            writer.Write(expression);
            writer.Flush();
            stream.Position = 0;

            Assert.That(parser.Parse(stream), Is.EqualTo(expectedResult));
        }
    }

    public class Parser
    {
        public int Parse(Stream stream)
        {
            var operators = new List<Operator>();
            var operands = new List<Operand>();
            var i = stream.ReadByte();

            do
            {
                var c = Convert.ToChar(i);

                switch (c)
                {
                    case '+':
                        operators.Add(new AdditionOperator());
                        break;

                    case '-':
                        operators.Add(new SubtractionOperator());
                        break;

                    case '*':
                        operators.Add(new MultiplicationOperator());
                        break;

                    case '/':
                        operators.Add(new DivisionOperator());
                        break;

                    default:
                        operands.Add(new Operand(int.Parse(c.ToString())));
                        break;
                }

                i = stream.ReadByte();
            } while (i > -1);

            return operators[0].Execute(operands[0], operands[1]);
        }
    }
}