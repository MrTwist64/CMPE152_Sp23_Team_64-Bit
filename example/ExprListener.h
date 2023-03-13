
// Generated from Expr.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ExprParser.
 */
class  ExprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(ExprParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(ExprParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(ExprParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ExprParser::StatementContext *ctx) = 0;

  virtual void enterExpr(ExprParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ExprParser::ExprContext *ctx) = 0;


};

