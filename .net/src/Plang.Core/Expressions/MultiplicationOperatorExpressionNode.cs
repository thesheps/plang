namespace Plang.Core.Expressions
{
    public class MultiplicationOperatorExpressionNode : IOperatorExpressionNode
    {
        public int Execute(OperandExpressionNode operand1, OperandExpressionNode operand2)
        {
            return operand1.Value * operand2.Value;
        }
    }
}