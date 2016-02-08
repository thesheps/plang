﻿using System;
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
                        var op = (IOperatorExpressionNode)expressionNode;
                        AddOperand(operandString);

                        if (_operators.Any() &&
                            (op.Associativity == Associativity.Left && op.Precedence <= _operators.Peek().Precedence) ||
                            (op.Associativity == Associativity.Right && op.Precedence < _operators.Peek().Precedence))
                        {
                            ProcessOperation();
                        }

                        _operators.Push(op);
                        operandString = string.Empty;
                    }
                }
            }

            AddOperand(operandString);
            ProcessOperation();

            return _operands.Peek().Value;
        }

        private void AddOperand(string operandString)
        {
            if (!string.IsNullOrEmpty(operandString))
                _operands.Enqueue(new OperandExpressionNode(int.Parse(operandString)));
        }

        private void ProcessOperation()
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