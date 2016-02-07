namespace Plang.Core.Expressions
{
    public class OperandExpressionNode : ExpressionNode
    {
        public int Value { get; }

        public OperandExpressionNode(int value)
        {
            Value = value;
        }
    }
}