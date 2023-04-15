
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from pascal.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "pascalVisitor.h"


/**
 * This class provides an empty implementation of pascalVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  pascalBaseVisitor : public pascalVisitor {
public:

  virtual std::any visitProgram(pascalParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramHeader(pascalParser::ProgramHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramParameters(pascalParser::ProgramParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramIdentifier(pascalParser::ProgramIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(pascalParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarations(pascalParser::DeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantsPart(pascalParser::ConstantsPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantDefinitionsList(pascalParser::ConstantDefinitionsListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantDefinition(pascalParser::ConstantDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantIdentifier(pascalParser::ConstantIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(pascalParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSign(pascalParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypesPart(pascalParser::TypesPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeDefinitionsList(pascalParser::TypeDefinitionsListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeDefinition(pascalParser::TypeDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeIdentifier(pascalParser::TypeIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleTypespec(pascalParser::SimpleTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayTypespec(pascalParser::ArrayTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordTypespec(pascalParser::RecordTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeIdentifierTypespec(pascalParser::TypeIdentifierTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumerationTypespec(pascalParser::EnumerationTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubrangeTypespec(pascalParser::SubrangeTypespecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumerationType(pascalParser::EnumerationTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumerationConstant(pascalParser::EnumerationConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubrangeType(pascalParser::SubrangeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(pascalParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayDimensionList(pascalParser::ArrayDimensionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordType(pascalParser::RecordTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordFields(pascalParser::RecordFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariablesPart(pascalParser::VariablesPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclarationsList(pascalParser::VariableDeclarationsListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclarations(pascalParser::VariableDeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableIdentifierList(pascalParser::VariableIdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableIdentifier(pascalParser::VariableIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutinesPart(pascalParser::RoutinesPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutineDefinition(pascalParser::RoutineDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureHead(pascalParser::ProcedureHeadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionHead(pascalParser::FunctionHeadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutineIdentifier(pascalParser::RoutineIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(pascalParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterDeclarationsList(pascalParser::ParameterDeclarationsListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterDeclarations(pascalParser::ParameterDeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterIdentifierList(pascalParser::ParameterIdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterIdentifier(pascalParser::ParameterIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(pascalParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundStatement(pascalParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptyStatement(pascalParser::EmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementList(pascalParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentStatement(pascalParser::AssignmentStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLhs(pascalParser::LhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRhs(pascalParser::RhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(pascalParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrueStatement(pascalParser::TrueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFalseStatement(pascalParser::FalseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseStatement(pascalParser::CaseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseBranchList(pascalParser::CaseBranchListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseBranch(pascalParser::CaseBranchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseConstantList(pascalParser::CaseConstantListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseConstant(pascalParser::CaseConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRepeatStatement(pascalParser::RepeatStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(pascalParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(pascalParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureCallStatement(pascalParser::ProcedureCallStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureName(pascalParser::ProcedureNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(pascalParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgument(pascalParser::ArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWriteStatement(pascalParser::WriteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWritelnStatement(pascalParser::WritelnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWriteArguments(pascalParser::WriteArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWriteArgument(pascalParser::WriteArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldWidth(pascalParser::FieldWidthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimalPlaces(pascalParser::DecimalPlacesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReadStatement(pascalParser::ReadStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReadlnStatement(pascalParser::ReadlnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReadArguments(pascalParser::ReadArgumentsContext *ctx) override {
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

  virtual std::any visitVariableFactor(pascalParser::VariableFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberFactor(pascalParser::NumberFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharacterFactor(pascalParser::CharacterFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringFactor(pascalParser::StringFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallFactor(pascalParser::FunctionCallFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotFactor(pascalParser::NotFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedFactor(pascalParser::ParenthesizedFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(pascalParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModifier(pascalParser::ModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexList(pascalParser::IndexListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndex(pascalParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitField(pascalParser::FieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(pascalParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionName(pascalParser::FunctionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(pascalParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnsignedNumber(pascalParser::UnsignedNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerConstant(pascalParser::IntegerConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRealConstant(pascalParser::RealConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharacterConstant(pascalParser::CharacterConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringConstant(pascalParser::StringConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelOp(pascalParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddOp(pascalParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulOp(pascalParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }


};

