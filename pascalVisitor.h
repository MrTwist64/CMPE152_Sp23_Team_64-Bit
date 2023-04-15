
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from pascal.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "pascalParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by pascalParser.
 */
class  pascalVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by pascalParser.
   */
    virtual std::any visitProgram(pascalParser::ProgramContext *context) = 0;

    virtual std::any visitProgramHeader(pascalParser::ProgramHeaderContext *context) = 0;

    virtual std::any visitProgramParameters(pascalParser::ProgramParametersContext *context) = 0;

    virtual std::any visitProgramIdentifier(pascalParser::ProgramIdentifierContext *context) = 0;

    virtual std::any visitBlock(pascalParser::BlockContext *context) = 0;

    virtual std::any visitDeclarations(pascalParser::DeclarationsContext *context) = 0;

    virtual std::any visitConstantsPart(pascalParser::ConstantsPartContext *context) = 0;

    virtual std::any visitConstantDefinitionsList(pascalParser::ConstantDefinitionsListContext *context) = 0;

    virtual std::any visitConstantDefinition(pascalParser::ConstantDefinitionContext *context) = 0;

    virtual std::any visitConstantIdentifier(pascalParser::ConstantIdentifierContext *context) = 0;

    virtual std::any visitConstant(pascalParser::ConstantContext *context) = 0;

    virtual std::any visitSign(pascalParser::SignContext *context) = 0;

    virtual std::any visitTypesPart(pascalParser::TypesPartContext *context) = 0;

    virtual std::any visitTypeDefinitionsList(pascalParser::TypeDefinitionsListContext *context) = 0;

    virtual std::any visitTypeDefinition(pascalParser::TypeDefinitionContext *context) = 0;

    virtual std::any visitTypeIdentifier(pascalParser::TypeIdentifierContext *context) = 0;

    virtual std::any visitSimpleTypespec(pascalParser::SimpleTypespecContext *context) = 0;

    virtual std::any visitArrayTypespec(pascalParser::ArrayTypespecContext *context) = 0;

    virtual std::any visitRecordTypespec(pascalParser::RecordTypespecContext *context) = 0;

    virtual std::any visitTypeIdentifierTypespec(pascalParser::TypeIdentifierTypespecContext *context) = 0;

    virtual std::any visitEnumerationTypespec(pascalParser::EnumerationTypespecContext *context) = 0;

    virtual std::any visitSubrangeTypespec(pascalParser::SubrangeTypespecContext *context) = 0;

    virtual std::any visitEnumerationType(pascalParser::EnumerationTypeContext *context) = 0;

    virtual std::any visitEnumerationConstant(pascalParser::EnumerationConstantContext *context) = 0;

    virtual std::any visitSubrangeType(pascalParser::SubrangeTypeContext *context) = 0;

    virtual std::any visitArrayType(pascalParser::ArrayTypeContext *context) = 0;

    virtual std::any visitArrayDimensionList(pascalParser::ArrayDimensionListContext *context) = 0;

    virtual std::any visitRecordType(pascalParser::RecordTypeContext *context) = 0;

    virtual std::any visitRecordFields(pascalParser::RecordFieldsContext *context) = 0;

    virtual std::any visitVariablesPart(pascalParser::VariablesPartContext *context) = 0;

    virtual std::any visitVariableDeclarationsList(pascalParser::VariableDeclarationsListContext *context) = 0;

    virtual std::any visitVariableDeclarations(pascalParser::VariableDeclarationsContext *context) = 0;

    virtual std::any visitVariableIdentifierList(pascalParser::VariableIdentifierListContext *context) = 0;

    virtual std::any visitVariableIdentifier(pascalParser::VariableIdentifierContext *context) = 0;

    virtual std::any visitRoutinesPart(pascalParser::RoutinesPartContext *context) = 0;

    virtual std::any visitRoutineDefinition(pascalParser::RoutineDefinitionContext *context) = 0;

    virtual std::any visitProcedureHead(pascalParser::ProcedureHeadContext *context) = 0;

    virtual std::any visitFunctionHead(pascalParser::FunctionHeadContext *context) = 0;

    virtual std::any visitRoutineIdentifier(pascalParser::RoutineIdentifierContext *context) = 0;

    virtual std::any visitParameters(pascalParser::ParametersContext *context) = 0;

    virtual std::any visitParameterDeclarationsList(pascalParser::ParameterDeclarationsListContext *context) = 0;

    virtual std::any visitParameterDeclarations(pascalParser::ParameterDeclarationsContext *context) = 0;

    virtual std::any visitParameterIdentifierList(pascalParser::ParameterIdentifierListContext *context) = 0;

    virtual std::any visitParameterIdentifier(pascalParser::ParameterIdentifierContext *context) = 0;

    virtual std::any visitStatement(pascalParser::StatementContext *context) = 0;

    virtual std::any visitCompoundStatement(pascalParser::CompoundStatementContext *context) = 0;

    virtual std::any visitEmptyStatement(pascalParser::EmptyStatementContext *context) = 0;

    virtual std::any visitStatementList(pascalParser::StatementListContext *context) = 0;

    virtual std::any visitAssignmentStatement(pascalParser::AssignmentStatementContext *context) = 0;

    virtual std::any visitLhs(pascalParser::LhsContext *context) = 0;

    virtual std::any visitRhs(pascalParser::RhsContext *context) = 0;

    virtual std::any visitIfStatement(pascalParser::IfStatementContext *context) = 0;

    virtual std::any visitTrueStatement(pascalParser::TrueStatementContext *context) = 0;

    virtual std::any visitFalseStatement(pascalParser::FalseStatementContext *context) = 0;

    virtual std::any visitCaseStatement(pascalParser::CaseStatementContext *context) = 0;

    virtual std::any visitCaseBranchList(pascalParser::CaseBranchListContext *context) = 0;

    virtual std::any visitCaseBranch(pascalParser::CaseBranchContext *context) = 0;

    virtual std::any visitCaseConstantList(pascalParser::CaseConstantListContext *context) = 0;

    virtual std::any visitCaseConstant(pascalParser::CaseConstantContext *context) = 0;

    virtual std::any visitRepeatStatement(pascalParser::RepeatStatementContext *context) = 0;

    virtual std::any visitWhileStatement(pascalParser::WhileStatementContext *context) = 0;

    virtual std::any visitForStatement(pascalParser::ForStatementContext *context) = 0;

    virtual std::any visitProcedureCallStatement(pascalParser::ProcedureCallStatementContext *context) = 0;

    virtual std::any visitProcedureName(pascalParser::ProcedureNameContext *context) = 0;

    virtual std::any visitArgumentList(pascalParser::ArgumentListContext *context) = 0;

    virtual std::any visitArgument(pascalParser::ArgumentContext *context) = 0;

    virtual std::any visitWriteStatement(pascalParser::WriteStatementContext *context) = 0;

    virtual std::any visitWritelnStatement(pascalParser::WritelnStatementContext *context) = 0;

    virtual std::any visitWriteArguments(pascalParser::WriteArgumentsContext *context) = 0;

    virtual std::any visitWriteArgument(pascalParser::WriteArgumentContext *context) = 0;

    virtual std::any visitFieldWidth(pascalParser::FieldWidthContext *context) = 0;

    virtual std::any visitDecimalPlaces(pascalParser::DecimalPlacesContext *context) = 0;

    virtual std::any visitReadStatement(pascalParser::ReadStatementContext *context) = 0;

    virtual std::any visitReadlnStatement(pascalParser::ReadlnStatementContext *context) = 0;

    virtual std::any visitReadArguments(pascalParser::ReadArgumentsContext *context) = 0;

    virtual std::any visitExpression(pascalParser::ExpressionContext *context) = 0;

    virtual std::any visitSimpleExpression(pascalParser::SimpleExpressionContext *context) = 0;

    virtual std::any visitTerm(pascalParser::TermContext *context) = 0;

    virtual std::any visitVariableFactor(pascalParser::VariableFactorContext *context) = 0;

    virtual std::any visitNumberFactor(pascalParser::NumberFactorContext *context) = 0;

    virtual std::any visitCharacterFactor(pascalParser::CharacterFactorContext *context) = 0;

    virtual std::any visitStringFactor(pascalParser::StringFactorContext *context) = 0;

    virtual std::any visitFunctionCallFactor(pascalParser::FunctionCallFactorContext *context) = 0;

    virtual std::any visitNotFactor(pascalParser::NotFactorContext *context) = 0;

    virtual std::any visitParenthesizedFactor(pascalParser::ParenthesizedFactorContext *context) = 0;

    virtual std::any visitVariable(pascalParser::VariableContext *context) = 0;

    virtual std::any visitModifier(pascalParser::ModifierContext *context) = 0;

    virtual std::any visitIndexList(pascalParser::IndexListContext *context) = 0;

    virtual std::any visitIndex(pascalParser::IndexContext *context) = 0;

    virtual std::any visitField(pascalParser::FieldContext *context) = 0;

    virtual std::any visitFunctionCall(pascalParser::FunctionCallContext *context) = 0;

    virtual std::any visitFunctionName(pascalParser::FunctionNameContext *context) = 0;

    virtual std::any visitNumber(pascalParser::NumberContext *context) = 0;

    virtual std::any visitUnsignedNumber(pascalParser::UnsignedNumberContext *context) = 0;

    virtual std::any visitIntegerConstant(pascalParser::IntegerConstantContext *context) = 0;

    virtual std::any visitRealConstant(pascalParser::RealConstantContext *context) = 0;

    virtual std::any visitCharacterConstant(pascalParser::CharacterConstantContext *context) = 0;

    virtual std::any visitStringConstant(pascalParser::StringConstantContext *context) = 0;

    virtual std::any visitRelOp(pascalParser::RelOpContext *context) = 0;

    virtual std::any visitAddOp(pascalParser::AddOpContext *context) = 0;

    virtual std::any visitMulOp(pascalParser::MulOpContext *context) = 0;


};

