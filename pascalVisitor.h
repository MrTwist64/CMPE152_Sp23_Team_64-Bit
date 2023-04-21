
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from pascal.g4 by ANTLR 4.7.2

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
    virtual antlrcpp::Any visitProgram(pascalParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgramHeader(pascalParser::ProgramHeaderContext *context) = 0;

    virtual antlrcpp::Any visitProgramParameters(pascalParser::ProgramParametersContext *context) = 0;

    virtual antlrcpp::Any visitProgramIdentifier(pascalParser::ProgramIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitBlock(pascalParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(pascalParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitConstantsPart(pascalParser::ConstantsPartContext *context) = 0;

    virtual antlrcpp::Any visitConstantDefinitionsList(pascalParser::ConstantDefinitionsListContext *context) = 0;

    virtual antlrcpp::Any visitConstantDefinition(pascalParser::ConstantDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitConstantIdentifier(pascalParser::ConstantIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitConstant(pascalParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitSign(pascalParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitTypesPart(pascalParser::TypesPartContext *context) = 0;

    virtual antlrcpp::Any visitTypeDefinitionsList(pascalParser::TypeDefinitionsListContext *context) = 0;

    virtual antlrcpp::Any visitTypeDefinition(pascalParser::TypeDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitTypeIdentifier(pascalParser::TypeIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitSimpleTypespec(pascalParser::SimpleTypespecContext *context) = 0;

    virtual antlrcpp::Any visitArrayTypespec(pascalParser::ArrayTypespecContext *context) = 0;

    virtual antlrcpp::Any visitRecordTypespec(pascalParser::RecordTypespecContext *context) = 0;

    virtual antlrcpp::Any visitTypeIdentifierTypespec(pascalParser::TypeIdentifierTypespecContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationTypespec(pascalParser::EnumerationTypespecContext *context) = 0;

    virtual antlrcpp::Any visitSubrangeTypespec(pascalParser::SubrangeTypespecContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationType(pascalParser::EnumerationTypeContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationConstant(pascalParser::EnumerationConstantContext *context) = 0;

    virtual antlrcpp::Any visitSubrangeType(pascalParser::SubrangeTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayType(pascalParser::ArrayTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayDimensionList(pascalParser::ArrayDimensionListContext *context) = 0;

    virtual antlrcpp::Any visitRecordType(pascalParser::RecordTypeContext *context) = 0;

    virtual antlrcpp::Any visitRecordFields(pascalParser::RecordFieldsContext *context) = 0;

    virtual antlrcpp::Any visitVariablesPart(pascalParser::VariablesPartContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationsList(pascalParser::VariableDeclarationsListContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarations(pascalParser::VariableDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVariableIdentifierList(pascalParser::VariableIdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitVariableIdentifier(pascalParser::VariableIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitRoutinesPart(pascalParser::RoutinesPartContext *context) = 0;

    virtual antlrcpp::Any visitRoutineDefinition(pascalParser::RoutineDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitProcedureHead(pascalParser::ProcedureHeadContext *context) = 0;

    virtual antlrcpp::Any visitFunctionHead(pascalParser::FunctionHeadContext *context) = 0;

    virtual antlrcpp::Any visitRoutineIdentifier(pascalParser::RoutineIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitParameters(pascalParser::ParametersContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclarationsList(pascalParser::ParameterDeclarationsListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclarations(pascalParser::ParameterDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitParameterIdentifierList(pascalParser::ParameterIdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitParameterIdentifier(pascalParser::ParameterIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitStatement(pascalParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(pascalParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement(pascalParser::EmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitStatementList(pascalParser::StatementListContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(pascalParser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitLhs(pascalParser::LhsContext *context) = 0;

    virtual antlrcpp::Any visitRhs(pascalParser::RhsContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(pascalParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitTrueStatement(pascalParser::TrueStatementContext *context) = 0;

    virtual antlrcpp::Any visitFalseStatement(pascalParser::FalseStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseStatement(pascalParser::CaseStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseBranchList(pascalParser::CaseBranchListContext *context) = 0;

    virtual antlrcpp::Any visitCaseBranch(pascalParser::CaseBranchContext *context) = 0;

    virtual antlrcpp::Any visitCaseConstantList(pascalParser::CaseConstantListContext *context) = 0;

    virtual antlrcpp::Any visitCaseConstant(pascalParser::CaseConstantContext *context) = 0;

    virtual antlrcpp::Any visitRepeatStatement(pascalParser::RepeatStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(pascalParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(pascalParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitProcedureCallStatement(pascalParser::ProcedureCallStatementContext *context) = 0;

    virtual antlrcpp::Any visitProcedureName(pascalParser::ProcedureNameContext *context) = 0;

    virtual antlrcpp::Any visitArgumentList(pascalParser::ArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitArgument(pascalParser::ArgumentContext *context) = 0;

    virtual antlrcpp::Any visitWriteStatement(pascalParser::WriteStatementContext *context) = 0;

    virtual antlrcpp::Any visitWritelnStatement(pascalParser::WritelnStatementContext *context) = 0;

    virtual antlrcpp::Any visitWriteArguments(pascalParser::WriteArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitWriteArgument(pascalParser::WriteArgumentContext *context) = 0;

    virtual antlrcpp::Any visitFieldWidth(pascalParser::FieldWidthContext *context) = 0;

    virtual antlrcpp::Any visitDecimalPlaces(pascalParser::DecimalPlacesContext *context) = 0;

    virtual antlrcpp::Any visitReadStatement(pascalParser::ReadStatementContext *context) = 0;

    virtual antlrcpp::Any visitReadlnStatement(pascalParser::ReadlnStatementContext *context) = 0;

    virtual antlrcpp::Any visitReadArguments(pascalParser::ReadArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitExpression(pascalParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimpleExpression(pascalParser::SimpleExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTerm(pascalParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitVariableFactor(pascalParser::VariableFactorContext *context) = 0;

    virtual antlrcpp::Any visitNumberFactor(pascalParser::NumberFactorContext *context) = 0;

    virtual antlrcpp::Any visitCharacterFactor(pascalParser::CharacterFactorContext *context) = 0;

    virtual antlrcpp::Any visitStringFactor(pascalParser::StringFactorContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCallFactor(pascalParser::FunctionCallFactorContext *context) = 0;

    virtual antlrcpp::Any visitNotFactor(pascalParser::NotFactorContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedFactor(pascalParser::ParenthesizedFactorContext *context) = 0;

    virtual antlrcpp::Any visitVariable(pascalParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitModifier(pascalParser::ModifierContext *context) = 0;

    virtual antlrcpp::Any visitIndexList(pascalParser::IndexListContext *context) = 0;

    virtual antlrcpp::Any visitIndex(pascalParser::IndexContext *context) = 0;

    virtual antlrcpp::Any visitField(pascalParser::FieldContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(pascalParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitFunctionName(pascalParser::FunctionNameContext *context) = 0;

    virtual antlrcpp::Any visitNumber(pascalParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedNumber(pascalParser::UnsignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitIntegerConstant(pascalParser::IntegerConstantContext *context) = 0;

    virtual antlrcpp::Any visitRealConstant(pascalParser::RealConstantContext *context) = 0;

    virtual antlrcpp::Any visitCharacterConstant(pascalParser::CharacterConstantContext *context) = 0;

    virtual antlrcpp::Any visitStringConstant(pascalParser::StringConstantContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(pascalParser::RelOpContext *context) = 0;

    virtual antlrcpp::Any visitAddOp(pascalParser::AddOpContext *context) = 0;

    virtual antlrcpp::Any visitMulOp(pascalParser::MulOpContext *context) = 0;


};

