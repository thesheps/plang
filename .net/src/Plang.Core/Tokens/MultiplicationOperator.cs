namespace Plang.Core.Tokens
{
    public class MultiplicationOperator : Operator
    {
        public override int Execute(Operand operand1, Operand operand2)
        {
            return operand1.Value * operand2.Value;
        }
    }
}