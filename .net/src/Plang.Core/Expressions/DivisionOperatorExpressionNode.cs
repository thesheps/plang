namespace Plang.Core.Expressions
{
    public class DivisionOperatorExpressionNode : IOperatorExpressionNode
    {
        public Associativity Associativity  => Associativity.Left;
        public int Precedence => 3;

        public OperandExpressionNode Execute(OperandExpressionNode operand1, OperandExpressionNode operand2)
        {
            return new OperandExpressionNode(operand1.Value / operand2.Value);
        }
    }
}