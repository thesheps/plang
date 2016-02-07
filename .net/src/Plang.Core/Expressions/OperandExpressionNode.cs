namespace Plang.Core.Expressions
{
    public class NullOperandExpressionNode : ExpressionNode
    {
    }

    public class OperandExpressionNode : ExpressionNode
    {
        public int Value { get; }

        public OperandExpressionNode(int value)
        {
            Value = value;
        }
    }
}