using System.IO;
using NUnit.Framework;

namespace Plang.Core.UnitTests
{
    public class GivenMathematicalExpressions
    {
        [TestCase("1+1", 2)]
        [TestCase("5-1", 4)]
        [TestCase("7*7", 49)]
        [TestCase("9/3", 3)]
        public void WhenIParseAnExpressionWithSingleDigits_ThenTheResultIsAsExpected(string expression, int expectedResult)
        {
            var stream = GetStream(expression);
            var parser = new Parser();

            Assert.That(parser.Parse(stream), Is.EqualTo(expectedResult));
        }

        [TestCase("15+23", 38)]
        [TestCase("15-11", 4)]
        [TestCase("10*77", 770)]
        [TestCase("30/15", 2)]
        public void WhenIParseAnExpressionWithMultipleDigits_ThenTheResultIsAsExpected(string expression, int expectedResult)
        {
            var stream = GetStream(expression);
            var parser = new Parser();

            Assert.That(parser.Parse(stream), Is.EqualTo(expectedResult));
        }

        private static Stream GetStream(string expression)
        {
            var stream = new MemoryStream();
            var writer = new StreamWriter(stream);
            writer.Write(expression);
            writer.Flush();
            stream.Position = 0;
            return stream;
        }
    }
}