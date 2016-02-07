using System;
using System.Collections.Generic;
using System.IO;
using Plang.Core.Exceptions;
using Plang.Core.Expressions;

namespace Plang.Core
{
    public class Parser
    {
        public int Parse(Stream stream)
        {
            if (stream == null) throw new NullStreamException();

            var i = stream.ReadByte();
            var operandString = string.Empty;

            do
            {
                var c = Convert.ToChar(i);
                var expressionNode = CreateExpressionNode(c);

                if (expressionNode is NullOperandExpressionNode)
                {
                    operandString += c;
                }
                else
                {
                    _operators.Add(expressionNode as OperatorExpressionNode);
                    AddOperand(operandString);
                    operandString = string.Empty;
                }

                i = stream.ReadByte();
            } while (i > -1);

            AddOperand(operandString);

            return _operators[0].Execute(_operands[0], _operands[1]);
        }

        private void AddOperand(string operand)
        {
            if (string.IsNullOrEmpty(operand)) return;
            _operands.Add(new OperandExpressionNode(int.Parse(operand)));
        }

        private static ExpressionNode CreateExpressionNode(char c)
        {
            switch (c)
            {
                case '+':
                    return new AdditionOperatorExpressionNode();
                case '-':
                    return new SubtractionOperatorExpressionNode();
                case '*':
                    return new MultiplicationOperatorExpressionNode();
                case '/':
                    return new DivisionOperatorExpressionNode();
                default:
                    return new NullOperandExpressionNode();
            }
        }

        private readonly IList<OperatorExpressionNode> _operators = new List<OperatorExpressionNode>();
        private readonly IList<OperandExpressionNode> _operands = new List<OperandExpressionNode>();
    }
}