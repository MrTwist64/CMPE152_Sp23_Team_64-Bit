#include <iostream>

#include "../intermediate/symtab/SymtabStack.h"
#include "../intermediate/symtab/Predefined.h"
#include "../intermediate/type/TypeChecker.h"
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime.h"
#include "../PascalBaseVisitor.h"

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class PassTwo : public pascalBaseVisitor
{
private:
    Predefined* pred;
    SymtabStack* stack;
    TypeChecker* typeChecker;
 
public:
    PassTwo(Predefined *pred)
    {
        this->pred = pred;
        stack = new SymtabStack();
        this->pred->initialize(stack);
        typeChecker = new TypeChecker(pred);
    }

    

    SymtabStack* getStack() {return stack;}

    virtual antlrcpp::Any visitProgram(pascalParser::ProgramContext *ctx) override 
    {
        visit(ctx->programHeader());
        visit(ctx->block());
        return nullptr;
    }

    virtual antlrcpp::Any visitProgramHeader(pascalParser::ProgramHeaderContext *ctx) override 
    {
        pascalParser::ProgramIdentifierContext *proIdCtx = ctx->programIdentifier();
        proIdCtx->entry = stack->enterLocal(proIdCtx->IDENTIFIER()->getText(), Kind::PROGRAM);

        Symtab* newTable = stack->push();
        newTable->setOwner(proIdCtx->entry);

        visit(ctx->programParameters());

        return nullptr;
    }

    virtual antlrcpp::Any visitProgramParameters(pascalParser::ProgramParametersContext *ctx) override 
    {
        
        return nullptr;
    }

    virtual antlrcpp::Any visitVariableDeclarations(pascalParser::VariableDeclarationsContext *ctx) override 
    {
        pascalParser::TypeSpecificationContext *typespecCtx = ctx->typeSpecification();
        visit(typespecCtx);
        pascalParser::VariableIdentifierListContext *varIdListCtx = ctx->variableIdentifierList();
        
        for(pascalParser::VariableIdentifierContext *idCtx : varIdListCtx->variableIdentifier()) {
            idCtx->type = typespecCtx->type;
            idCtx->entry = stack->enterLocal(idCtx->IDENTIFIER()->getText(), Kind::VARIABLE);
            idCtx->entry->setType(idCtx->type);
        }
        //varDecCtx->entry = stack->enterLocal(varDecCtx->IDENTIFIER()->getText(), K)
        return nullptr;
    }

    virtual antlrcpp::Any visitTypeIdentifier(pascalParser::TypeIdentifierContext *ctx) override {
        ctx->entry = stack->lookup(ctx->IDENTIFIER()->getText());
        ctx->type = ctx->entry->getType();
        return nullptr;
    }

    virtual antlrcpp::Any visitSimpleTypespec(pascalParser::SimpleTypespecContext *ctx) override
    {
        visit(ctx->simpleType());
        ctx->type = ctx->simpleType()->type;
        return nullptr;
    }

    virtual antlrcpp::Any visitArrayTypespec(pascalParser::ArrayTypespecContext *ctx) override {


        return nullptr;
    }

    virtual antlrcpp::Any visitTypeIdentifierTypespec(pascalParser::TypeIdentifierTypespecContext *ctx) override
    {
        visit(ctx->typeIdentifier());
        ctx->type = ctx->typeIdentifier()->type;
        return nullptr;
    }

    virtual antlrcpp::Any visitEnumerationTypespec(pascalParser::EnumerationTypespecContext *ctx) override
    {
        
        for (pascalParser::EnumerationConstantContext *constCtx : ctx->enumerationType()->enumerationConstant())
        {

        }

        return nullptr;
    }

    virtual antlrcpp::Any visitSubrangeTypespec(pascalParser::SubrangeTypespecContext *ctx) override
    {
        // pascalParser::ConstantContext *lowerCtx = ctx->

        return nullptr;
    }

    virtual antlrcpp::Any visitAssignmentStatement(pascalParser::AssignmentStatementContext *ctx) override // NOT DONE !!! NEEDS WORK (REFER TO visitexpression)
    {
        pascalParser::LhsContext *lhsCtx = ctx->lhs();
        pascalParser::RhsContext *rhsCtx = ctx->rhs();

        visitChildren(ctx);

        Typespec *lhsType = lhsCtx->type;
        Typespec *rhsType = rhsCtx->expression()->type;

        if (!typeChecker->areAssignmentCompatible(lhsType, rhsType))
        {
            cout << "Error: Incompatible assignment between ";
            cout << lhsType->getIdentifier()->getName();
            cout << " and ";
            cout << rhsType->getIdentifier()->getName();
            cout << endl;
        }

        return nullptr;
    }

    virtual antlrcpp::Any visitExpression(pascalParser::ExpressionContext *ctx) override // NOT DONE !!! NEEDS WORK
    {
        pascalParser::SimpleExpressionContext *simpleCtx1 = ctx->simpleExpression()[0];

        visit(simpleCtx1);

        Typespec *simpleType1 = simpleCtx1->type;
        ctx->type = simpleType1;

        pascalParser::RelOpContext *relopCtx = ctx->relOp();

        if (relopCtx != nullptr)
        {
            pascalParser::SimpleExpressionContext *simpleCtx2 =
                                                        ctx->simpleExpression()[1];
            visit(simpleCtx2);

            Typespec *simpleType2 = simpleCtx2->type;
            if (!typeChecker->areComparisonCompatible(simpleType1, simpleType2))
            {
                //error.flag(INCOMPATIBLE_COMPARISON, ctx);
            }

            ctx->type = pred->booleanType;
        }

        return nullptr;
    }

    virtual antlrcpp::Any visitLhs(pascalParser::LhsContext *ctx) override
    {
        visit(ctx->variable());
        ctx->type = ctx->variable()->type;

        return nullptr;
    }

    virtual antlrcpp::Any visitSimpleExpression(pascalParser::SimpleExpressionContext *ctx) override {
        pascalParser::SignContext* signCtx = ctx->sign();
        if (signCtx != nullptr)
            string sign = signCtx->getText(); // Do we need this?
        
        visitChildren(ctx);
        
        int numTerms = ctx->term().size();
        if (numTerms > 1) 
        {
            // TODO: Add support for (+, -, OR) operations
        }

        ctx->type = ctx->term()[0]->type; // TODO: Change once we add support to operations above
        
        return nullptr;
    }

    virtual antlrcpp::Any visitTerm(pascalParser::TermContext *ctx) override {
        visitChildren(ctx);

        int numFactors = ctx->factor().size();
        if (numFactors > 1) 
        {
            // TODO: Add support for (*, /, DIV, MOD, AND) operations
        }

        ctx->type = ctx->factor()[0]->type; // TODO: Change once we add support to operations above
        
        return nullptr;
    }

    virtual antlrcpp::Any visitVariableFactor(pascalParser::VariableFactorContext *ctx) override
    {        
        return nullptr;
    }

    virtual antlrcpp::Any visitNumberFactor(pascalParser::NumberFactorContext *ctx) override
    {
        pascalParser::SignContext* signCtx = ctx->number()->sign();
        if (signCtx != nullptr)
            string sign = signCtx->getText(); // Do we need this?
        
        pascalParser::UnsignedNumberContext* unsignNumCtx = ctx->number()->unsignedNumber();
        if (unsignNumCtx->integerConstant() == nullptr)
            ctx->type = pred->realType;
        else
            ctx->type = pred->integerType;

        return nullptr;
    }

    virtual antlrcpp::Any visitCharacterFactor(pascalParser::CharacterFactorContext *ctx) override
    {
        return nullptr;
    }

    virtual antlrcpp::Any visitStringFactor(pascalParser::StringFactorContext *ctx) override
    {
        return nullptr;
    }

    virtual antlrcpp::Any visitFunctionCallFactor(pascalParser::FunctionCallFactorContext *ctx) override
    {
        return nullptr;
    }

    virtual antlrcpp::Any visitNotFactor(pascalParser::NotFactorContext *ctx) override
    {
        return nullptr;
    }

    virtual antlrcpp::Any visitParenthesizedFactor(pascalParser::ParenthesizedFactorContext *ctx) override
    {
        return nullptr;
    }

    virtual antlrcpp::Any visitSign(pascalParser::SignContext *ctx) override
    {
        return nullptr;
    }

    virtual antlrcpp::Any visitUnsignedNumber(pascalParser::UnsignedNumberContext *ctx) override
    {
        return nullptr;
    }

    virtual antlrcpp::Any visitVariable(pascalParser::VariableContext *ctx) override {
        pascalParser::VariableIdentifierContext *varIdCtx = ctx->variableIdentifier();
        visit(varIdCtx);
        ctx->entry = varIdCtx->entry;
        ctx->type = varIdCtx->type; // TODO: Check for modifier

        return nullptr;
    }

    virtual antlrcpp::Any visitVariableIdentifier(pascalParser::VariableIdentifierContext *ctx) override {
        ctx->entry = stack->lookup(ctx->IDENTIFIER()->getText());

        if (ctx->entry == nullptr)
        {
            // TODO: Add error variable not found
            cout << "visitVariableIdentifier() variable not found" << endl;
            return nullptr;
        }

        ctx->type = ctx->entry->getType();

        return nullptr;
    }

    /*
    pascalParser::ProgramIdentifierContext *proIdCtx = ctx->programIdentifier();
    proIdCtx->entry = stack->enterLocal(proIdCtx->IDENTIFIER()->getText(), Kind::PROGRAM);
    */

};

} // namespace frontend