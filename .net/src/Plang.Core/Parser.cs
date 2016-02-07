using System;
using System.Collections.Generic;
using System.IO;
using Plang.Core.Expressions;

namespace Plang.Core
{
    public class Parser
    {
        public int Parse(Stream stream)
        {
            var operators = new List<OperatorExpressionNode>();
            var operands = new List<OperandExpressionNode>();
            var i = stream.ReadByte();
            var s = string.Empty;

            do
            {
                var c = Convert.ToChar(i);

                if (IsOperator(c))
                {
                    if (!string.IsNullOrEmpty(s))
                    {
                        operands.Add(new OperandExpressionNode(int.Parse(s)));
                        s = string.Empty;
                    }
                }

                switch (c)
                {
                    case '+':
                        operators.Add(new AdditionOperatorExpressionNode());
                        break;

                    case '-':
                        operators.Add(new SubtractionOperatorExpressionNode());
                        break;

                    case '*':
                        operators.Add(new MultiplicationOperatorExpressionNode());
                        break;

                    case '/':
                        operators.Add(new DivisionOperatorExpressionNode());
                        break;

                    default:
                        s += c.ToString();
                        break;
                }

                i = stream.ReadByte();
            } while (i > -1);

            operands.Add(new OperandExpressionNode(int.Parse(s)));

            return operators[0].Execute(operands[0], operands[1]);
        }

        private static bool IsOperator(char c)
        {
            return c == '+' || c == '-' || c == '*' || c == '/';
        }
    }
}