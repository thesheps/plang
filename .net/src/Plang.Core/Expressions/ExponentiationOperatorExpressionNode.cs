namespace Plang.Core.Expressions
{
    public class ExponentiationOperatorExpressionNode : IOperatorExpressionNode
    {
        public Associativity Associativity  => Associativity.Right;
        public int Precedence => 4;

        public OperandExpressionNode Execute(OperandExpressionNode operand1, OperandExpressionNode operand2)
        {
            return new OperandExpressionNode(operand1.Value ^ operand2.Value);
        }
    }
}