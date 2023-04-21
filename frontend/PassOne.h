#include <iostream>
#include <string>

#include "antlr4-runtime.h"
#include "../PascalBaseVisitor.h"

namespace frontend {

using namespace std;

class PassOne : public pascalBaseVisitor
{
private:

public:
    PassOne()
    {
        
    }

    virtual antlrcpp::Any visitAssignmentStatement(pascalParser::AssignmentStatementContext *ctx) override 
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitExpression(pascalParser::ExpressionContext *ctx) override {
        // visit lhs
        // visit rhs
        // check if lhs.type = rhs.type
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitSimpleExpression(pascalParser::SimpleExpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTerm(pascalParser::TermContext *ctx) override {
        return visitChildren(ctx);
    }

};

} // namespace frontend