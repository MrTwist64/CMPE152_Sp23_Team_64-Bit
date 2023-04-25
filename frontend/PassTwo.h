#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

#include "../intermediate/symtab/SymtabStack.h"
#include "../intermediate/symtab/Predefined.h"
#include "../intermediate/type/TypeChecker.h"
#include "../intermediate/type/ErrStr.h"
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
    ErrStr* err;

    string lower(string data)
    {
        transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
        return data;
    }
 
public:
    PassTwo(Predefined *pred)
    {
        this->pred = pred;
        stack = new SymtabStack;
        this->pred->initialize(stack);
        typeChecker = new TypeChecker(pred);
        err = new ErrStr;
    }

    SymtabStack* getStack() {return stack;}
    
    // #1
    virtual antlrcpp::Any visitProgram(pascalParser::ProgramContext *ctx) override 
    {
        visit(ctx->programHeader());
        visit(ctx->block());

        stack->pop();

        return nullptr;
    }
    
    // #2
    virtual antlrcpp::Any visitProgramHeader(pascalParser::ProgramHeaderContext *ctx) override 
    {
        pascalParser::ProgramIdentifierContext *proIdCtx = ctx->programIdentifier();
        proIdCtx->entry = stack->enterLocal(lower(proIdCtx->IDENTIFIER()->getText()), Kind::PROGRAM);

        Symtab* newTable = stack->push();
        newTable->setOwner(proIdCtx->entry);
        proIdCtx->entry->setChild(newTable);

        visit(ctx->programParameters());

        return nullptr;
    }
    
    // #3
    // I think the only parameters passed in are a list of files. Given that, I don't think we need it.
    // virtual antlrcpp::Any visitProgramParameters(pascalParser::ProgramParametersContext *ctx) override 
    // {
    //     return visitChildren(ctx);
    // }
    
    // #4
    // Skipped by #2 visitProgramHeader().
    // virtual antlrcpp::Any visitProgramIdentifier(pascalParser::ProgramIdentifierContext *ctx) override {
    //     return visitChildren(ctx);
    // }
    
    // #5
    // virtual antlrcpp::Any visitBlock(pascalParser::BlockContext *ctx) override
    // {
    //     return visitChildren(ctx);
    // }
    
    // #6
    virtual antlrcpp::Any visitDeclarations(pascalParser::DeclarationsContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #7
    virtual antlrcpp::Any visitConstantsPart(pascalParser::ConstantsPartContext *ctx) override 
    {
        return visitChildren(ctx);
    }
    
    // #8
    virtual antlrcpp::Any visitConstantDefinitionsList(pascalParser::ConstantDefinitionsListContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #9
    virtual antlrcpp::Any visitConstantDefinition(pascalParser::ConstantDefinitionContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #10
    virtual antlrcpp::Any visitConstantIdentifier(pascalParser::ConstantIdentifierContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #11
    virtual antlrcpp::Any visitConstant(pascalParser::ConstantContext *ctx) override
    {
        visitChildren(ctx);
        
        if (ctx->IDENTIFIER() != nullptr)
        {
            SymtabEntry *constId = stack->lookup(lower(ctx->IDENTIFIER()->getText()));

            // Check if identifier exists
            if (constId == nullptr)
            {
                cout << err->constantNotFound(ctx->IDENTIFIER()->getText(), ctx->getStart()->getLine()) << endl;
                ctx->type = pred->integerType;
                ctx->value = 0;
                return nullptr;
            }

            // Check if identifier is constant
            Kind constKind = constId->getKind();
            if (constKind != Kind::CONSTANT && constKind != Kind::ENUMERATION_CONSTANT)
            {
                cout << err->kindNotCorrect(KIND_STRINGS[int(constKind)], "CONSTANT or ENUMERATION_CONSTANT", ctx->getStart()->getLine()) << endl;
                return nullptr;
            }
            
            // Copy type and value
            ctx->type = constId->getType();
            ctx->value = constId->getValue();
        }
        else if (ctx->unsignedNumber() != nullptr)
        {
            pascalParser::UnsignedNumberContext *unsNumCtx = ctx->unsignedNumber();
            if(unsNumCtx->integerConstant() != nullptr)
            {
                ctx->type = pred->integerType;
                ctx->value = stoi(unsNumCtx->integerConstant()->INTEGER()->getText());
            }
            else 
            {
                ctx->type = pred->realType;
                ctx->value = stod(unsNumCtx->realConstant()->REAL()->getText());
            }
        }
        else if (ctx->characterConstant() != nullptr)
        {
            ctx->type = pred->charType;
            ctx->value = ctx->IDENTIFIER()->getText()[1];
        }
        else // (ctx->stringConstant() != nullptr)
        {
            string pString = ctx->stringConstant()->STRING()->getText();
            string subString = pString.substr(1, pString.length()-2);
            ctx->type = pred->stringType;
            ctx->value = new string(subString);
        }
        
        return nullptr;
    }
    
    // #12
    // virtual antlrcpp::Any visitSign(pascalParser::SignContext *ctx) override
    // {
        
    //     return visitChildren(ctx);
    // }
    
    // #13
    // virtual antlrcpp::Any visitTypesPart(pascalParser::TypesPartContext *ctx) override
    // {
    //     return visitChildren(ctx);
    // }
    
    // #14
    // virtual antlrcpp::Any visitTypeDefinitionsList(pascalParser::TypeDefinitionsListContext *ctx) override
    // {
    //     return visitChildren(ctx);
    // }
    
    // #15
    virtual antlrcpp::Any visitTypeDefinition(pascalParser::TypeDefinitionContext *ctx) override
    {
        pascalParser::TypeIdentifierContext *idCtx = ctx->typeIdentifier();
        string name = toLowerCase(idCtx->IDENTIFIER()->getText());
        SymtabEntry *ID = stack->lookup(name);
        pascalParser::TypeSpecificationContext *typeCtx = ctx->typeSpecification();
        visit(typeCtx);
        
        if (ID == nullptr)
        {
            ID = stack->enterLocal(name, TYPE);
            ID->setType(typeCtx->type);
            typeCtx->type->setIdentifier(ID);
        }
        else // Error
            cout << err->duplicateTypeDef(name, ctx->getStart()->getLine());

        idCtx->entry = ID;
        idCtx->type = typeCtx->type;

        return nullptr;
    }
    
    // #16
    virtual antlrcpp::Any visitTypeIdentifier(pascalParser::TypeIdentifierContext *ctx) override
    {
        ctx->entry = stack->lookup(lower(ctx->IDENTIFIER()->getText()));
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
        visitChildren(ctx);
        Typespec *arrayType = new Typespec(ARRAY);
        pascalParser::ArrayTypeContext *arrayCtx = ctx->arrayType();
        pascalParser::ArrayDimensionListContext *listCtx = arrayCtx->arrayDimensionList();

        ctx->type = arrayType;

        pascalParser::SimpleTypeContext *simpleCtx;
        int subcount;
        Typespec *newType;

        int count = listCtx->simpleType().size();
        for (int i = 0; i < count; i++)
        {
            simpleCtx = listCtx->simpleType()[i];
            arrayType->setArrIndexType(simpleCtx->type);
            subcount = simpleCtx->type->getSubrMax() - simpleCtx->type->getSubrMin() + 1;
            arrayType->setArrLength(subcount);

            if (i < count - 1)
            {
                newType = new Typespec(ARRAY);
                arrayType->setArrElemType(newType);
                arrayType = newType;
            }
        }

        arrayType->setArrElemType(arrayCtx->typeSpecification()->type);

        return nullptr;
    }
    
    // #19
    // virtual antlrcpp::Any visitRecordTypespec(pascalParser::RecordTypespecContext *ctx) override
    // {
    //     return visitChildren(ctx);
    // }
    
    // #20
    virtual antlrcpp::Any visitTypeIdentifierTypespec(pascalParser::TypeIdentifierTypespecContext *ctx) override
    {
        visit(ctx->typeIdentifier());
        ctx->type = ctx->typeIdentifier()->type;
        return nullptr;
    }
    
    // #21
    virtual antlrcpp::Any visitEnumerationTypespec(pascalParser::EnumerationTypespecContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #22
    virtual antlrcpp::Any visitSubrangeTypespec(pascalParser::SubrangeTypespecContext *ctx) override
    {
        visitChildren(ctx);
        ctx->type = new Typespec(SUBRANGE);

        int minVal;
        int maxVal;
        Typespec *minType = ctx->subrangeType()->constant()[0]->type;
        Typespec *maxType = ctx->subrangeType()->constant()[1]->type;

        // Check for correct form
        if (   (   (minType->getForm() != Form::SCALAR)
    		       && (minType->getForm() != Form::ENUMERATION))
               || (minType == pred->realType)
               || (minType == pred->stringType))
        {
            cout << err->typeNotCorrect(ctx->getStart()->getLine()) << endl;
            minType = pred->integerType;
            minVal = 0; // May get overwritten
        }

        // Cast values
        if (minType == pred->integerType)
        {
            minVal = int(ctx->subrangeType()->constant()[0]->value);
            maxVal = int(ctx->subrangeType()->constant()[1]->value);
        }
        else // (minType == pred->charType)
        {
            minVal = char(ctx->subrangeType()->constant()[0]->value);
            maxVal = char(ctx->subrangeType()->constant()[1]->value);
        }

        // Check for identical types or correctly ordered values
        if ((maxType != minType) || (minVal > maxVal))
        {
            cout << err->typeNotCorrect(ctx->getStart()->getLine()) << endl;
            maxType = minType;
        }

        ctx->type->setSubrBaseType(minType);
        ctx->type->setSubrMin(minVal);
        ctx->type->setSubrMax(maxVal);

        return nullptr;
    }
    
    // #23
    virtual antlrcpp::Any visitEnumerationType(pascalParser::EnumerationTypeContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #24
    virtual antlrcpp::Any visitEnumerationConstant(pascalParser::EnumerationConstantContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #25
    virtual antlrcpp::Any visitSubrangeType(pascalParser::SubrangeTypeContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #26
    virtual antlrcpp::Any visitArrayType(pascalParser::ArrayTypeContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #27
    virtual antlrcpp::Any visitArrayDimensionList(pascalParser::ArrayDimensionListContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #28
    virtual antlrcpp::Any visitRecordType(pascalParser::RecordTypeContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #29
    virtual antlrcpp::Any visitRecordFields(pascalParser::RecordFieldsContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #30
    virtual antlrcpp::Any visitVariablesPart(pascalParser::VariablesPartContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #31
    virtual antlrcpp::Any visitVariableDeclarationsList(pascalParser::VariableDeclarationsListContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #32
    virtual antlrcpp::Any visitVariableDeclarations(pascalParser::VariableDeclarationsContext *ctx) override 
    {
        pascalParser::TypeSpecificationContext *typespecCtx = ctx->typeSpecification();
        visit(typespecCtx);

        // Gives a list of contexts that must individually be parsed through.
        pascalParser::VariableIdentifierListContext *varIdListCtx = ctx->variableIdentifierList();
        
        for(pascalParser::VariableIdentifierContext *idCtx : varIdListCtx->variableIdentifier()) {
            idCtx->type = typespecCtx->type;
            idCtx->entry = stack->enterLocal(idCtx->IDENTIFIER()->getText(), Kind::VARIABLE);
            idCtx->entry->setType(idCtx->type);
        }

        return nullptr;
    }
    
    // #33
    virtual antlrcpp::Any visitVariableIdentifierList(pascalParser::VariableIdentifierListContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #34
    virtual antlrcpp::Any visitVariableIdentifier(pascalParser::VariableIdentifierContext *ctx) override
    {
        ctx->entry = stack->lookup(ctx->IDENTIFIER()->getText());

        if (ctx->entry == nullptr)
        {
            cout << err->variableNotFound(ctx->IDENTIFIER()->getText(), ctx->getStart()->getLine()) << endl;
            return nullptr;
        }

        ctx->type = ctx->entry->getType();

        return nullptr;
    }
    
    // #35
    virtual antlrcpp::Any visitRoutinesPart(pascalParser::RoutinesPartContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #36
    virtual antlrcpp::Any visitRoutineDefinition(pascalParser::RoutineDefinitionContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #37
    virtual antlrcpp::Any visitProcedureHead(pascalParser::ProcedureHeadContext *ctx) override {
        return visitChildren(ctx);
    }
    
    // #38
    virtual antlrcpp::Any visitFunctionHead(pascalParser::FunctionHeadContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #39
    virtual antlrcpp::Any visitRoutineIdentifier(pascalParser::RoutineIdentifierContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #40
    virtual antlrcpp::Any visitParameters(pascalParser::ParametersContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #41
    virtual antlrcpp::Any visitParameterDeclarationsList(pascalParser::ParameterDeclarationsListContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #42
    virtual antlrcpp::Any visitParameterDeclarations(pascalParser::ParameterDeclarationsContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #43
    virtual antlrcpp::Any visitParameterIdentifierList(pascalParser::ParameterIdentifierListContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #44
    virtual antlrcpp::Any visitParameterIdentifier(pascalParser::ParameterIdentifierContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #45
    virtual antlrcpp::Any visitStatement(pascalParser::StatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #46
    virtual antlrcpp::Any visitCompoundStatement(pascalParser::CompoundStatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #47
    virtual antlrcpp::Any visitEmptyStatement(pascalParser::EmptyStatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #48
    virtual antlrcpp::Any visitStatementList(pascalParser::StatementListContext *ctx) override
    {
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
        
        if (lhsType == nullptr || rhsType == nullptr)
            return nullptr;

        if (!typeChecker->areAssignmentCompatible(lhsType, rhsType))
            cout << err->incompatibleAssignment(lhsType, rhsType, ctx->getStart()->getLine()) << endl;
        
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
    // Skipped by #49 visitAssignmentStatement().
    // virtual antlrcpp::Any visitRhs(pascalParser::RhsContext *ctx) override {
    //     return visitChildren(ctx);
    // }
    
    // #52
    virtual antlrcpp::Any visitIfStatement(pascalParser::IfStatementContext *ctx) override
    {
        visitChildren(ctx);
        if (!typeChecker->isBoolean(ctx->expression()->type))
            cout << err->typeNotCorrect(ctx->expression()->type, "boolean", ctx->getStart()->getLine()) << endl;

        return nullptr;
    }
    
    // #53
    virtual antlrcpp::Any visitTrueStatement(pascalParser::TrueStatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #54
    virtual antlrcpp::Any visitFalseStatement(pascalParser::FalseStatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #55
    virtual antlrcpp::Any visitCaseStatement(pascalParser::CaseStatementContext *ctx) override
    {
        visitChildren(ctx);
        
        pascalParser::ExpressionContext *exprCtx = ctx->expression();
        Typespec *exprType = exprCtx->type;
        Form exprTypeForm = exprType->getForm();

        if (  (  (exprTypeForm != Form::SCALAR)
                 && (exprTypeForm != Form::ENUMERATION)
                 && (exprTypeForm != Form::SUBRANGE))
              || (exprType == pred->realType)
              || (exprType == pred->stringType))
            cout << err->typeNotCorrect(ctx->getStart()->getLine()) << endl;

        pascalParser::ConstantContext *constCtx;
        set<int> constants;

        for (pascalParser::CaseBranchContext *branchCtx : ctx->caseBranchList()->caseBranch())
        {
            if (branchCtx->caseConstantList() != nullptr)
            {
                for (pascalParser::CaseConstantContext *caseConstCtx : branchCtx->caseConstantList()->caseConstant())
                {
                    constCtx = caseConstCtx->constant();
                    caseConstCtx->type = constCtx->type;
                    caseConstCtx->value = 0;
                    
                    // Check for constant type
                    // Has error with variables that causes a segmentation fault.
                    if (constCtx->type != exprType)
                        cout << err->incompatibleCaseConstant(constCtx->type, exprType, ctx->getStart()->getLine()) << endl;
                    else if ((constCtx->type == pred->integerType) || (constCtx->type->getForm() == Form::ENUMERATION))
                        caseConstCtx->value = int(constCtx->value);
                    else if (constCtx->type == pred->charType)
                        caseConstCtx->value = char(constCtx->value);
                    
                    // Check for duplicate constants
                    if (constants.find(caseConstCtx->value) != constants.end())
                        cout << err->duplicateCaseConstant(caseConstCtx->value, ctx->getStart()->getLine());
                    constants.insert(caseConstCtx->value);
                }
            }
        }
        
        return nullptr;
    }
    
    // #56
    virtual antlrcpp::Any visitCaseBranchList(pascalParser::CaseBranchListContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #57
    virtual antlrcpp::Any visitCaseBranch(pascalParser::CaseBranchContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #58
    virtual antlrcpp::Any visitCaseConstantList(pascalParser::CaseConstantListContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #59
    // Skipped by #55 visitCaseStatement?
    virtual antlrcpp::Any visitCaseConstant(pascalParser::CaseConstantContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #60
    virtual antlrcpp::Any visitRepeatStatement(pascalParser::RepeatStatementContext *ctx) override
    {
        visitChildren(ctx);
        if (!typeChecker->isBoolean(ctx->expression()->type))
           cout << err->typeNotCorrect(ctx->expression()->type, "boolean", ctx->getStart()->getLine()) << endl;
                 
        return nullptr;
    }
    
    // #61
    virtual antlrcpp::Any visitWhileStatement(pascalParser::WhileStatementContext *ctx) override
    {
        visitChildren(ctx);
        if (!typeChecker->isBoolean(ctx->expression()->type))
           cout << err->typeNotCorrect(ctx->expression()->type, "boolean", ctx->getStart()->getLine()) << endl;
                 
        return nullptr;
    }
    
    // #62
    virtual antlrcpp::Any visitForStatement(pascalParser::ForStatementContext *ctx) override
    {
        visitChildren(ctx);
        if(ctx->variable()->entry != nullptr)
        {
            if((ctx->variable()->type->getForm() != SCALAR)
                || (ctx->variable()->type == pred->realType)
                || (ctx->variable()->type == pred->stringType))
                {
                cout << err->typeNotCorrect(ctx->variable()->type,"integer", ctx->getStart()->getLine()) << endl;
            }
        }
        else
        {
            cout << err->variableNotFound(ctx->variable()->getText(), ctx->getStart()->getLine()) << endl;
        }

        if(ctx->expression()[0]->type != ctx->variable()->type)
            cout << err->incompatibleAssignment(ctx->expression()[0]->type, ctx->variable()->type, ctx->getStart()->getLine()) <<endl;
        if(ctx->expression()[0]->type != ctx->expression()[1]->type)
            cout << err->incompatibleAssignment(ctx->expression()[0]->type, ctx->expression()[1]->type, ctx->getStart()->getLine()) <<endl;
        

        return nullptr;
    }
    
    // #63
    virtual antlrcpp::Any visitProcedureCallStatement(pascalParser::ProcedureCallStatementContext *ctx) override
    {
        visitChildren(ctx);
        bool badName = false;
        string name = toLowerCase(ctx->procedureName()->getText());
        SymtabEntry* procedureID = stack->lookup(name);
        pascalParser::ProcedureNameContext* nameCtx = ctx->procedureName();
        pascalParser::ArgumentListContext* listCtx = ctx->argumentList();

        if(procedureID == nullptr)
        {
            cout << err->variableNotFound(ctx->procedureName()->getText(), ctx->getStart()->getLine());
            badName = true;
        }
        else if (procedureID->getKind() != PROCEDURE)
        {
            cout << err->kindNotCorrect(ctx->procedureName()->getText(), "procedure", ctx->getStart()->getLine());
            badName = true;
            
        }

        //Bad Name
        if(badName)
        {
            for (pascalParser::ArgumentContext* exprCtx : listCtx->argument())
            {
                visit(exprCtx);
            }
        }

        //Good Name
        // Commented to allow for tests -Aaron
        // else
        // {
        //     checkCallArguments(listCtx,stack);
            
        // }

        return nullptr;

    }
    
    // #64
    virtual antlrcpp::Any visitProcedureName(pascalParser::ProcedureNameContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #65
    virtual antlrcpp::Any visitArgumentList(pascalParser::ArgumentListContext *ctx) override
    {
        
        return visitChildren(ctx);
    }
    
    // #66
    virtual antlrcpp::Any visitArgument(pascalParser::ArgumentContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #67
    virtual antlrcpp::Any visitWriteStatement(pascalParser::WriteStatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #68
    virtual antlrcpp::Any visitWritelnStatement(pascalParser::WritelnStatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #69
    virtual antlrcpp::Any visitWriteArguments(pascalParser::WriteArgumentsContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #70
    virtual antlrcpp::Any visitWriteArgument(pascalParser::WriteArgumentContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #71
    virtual antlrcpp::Any visitFieldWidth(pascalParser::FieldWidthContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #72
    virtual antlrcpp::Any visitDecimalPlaces(pascalParser::DecimalPlacesContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #73
    virtual antlrcpp::Any visitReadStatement(pascalParser::ReadStatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #74
    virtual antlrcpp::Any visitReadlnStatement(pascalParser::ReadlnStatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #75
    virtual antlrcpp::Any visitReadArguments(pascalParser::ReadArgumentsContext *ctx) override 
    {
        return visitChildren(ctx);
    }
    
    // #76
    virtual antlrcpp::Any visitExpression(pascalParser::ExpressionContext *ctx) override // NOT DONE !!! NEEDS WORK
    {
        // Returns of list of simple expression contexts
        pascalParser::SimpleExpressionContext *simExprCtxLeft = ctx->simpleExpression()[0];
        visit(simExprCtxLeft);

        Typespec *simExprTypeLeft = simExprCtxLeft->type;
        ctx->type = simExprTypeLeft;

        pascalParser::RelOpContext *relopCtx = ctx->relOp();

        if (relopCtx != nullptr)
        {
            pascalParser::SimpleExpressionContext *simExprCtxRight = ctx->simpleExpression()[1];
            visit(simExprCtxRight);

            Typespec *simExprTypeRight = simExprCtxRight->type;
            if (!typeChecker->areComparisonCompatible(simExprTypeLeft, simExprTypeRight))
            {
                cout << err->incompatibleComparison(simExprTypeLeft, simExprTypeRight, ctx->getStart()->getLine()) << endl;
                return nullptr;
            }

            ctx->type = pred->booleanType;
        }

        return nullptr;
    }
    
    // #77
    virtual antlrcpp::Any visitSimpleExpression(pascalParser::SimpleExpressionContext *ctx) override
    {
        pascalParser::SignContext* signCtx = ctx->sign();
        if (signCtx != nullptr)
            string sign = signCtx->getText(); // Do we need this?
        visitChildren(ctx);

        pascalParser::TermContext* termCtx1 = ctx->term()[0];
        Typespec* termType1 = termCtx1->type;
        
        int numTerms = ctx->term().size();
        if (numTerms > 1) 
        {
            Typespec* termType2;
            string addOp;

            for (int i = 0; i + 1 < numTerms; i++)
            {
                termType2 = ctx->term()[i + 1]->type;
                addOp = lower(ctx->addOp()[i]->getText());

                if (addOp == "or")
                {
                    if(!typeChecker->areBothBoolean(termType1, termType2))
                    {
                        if(!typeChecker->isBoolean(termType1))
                            cout << err->typeNotCorrect(termType1, "boolean", ctx->getStart()->getLine()) << endl;
                        if(!typeChecker->isBoolean(termType2))
                            cout << err->typeNotCorrect(termType2, "boolean", ctx->getStart()->getLine()) << endl;
                    }
                    termType2 = pred->booleanType;
                }
                else // (addOp == "+" || addOp == "-")
                {
                    if (typeChecker->areBothInteger(termType1, termType2))
                        termType2 = pred->integerType;
                    else if (typeChecker->isAtLeastOneReal(termType1, termType2))
                        termType2 = pred->realType;
                    else if (typeChecker->areBothString(termType1, termType2) && addOp == "+")
                        termType2 = pred->stringType;
                    else // Error
                    {
                        if (!typeChecker->isIntegerOrReal(termType1))
                            cout << err->typeNotCorrect(termType1, "integer or real", ctx->getStart()->getLine()) << endl;
                        if (!typeChecker->isIntegerOrReal(termType2))
                            cout << err->typeNotCorrect(termType2, "integer or real", ctx->getStart()->getLine()) << endl;
                        termType2 = pred->integerType;
                    }
                }

                termType1 = termType2;
            }
        }

        ctx->type = termType1;
        return nullptr;
    }
    
    // #78
    virtual antlrcpp::Any visitTerm(pascalParser::TermContext *ctx) override
    {
        visitChildren(ctx);

        pascalParser::FactorContext* termCtx1 = ctx->factor()[0];
        Typespec* termType1 = termCtx1->type;
        
        int numFactors = ctx->factor().size();
        if (numFactors > 1)
        {
            Typespec* termType2;
            string mulOp;

            for (int i = 0; i + 1 < numFactors; i++)
            {
                termType2 = ctx->factor()[i + 1]->type;
                mulOp = lower(ctx->mulOp()[i]->getText());

                if (mulOp == "*")
                {
                    if (typeChecker->areBothInteger(termType1, termType2))
                        termType2 = pred->integerType;
                    else if (typeChecker->isAtLeastOneReal(termType1, termType2))
                        termType2 = pred->realType;
                    else // Error
                    {
                        if (!typeChecker->isIntegerOrReal(termType1))
                            cout << err->typeNotCorrect(termType1, "integer or real", ctx->getStart()->getLine()) << endl;
                        if (!typeChecker->isIntegerOrReal(termType2))
                            cout << err->typeNotCorrect(termType2, "integer or real", ctx->getStart()->getLine()) << endl;
                        termType2 = pred->integerType;
                    }
                }
                else if (mulOp == "/")
                {
                    if (typeChecker->areBothInteger(termType1, termType2))
                        termType2 = pred->realType;
                    else if (typeChecker->isAtLeastOneReal(termType1, termType2))
                        termType2 = pred->realType;
                    else // Error
                    {
                        if (!typeChecker->isIntegerOrReal(termType1))
                            cout << err->typeNotCorrect(termType1, "integer or real", ctx->getStart()->getLine()) << endl;
                        if (!typeChecker->isIntegerOrReal(termType2))
                            cout << err->typeNotCorrect(termType2, "integer or real", ctx->getStart()->getLine()) << endl;
                        termType2 = pred->integerType;
                    }
                }
                else if (mulOp == "div" || mulOp == "mod")
                {
                    if (!typeChecker->isIntegerOrReal(termType1))
                        cout << err->typeNotCorrect(termType1, "integer or real", ctx->getStart()->getLine()) << endl;
                    if (!typeChecker->isIntegerOrReal(termType2))
                        cout << err->typeNotCorrect(termType2, "integer or real", ctx->getStart()->getLine()) << endl;
                    termType2 = pred->integerType;
                }
                else // mulOp == "and"
                {
                    if(!typeChecker->areBothBoolean(termType1, termType2))
                    {
                        if(!typeChecker->isBoolean(termType1))
                            cout << err->typeNotCorrect(termType1, "boolean", ctx->getStart()->getLine()) << endl;
                        if(!typeChecker->isBoolean(termType2))
                            cout << err->typeNotCorrect(termType2, "boolean", ctx->getStart()->getLine()) << endl;
                    }
                    termType2 = pred->booleanType;
                }

                termType1 = termType2;
            }
        }

        ctx->type = termType1;
        return nullptr;
    }
    
    // #79
    virtual antlrcpp::Any visitVariableFactor(pascalParser::VariableFactorContext *ctx) override
    {
        visitChildren(ctx);
        ctx->type = ctx->variable()->type;
        return nullptr;
    }
    
    // #80
    virtual antlrcpp::Any visitNumberFactor(pascalParser::NumberFactorContext *ctx) override
    {
        pascalParser::SignContext* signCtx = ctx->number()->sign();
        if (signCtx != nullptr)
            string sign = signCtx->getText();
        
        pascalParser::UnsignedNumberContext* unsignNumCtx = ctx->number()->unsignedNumber();
        if (unsignNumCtx->integerConstant() == nullptr)
            ctx->type = pred->realType;
        else
            ctx->type = pred->integerType;

        return nullptr;
    }
    
    // #81
    virtual antlrcpp::Any visitCharacterFactor(pascalParser::CharacterFactorContext *ctx) override
    {
        ctx->type = pred->charType;
        return nullptr;
    }
    
    // #82
    virtual antlrcpp::Any visitStringFactor(pascalParser::StringFactorContext *ctx) override
    {
        ctx->type = pred->stringType;
        return visitChildren(ctx);
    }
    
    // #83
    virtual antlrcpp::Any visitFunctionCallFactor(pascalParser::FunctionCallFactorContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #84
    virtual antlrcpp::Any visitNotFactor(pascalParser::NotFactorContext *ctx) override
    {
        visitChildren(ctx);
        if (ctx->factor()->type != ctx->type)
            cout << err->typeNotCorrect(ctx->factor()->type, "boolean", ctx->getStart()->getLine()) << endl;
        ctx->type = pred->booleanType;
        return nullptr;
    }
    
    // #85
    virtual antlrcpp::Any visitParenthesizedFactor(pascalParser::ParenthesizedFactorContext *ctx) override
    {
        visitChildren(ctx);
        ctx->type = ctx->expression()->type;
        return nullptr;
    }
    
    // #86
    // NOT DONE: NEEDS MODIFIER FUNCTIONALITY ADDED
    virtual antlrcpp::Any visitVariable(pascalParser::VariableContext *ctx) override
    {
        pascalParser::VariableIdentifierContext *varIdCtx = ctx->variableIdentifier();
        visit(varIdCtx);
        ctx->entry = varIdCtx->entry;
        ctx->type = varIdCtx->type; // TODO: Check for modifier

        return nullptr;
    }
    
    // #87
    virtual antlrcpp::Any visitModifier(pascalParser::ModifierContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #88
    virtual antlrcpp::Any visitIndexList(pascalParser::IndexListContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #89
    virtual antlrcpp::Any visitIndex(pascalParser::IndexContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #90
    virtual antlrcpp::Any visitField(pascalParser::FieldContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #91
    virtual antlrcpp::Any visitFunctionCall(pascalParser::FunctionCallContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #92
    virtual antlrcpp::Any visitFunctionName(pascalParser::FunctionNameContext *ctx) override 
    {
        return visitChildren(ctx);
    }
    
    // #93
    virtual antlrcpp::Any visitNumber(pascalParser::NumberContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #94
    virtual antlrcpp::Any visitUnsignedNumber(pascalParser::UnsignedNumberContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #95
    virtual antlrcpp::Any visitIntegerConstant(pascalParser::IntegerConstantContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #96
    virtual antlrcpp::Any visitRealConstant(pascalParser::RealConstantContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #97
    virtual antlrcpp::Any visitCharacterConstant(pascalParser::CharacterConstantContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #98
    virtual antlrcpp::Any visitStringConstant(pascalParser::StringConstantContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #99
    virtual antlrcpp::Any visitRelOp(pascalParser::RelOpContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #100
    virtual antlrcpp::Any visitAddOp(pascalParser::AddOpContext *ctx) override
    {
        return visitChildren(ctx);
    }
    
    // #101
    virtual antlrcpp::Any visitMulOp(pascalParser::MulOpContext *ctx) override
    {
        return visitChildren(ctx);
    }

    // #102
    void checkCallArguments(pascalParser::ArgumentListContext *listCtx, vector<SymtabEntry *> *params)
    {
        int argsCount = listCtx != nullptr ? listCtx->argument().size() : 0;
        
        if (params->size() != argsCount)
        {
            err->countNotEqual(listCtx->getStart()->getLine());
            return;
        }

        for (int i = 0; i < params->size(); i++)
        {
            pascalParser::ArgumentContext *argCtx = listCtx->argument()[i];
            pascalParser::ExpressionContext *exprCtx = argCtx->expression();
            visit(exprCtx);

            SymtabEntry *paramId = (*params)[i];
            Typespec *paramType = paramId->getType();
            Typespec *argType = exprCtx->type;

            if (paramId->getKind() == REFERENCE_PARAMETER)
            {
                if(expressionIsVariable(exprCtx))
                {
                    if(paramType != argType)
                        cout << err->typeNotCorrect(exprCtx->getStart()->getLine()) << endl;
                }
                else
                {
                    cout << err->typeNotCorrect(exprCtx->type,"variable", exprCtx->getStart()->getLine()) << endl;
                }
            }
            else if(!typeChecker->areAssignmentCompatible(paramType, argType))
            {
                cout << err->typeNotCorrect(exprCtx->getStart()->getLine()) << endl;
            }

        }
        


        return ;
    }

    // #103
    bool expressionIsVariable(pascalParser::ExpressionContext *exprCtx)
    {
        if (exprCtx->simpleExpression().size() == 1)
        {
            pascalParser::SimpleExpressionContext *simpleCtx = exprCtx->simpleExpression()[0];

            if (simpleCtx->term().size() == 1)
            {
                pascalParser::TermContext *termCtx = simpleCtx->term()[0];

                if (termCtx->factor().size() == 1)
                {
                    return dynamic_cast<pascalParser::VariableFactorContext *>(termCtx->factor()[0]) != nullptr;
                }
            }
        }
        return false;
    }


};

} // namespace frontend