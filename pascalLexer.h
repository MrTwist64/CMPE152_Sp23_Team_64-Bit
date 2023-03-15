
// Generated from pascal.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  pascalLexer : public antlr4::Lexer {
public:
  enum {
    AND = 1, ARRAY = 2, ASM = 3, BEGIN = 4, BREAK = 5, CASE = 6, CONST = 7, 
    CONSTRUCTOR = 8, CONTINUE = 9, DESTRUCTOR = 10, DIV = 11, DO = 12, DOWNTO = 13, 
    ELSE = 14, END = 15, FALSE = 16, FILE = 17, FOR = 18, FUNCTION = 19, 
    GOTO = 20, IF = 21, IMPLEMENTATION = 22, IN = 23, INLINE = 24, INTERFACE = 25, 
    LABEL = 26, MOD = 27, NIL = 28, NOT = 29, OBJECT = 30, OF = 31, ON = 32, 
    OPERATOR = 33, OR = 34, PACKED = 35, PROCEDURE = 36, PROGRAM = 37, RECORD = 38, 
    REPEAT = 39, SET = 40, SHL = 41, SHR = 42, STRING = 43, THEN = 44, TO = 45, 
    TRUE = 46, TYPE = 47, UNIT = 48, UNTIL = 49, USES = 50, VAR = 51, WHILE = 52, 
    WITH = 53, XOR = 54, PLUSOP = 55, MINUSOP = 56, MULTOP = 57, DIVOP = 58, 
    ASSIGN = 59, EQUAL = 60, NE = 61, LTEQ = 62, GTEQ = 63, LT = 64, GT = 65, 
    PLUSEQUAL = 66, MINUSEQUAL = 67, MULTEQUAL = 68, DIVEQUAL = 69, CARAT = 70, 
    SEMICOLON = 71, COMMA = 72, LPAREN = 73, RPAREN = 74, LBRACKET = 75, 
    RBRACKET = 76, LBRACE = 77, RBRACE = 78, LCOMMENT = 79, RCOMMENT = 80, 
    INTEGER = 81, REAL = 82, IDENTIFIER = 83, WS = 84
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

