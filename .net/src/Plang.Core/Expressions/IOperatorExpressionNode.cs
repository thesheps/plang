namespace Plang.Core.Expressions
{
    public interface IOperatorExpressionNode : IExpressionNode
    {
        int Precedence { get; }
        Associativity Associativity { get; }
        OperandExpressionNode Execute(OperandExpressionNode operand1, OperandExpressionNode operand2);
    }

    public enum Associativity
    {
        Left,
        Right
    }
}