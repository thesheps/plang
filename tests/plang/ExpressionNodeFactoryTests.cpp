#include <catch.hpp>

#include <plang/plang.h>
#include <plang/TokenStream.h>
#include <plang/ExpressionNode.h>
#include <plang/ExpressionNodeFactory.h>

#include <string>

using namespace plang;

SCENARIO("Mathematical expression is tokenised to ExpressionNodes", "[parsing][tokenisation][expressions]") {
	GIVEN("Mathematical expression") {
		char buf[] = "1 + 1";
		TokenStream tokstr(buf);
	
		WHEN("The sum is parsed") {
			ExpressionNodeFactory factory;
			ExpressionNode* e1 = factory.create(tokstr.getNext());
			ExpressionNode* e2 = factory.create(tokstr.getNext());
			ExpressionNode* e3 = factory.create(tokstr.getNext());

			THEN("Then the resultant ExpressionNodes are of the correct type") {
				REQUIRE(e1->expressionNodeType == ExpressionNode::kTypeOperand);
				REQUIRE(e2->expressionNodeType == ExpressionNode::kTypeOperator);
				REQUIRE(e3->expressionNodeType == ExpressionNode::kTypeOperand);
			}
		}
	}
}