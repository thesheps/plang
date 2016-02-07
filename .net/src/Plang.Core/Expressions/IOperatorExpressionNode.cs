namespace Plang.Core.Expressions
{
    public interface IOperatorExpressionNode : IExpressionNode
    {
        int Execute(OperandExpressionNode operand1, OperandExpressionNode operand2);
    }
}