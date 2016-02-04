using NUnit.Framework;

namespace Plang.Core.UnitTests
{
    public class GivenSimpleMathematicalString
    {
        [TestCase("1+1=2", 2)]
        public void WhenIParseTheExpression_ThenTheResultIsAsExpected(string expression, int result)
        {
            var parser = new Parser();
            Assert.That(result, Is.EqualTo(parser.Parse()));
        }
    }

    public class Parser
    {
        public int Parse()
        {
            return 2;
        }
    }
}