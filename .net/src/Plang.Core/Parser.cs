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
            var operandString = string.Empty;

            using (var streamReader = new StreamReader(stream))
            {
                while (!streamReader.EndOfStream)
                {
                    var c = Convert.ToChar(streamReader.Read());
                    var expressionNode = CreateExpressionNode(c);

                    if (expressionNode is NullOperandExpressionNode)
                        operandString += c;
                    else
                    {
                        PushOperand(operandString);
                        operandString = string.Empty;

                        var o1 = (IOperatorExpressionNode)expressionNode;

                        if (_operators.Any())
                        {
                            var o2 = _operators.Peek();

                            if (o1.Associativity == Associativity.Left && o1.Precedence <= o2.Precedence ||
                                o1.Associativity == Associativity.Right && o1.Precedence < o2.Precedence)
                            {
                                PopOperation();
                            }
                        }

                        _operators.Push(o1);
                    }
                }
            }

            PushOperand(operandString);
            PopOperation();

            return _operands.Peek().Value;
        }

        private void PushOperand(string operandString)
        {
            if (!string.IsNullOrEmpty(operandString))
                _operands.Enqueue(new OperandExpressionNode(int.Parse(operandString)));
        }

        private void PopOperation()
        {
            _operands.Enqueue(_operators.Pop().Execute(_operands.Dequeue(), _operands.Dequeue()));
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