
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from pascal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "pascalVisitor.h"


/**
 * This class provides an empty implementation of pascalVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  pascalBaseVisitor : public pascalVisitor {
public:

  virtual antlrcpp::Any visitProgram(pascalParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgramHeader(pascalParser::ProgramHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgramParameters(pascalParser::ProgramParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgramIdentifier(pascalParser::ProgramIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(pascalParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarations(pascalParser::DeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantsPart(pascalParser::ConstantsPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantDefinitionsList(pascalParser::ConstantDefinitionsListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantDefinition(pascalParser::ConstantDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantIdentifier(pascalParser::ConstantIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant(pascalParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSign(pascalParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypesPart(pascalParser::TypesPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeDefinitionsList(pascalParser::TypeDefinitionsListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeDefinition(pascalParser::TypeDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeIdentifier(pascalParser::TypeIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleTypespec(pascalParser::SimpleTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayTypespec(pascalParser::ArrayTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecordTypespec(pascalParser::RecordTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeIdentifierTypespec(pascalParser::TypeIdentifierTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumerationTypespec(pascalParser::EnumerationTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubrangeTypespec(pascalParser::SubrangeTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumerationType(pascalParser::EnumerationTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumerationConstant(pascalParser::EnumerationConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubrangeType(pascalParser::SubrangeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayType(pascalParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayDimensionList(pascalParser::ArrayDimensionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecordType(pascalParser::RecordTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecordFields(pascalParser::RecordFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariablesPart(pascalParser::VariablesPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationsList(pascalParser::VariableDeclarationsListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarations(pascalParser::VariableDeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableIdentifierList(pascalParser::VariableIdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableIdentifier(pascalParser::VariableIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutinesPart(pascalParser::RoutinesPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineDefinition(pascalParser::RoutineDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureHead(pascalParser::ProcedureHeadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionHead(pascalParser::FunctionHeadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineIdentifier(pascalParser::RoutineIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(pascalParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterDeclarationsList(pascalParser::ParameterDeclarationsListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterDeclarations(pascalParser::ParameterDeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterIdentifierList(pascalParser::ParameterIdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterIdentifier(pascalParser::ParameterIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(pascalParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompoundStatement(pascalParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyStatement(pascalParser::EmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(pascalParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(pascalParser::AssignmentStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLhs(pascalParser::LhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRhs(pascalParser::RhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(pascalParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrueStatement(pascalParser::TrueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFalseStatement(pascalParser::FalseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseStatement(pascalParser::CaseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseBranchList(pascalParser::CaseBranchListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseBranch(pascalParser::CaseBranchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseConstantList(pascalParser::CaseConstantListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseConstant(pascalParser::CaseConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepeatStatement(pascalParser::RepeatStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(pascalParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(pascalParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureCallStatement(pascalParser::ProcedureCallStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureName(pascalParser::ProcedureNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentList(pascalParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgument(pascalParser::ArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteStatement(pascalParser::WriteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWritelnStatement(pascalParser::WritelnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteArguments(pascalParser::WriteArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteArgument(pascalParser::WriteArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldWidth(pascalParser::FieldWidthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecimalPlaces(pascalParser::DecimalPlacesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadStatement(pascalParser::ReadStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadlnStatement(pascalParser::ReadlnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadArguments(pascalParser::ReadArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(pascalParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleExpression(pascalParser::SimpleExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(pascalParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableFactor(pascalParser::VariableFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberFactor(pascalParser::NumberFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharacterFactor(pascalParser::CharacterFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringFactor(pascalParser::StringFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCallFactor(pascalParser::FunctionCallFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotFactor(pascalParser::NotFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesizedFactor(pascalParser::ParenthesizedFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(pascalParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModifier(pascalParser::ModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexList(pascalParser::IndexListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex(pascalParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitField(pascalParser::FieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(pascalParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionName(pascalParser::FunctionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(pascalParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedNumber(pascalParser::UnsignedNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntegerConstant(pascalParser::IntegerConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRealConstant(pascalParser::RealConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharacterConstant(pascalParser::CharacterConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringConstant(pascalParser::StringConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelOp(pascalParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddOp(pascalParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulOp(pascalParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }


};

