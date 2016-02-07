namespace Plang.Core.Expressions
{
    public abstract class OperatorExpressionNode : ExpressionNode
    {
        public abstract int Execute(OperandExpressionNode operand1, OperandExpressionNode operand2);
    }
}