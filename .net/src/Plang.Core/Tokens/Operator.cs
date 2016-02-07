namespace Plang.Core.Tokens
{
    public abstract class Operator
    {
        public abstract int Execute(Operand operand1, Operand operand2);
    }
}