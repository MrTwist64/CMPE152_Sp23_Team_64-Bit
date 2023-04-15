
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from pascal.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  pascalLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    PROGRAM = 21, CONST = 22, TYPE = 23, ARRAY = 24, OF = 25, RECORD = 26, 
    VAR = 27, BEGIN = 28, END = 29, DIV = 30, MOD = 31, AND = 32, OR = 33, 
    NOT = 34, IF = 35, THEN = 36, ELSE = 37, CASE = 38, REPEAT = 39, UNTIL = 40, 
    WHILE = 41, DO = 42, FOR = 43, TO = 44, DOWNTO = 45, WRITE = 46, WRITELN = 47, 
    READ = 48, READLN = 49, PROCEDURE = 50, FUNCTION = 51, IDENTIFIER = 52, 
    INTEGER = 53, REAL = 54, NEWLINE = 55, WS = 56, QUOTE = 57, CHARACTER = 58, 
    STRING = 59, COMMENT = 60
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

