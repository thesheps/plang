namespace Plang.Core.Expressions
{
    public class NullOperandExpressionNode : IExpressionNode
    {
    }

    public class OperandExpressionNode : IExpressionNode
    {
        public int Value { get; }

        public OperandExpressionNode(int value)
        {
            Value = value;
        }
    }
}