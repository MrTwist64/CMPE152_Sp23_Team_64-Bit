
// Generated from Expr.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "ExprListener.h"


/**
 * This class provides an empty implementation of ExprListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ExprBaseListener : public ExprListener {
public:

  virtual void enterProgram(ExprParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(ExprParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(ExprParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ExprParser::StatementContext * /*ctx*/) override { }

  virtual void enterExpr(ExprParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ExprParser::ExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

