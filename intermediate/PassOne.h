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

    virtual std::any visitExpression(pascalParser::ExpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitSimpleExpression(pascalParser::SimpleExpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitTerm(pascalParser::TermContext *ctx) override {
        return visitChildren(ctx);
    }

};

} // namespace frontend