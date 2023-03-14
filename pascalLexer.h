
// Generated from pascal.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  pascalLexer : public antlr4::Lexer {
public:
  enum {
    AND = 1, ARRAY = 2, ASM = 3, BEGIN = 4, BREAK = 5, CASE = 6, CONST = 7, 
    CONSTRUCTOR = 8, CONTINUE = 9, DESTRUCTOR = 10, DIV = 11, DO = 12, DOWNTO = 13, 
    ELSE = 14, FALSE = 15, FILE = 16, FOR = 17, FUNCTION = 18, GOTO = 19, 
    IF = 20, IMPLEMENTATION = 21, IN = 22, INLINE = 23, INTERFACE = 24, 
    LABEL = 25, MOD = 26, NIL = 27, NOT = 28, OBJECT = 29, OF = 30, ON = 31, 
    OPERATOR = 32, OR = 33, PACKED = 34, PROCEDURE = 35, PROGRAM = 36, RECORD = 37, 
    REPEAT = 38, SET = 39, SHL = 40, SHR = 41, STRING = 42, THEN = 43, TO = 44, 
    TRUE = 45, TYPE = 46, UNIT = 47, UNTIL = 48, USES = 49, VAR = 50, WHILE = 51, 
    WITH = 52, XOR = 53, INTEGER = 54, REAL = 55, IDENTIFIER = 56, PLUSOP = 57, 
    MINUSOP = 58, MULTOP = 59, DIVOP = 60, ASSIGN = 61, EQUAL = 62, NE = 63, 
    LTEQ = 64, GTEQ = 65, LT = 66, GT = 67, PLUSEQUAL = 68, MINUSEQUAL = 69, 
    MULTEQUAL = 70, DIVEQUAL = 71, CARAT = 72, SEMICOLON = 73, COMMA = 74, 
    LPAREN = 75, RPAREN = 76, LBRACKET = 77, RBRACKET = 78, LBRACE = 79, 
    RBRACE = 80, LCOMMENT = 81, RCOMMENT = 82, WS = 83
  };

  explicit pascalLexer(antlr4::CharStream *input);

  ~pascalLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

