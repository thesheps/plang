using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
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
                var expressionNode = CreateExpressionNode(Convert.ToChar(i));

                if (expressionNode is NullOperandExpressionNode)
                    operandString += Convert.ToChar(i);
                else
                {
                    var op = (IOperatorExpressionNode)expressionNode;

                    if (!string.IsNullOrEmpty(operandString))
                        _operands.Enqueue(new OperandExpressionNode(int.Parse(operandString)));

                    if (_operators.Any() && (op.Associativity == Associativity.Left && op.Precedence <= _operators.Peek().Precedence))
                    {
                        ProcessOperation();
                    }

                    _operators.Push(op);
                    operandString = string.Empty;
                }

                i = stream.ReadByte();
            } while (i > -1);

            if (!string.IsNullOrEmpty(operandString))
                _operands.Enqueue(new OperandExpressionNode(int.Parse(operandString)));

            ProcessOperation();

            return _operands.Peek().Value;
        }

        private void ProcessOperation()
        {
            var operation = _operators.Pop();
            var op1 = _operands.Dequeue();
            var op2 = _operands.Dequeue();
            _operands.Enqueue(operation.Execute(op1, op2));
        }

        private static IExpressionNode CreateExpressionNode(char c)
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
                case '^':
                    return new ExponentiationOperatorExpressionNode();
                default:
                    return new NullOperandExpressionNode();
            }
        }

        private readonly Stack<IOperatorExpressionNode> _operators = new Stack<IOperatorExpressionNode>();
        private readonly Queue<OperandExpressionNode> _operands = new Queue<OperandExpressionNode>();
    }
}