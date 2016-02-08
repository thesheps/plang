namespace Plang.Core.Expressions
{
    public class SubtractionOperatorExpressionNode : IOperatorExpressionNode
    {
        public Associativity Associativity  => Associativity.Left;
        public int Precedence => 2;

        public OperandExpressionNode Execute(OperandExpressionNode operand1, OperandExpressionNode operand2)
        {
            return new OperandExpressionNode(operand1.Value - operand2.Value);
        }
    }
}