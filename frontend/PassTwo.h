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
    
    // #1
    virtual antlrcpp::Any visitProgram(pascalParser::ProgramContext *ctx) override 
    {
        visit(ctx->programHeader());
        visit(ctx->block());



        return nullptr;
    }
    
    // #2
    virtual antlrcpp::Any visitProgramHeader(pascalParser::ProgramHeaderContext *ctx) override 
    {
        pascalParser::ProgramIdentifierContext *proIdCtx = ctx->programIdentifier();
        proIdCtx->entry = stack->enterLocal(proIdCtx->IDENTIFIER()->getText(), Kind::PROGRAM);

        Symtab* newTable = stack->push();
        newTable->setOwner(proIdCtx->entry);
        proIdCtx->entry->setChild(newTable);

        visit(ctx->programParameters());

        return nullptr;
    }
    
    // #3
    virtual antlrcpp::Any visitProgramParameters(pascalParser::ProgramParametersContext *ctx) override 
    {
        return visitChildren(ctx);
    }
    
    // #4
    virtual antlrcpp::Any visitProgramIdentifier(pascalParser::ProgramIdentifierContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #5
    virtual antlrcpp::Any visitBlock(pascalParser::BlockContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #6
    virtual antlrcpp::Any visitDeclarations(pascalParser::DeclarationsContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #7
    virtual antlrcpp::Any visitConstantsPart(pascalParser::ConstantsPartContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #8
    virtual antlrcpp::Any visitConstantDefinitionsList(pascalParser::ConstantDefinitionsListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #9
    virtual antlrcpp::Any visitConstantDefinition(pascalParser::ConstantDefinitionContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #10
    virtual antlrcpp::Any visitConstantIdentifier(pascalParser::ConstantIdentifierContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #11
    virtual antlrcpp::Any visitConstant(pascalParser::ConstantContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #12
    virtual antlrcpp::Any visitSign(pascalParser::SignContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #13
    virtual antlrcpp::Any visitTypesPart(pascalParser::TypesPartContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #14
    virtual antlrcpp::Any visitTypeDefinitionsList(pascalParser::TypeDefinitionsListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #15
    virtual antlrcpp::Any visitTypeDefinition(pascalParser::TypeDefinitionContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #16
    virtual antlrcpp::Any visitTypeIdentifier(pascalParser::TypeIdentifierContext *ctx) override {
        ctx->entry = stack->lookup(ctx->IDENTIFIER()->getText());
        ctx->type = ctx->entry->getType();
        return nullptr;
    }
    
    // #17
    virtual antlrcpp::Any visitSimpleTypespec(pascalParser::SimpleTypespecContext *ctx) override
    {
        visit(ctx->simpleType());
        ctx->type = ctx->simpleType()->type;
        return nullptr;
    }
    
    // #18
    virtual antlrcpp::Any visitArrayTypespec(pascalParser::ArrayTypespecContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #19
    virtual antlrcpp::Any visitRecordTypespec(pascalParser::RecordTypespecContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #20
    virtual antlrcpp::Any visitTypeIdentifierTypespec(pascalParser::TypeIdentifierTypespecContext *ctx) override
    {
        visit(ctx->typeIdentifier());
        ctx->type = ctx->typeIdentifier()->type;
        return nullptr;
    }
    
    // #21
    virtual antlrcpp::Any visitEnumerationTypespec(pascalParser::EnumerationTypespecContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #22
    virtual antlrcpp::Any visitSubrangeTypespec(pascalParser::SubrangeTypespecContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #23
    virtual antlrcpp::Any visitEnumerationType(pascalParser::EnumerationTypeContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #24
    virtual antlrcpp::Any visitEnumerationConstant(pascalParser::EnumerationConstantContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #25
    virtual antlrcpp::Any visitSubrangeType(pascalParser::SubrangeTypeContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #26
    virtual antlrcpp::Any visitArrayType(pascalParser::ArrayTypeContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #27
    virtual antlrcpp::Any visitArrayDimensionList(pascalParser::ArrayDimensionListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #28
    virtual antlrcpp::Any visitRecordType(pascalParser::RecordTypeContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #29
    virtual antlrcpp::Any visitRecordFields(pascalParser::RecordFieldsContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #30
    virtual antlrcpp::Any visitVariablesPart(pascalParser::VariablesPartContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #31
    virtual antlrcpp::Any visitVariableDeclarationsList(pascalParser::VariableDeclarationsListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #32
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

        return nullptr;
    }
    
    // #33
    virtual antlrcpp::Any visitVariableIdentifierList(pascalParser::VariableIdentifierListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #34
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
    
    // #35
    virtual antlrcpp::Any visitRoutinesPart(pascalParser::RoutinesPartContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #36
    virtual antlrcpp::Any visitRoutineDefinition(pascalParser::RoutineDefinitionContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #37
    virtual antlrcpp::Any visitProcedureHead(pascalParser::ProcedureHeadContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #38
    virtual antlrcpp::Any visitFunctionHead(pascalParser::FunctionHeadContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #39
    virtual antlrcpp::Any visitRoutineIdentifier(pascalParser::RoutineIdentifierContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #40
    virtual antlrcpp::Any visitParameters(pascalParser::ParametersContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #41
    virtual antlrcpp::Any visitParameterDeclarationsList(pascalParser::ParameterDeclarationsListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #42
    virtual antlrcpp::Any visitParameterDeclarations(pascalParser::ParameterDeclarationsContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #43
    virtual antlrcpp::Any visitParameterIdentifierList(pascalParser::ParameterIdentifierListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #44
    virtual antlrcpp::Any visitParameterIdentifier(pascalParser::ParameterIdentifierContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #45
    virtual antlrcpp::Any visitStatement(pascalParser::StatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #46
    virtual antlrcpp::Any visitCompoundStatement(pascalParser::CompoundStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #47
    virtual antlrcpp::Any visitEmptyStatement(pascalParser::EmptyStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #48
    virtual antlrcpp::Any visitStatementList(pascalParser::StatementListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #49
    virtual antlrcpp::Any visitAssignmentStatement(pascalParser::AssignmentStatementContext *ctx) override // NOT DONE !!! NEEDS WORK (REFER TO visitexpression)
    {
        pascalParser::LhsContext *lhsCtx = ctx->lhs();
        pascalParser::RhsContext *rhsCtx = ctx->rhs();

        visitChildren(ctx);

        Typespec *lhsType = lhsCtx->type;
        Typespec *rhsType = rhsCtx->expression()->type;

        if (!typeChecker->areAssignmentCompatible(lhsType, rhsType))
        {
            cout << "Error [";
            cout << ctx->getStart()->getLine();
            cout << "]: Incompatible assignment between ";
            cout << lhsType->getIdentifier()->getName();
            cout << " and ";
            cout << rhsType->getIdentifier()->getName();
            cout << endl;
        }

        return nullptr;
    }
    
    // #50
    virtual antlrcpp::Any visitLhs(pascalParser::LhsContext *ctx) override
    {
        visit(ctx->variable());
        ctx->type = ctx->variable()->type;

        return nullptr;
    }
    
    // #51
    virtual antlrcpp::Any visitRhs(pascalParser::RhsContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #52
    virtual antlrcpp::Any visitIfStatement(pascalParser::IfStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #53
    virtual antlrcpp::Any visitTrueStatement(pascalParser::TrueStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #54
    virtual antlrcpp::Any visitFalseStatement(pascalParser::FalseStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #55
    virtual antlrcpp::Any visitCaseStatement(pascalParser::CaseStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #56
    virtual antlrcpp::Any visitCaseBranchList(pascalParser::CaseBranchListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #57
    virtual antlrcpp::Any visitCaseBranch(pascalParser::CaseBranchContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #58
    virtual antlrcpp::Any visitCaseConstantList(pascalParser::CaseConstantListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #59
    virtual antlrcpp::Any visitCaseConstant(pascalParser::CaseConstantContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #60
    virtual antlrcpp::Any visitRepeatStatement(pascalParser::RepeatStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #61
    virtual antlrcpp::Any visitWhileStatement(pascalParser::WhileStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #62
    virtual antlrcpp::Any visitForStatement(pascalParser::ForStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #63
    virtual antlrcpp::Any visitProcedureCallStatement(pascalParser::ProcedureCallStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #64
    virtual antlrcpp::Any visitProcedureName(pascalParser::ProcedureNameContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #65
    virtual antlrcpp::Any visitArgumentList(pascalParser::ArgumentListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #66
    virtual antlrcpp::Any visitArgument(pascalParser::ArgumentContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #67
    virtual antlrcpp::Any visitWriteStatement(pascalParser::WriteStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #68
    virtual antlrcpp::Any visitWritelnStatement(pascalParser::WritelnStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #69
    virtual antlrcpp::Any visitWriteArguments(pascalParser::WriteArgumentsContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #70
    virtual antlrcpp::Any visitWriteArgument(pascalParser::WriteArgumentContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #71
    virtual antlrcpp::Any visitFieldWidth(pascalParser::FieldWidthContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #72
    virtual antlrcpp::Any visitDecimalPlaces(pascalParser::DecimalPlacesContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #73
    virtual antlrcpp::Any visitReadStatement(pascalParser::ReadStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #74
    virtual antlrcpp::Any visitReadlnStatement(pascalParser::ReadlnStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #75
    virtual antlrcpp::Any visitReadArguments(pascalParser::ReadArgumentsContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #76
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
    
    // #77
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
    
    // #78
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
    
    // #79
    virtual antlrcpp::Any visitVariableFactor(pascalParser::VariableFactorContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #80
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
    
    // #81
    virtual antlrcpp::Any visitCharacterFactor(pascalParser::CharacterFactorContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #82
    virtual antlrcpp::Any visitStringFactor(pascalParser::StringFactorContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #83
    virtual antlrcpp::Any visitFunctionCallFactor(pascalParser::FunctionCallFactorContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #84
    virtual antlrcpp::Any visitNotFactor(pascalParser::NotFactorContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #85
    virtual antlrcpp::Any visitParenthesizedFactor(pascalParser::ParenthesizedFactorContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #86
    virtual antlrcpp::Any visitVariable(pascalParser::VariableContext *ctx) override {
        pascalParser::VariableIdentifierContext *varIdCtx = ctx->variableIdentifier();
        visit(varIdCtx);
        ctx->entry = varIdCtx->entry;
        ctx->type = varIdCtx->type; // TODO: Check for modifier

        return nullptr;
    }
    
    // #87
    virtual antlrcpp::Any visitModifier(pascalParser::ModifierContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #88
    virtual antlrcpp::Any visitIndexList(pascalParser::IndexListContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #89
    virtual antlrcpp::Any visitIndex(pascalParser::IndexContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #90
    virtual antlrcpp::Any visitField(pascalParser::FieldContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #91
    virtual antlrcpp::Any visitFunctionCall(pascalParser::FunctionCallContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #92
    virtual antlrcpp::Any visitFunctionName(pascalParser::FunctionNameContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #93
    virtual antlrcpp::Any visitNumber(pascalParser::NumberContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #94
    virtual antlrcpp::Any visitUnsignedNumber(pascalParser::UnsignedNumberContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #95
    virtual antlrcpp::Any visitIntegerConstant(pascalParser::IntegerConstantContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #96
    virtual antlrcpp::Any visitRealConstant(pascalParser::RealConstantContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #97
    virtual antlrcpp::Any visitCharacterConstant(pascalParser::CharacterConstantContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #98
    virtual antlrcpp::Any visitStringConstant(pascalParser::StringConstantContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #99
    virtual antlrcpp::Any visitRelOp(pascalParser::RelOpContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #100
    virtual antlrcpp::Any visitAddOp(pascalParser::AddOpContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #101
    virtual antlrcpp::Any visitMulOp(pascalParser::MulOpContext *ctx) override {
        return visitChildren(ctx);
    }

};

} // namespace frontend