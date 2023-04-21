
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from pascal.g4 by ANTLR 4.7.2


#include "pascalVisitor.h"

#include "pascalParser.h"


using namespace antlrcpp;
using namespace antlr4;

pascalParser::pascalParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

pascalParser::~pascalParser() {
  delete _interpreter;
}

std::string pascalParser::getGrammarFileName() const {
  return "pascal.g4";
}

const std::vector<std::string>& pascalParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& pascalParser::getVocabulary() const {
  return _vocabulary;
}

//----------------- ProgramContext ------------------------------------------------------------------

//ProgramContext() 
pascalParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

//programHeader() retrieve child context
pascalParser::ProgramHeaderContext* pascalParser::ProgramContext::programHeader() {
  return getRuleContext<pascalParser::ProgramHeaderContext>(0);
}

//block() retrieve child context
pascalParser::BlockContext* pascalParser::ProgramContext::block() {
  return getRuleContext<pascalParser::BlockContext>(0);
}

//getRuleIndex() returns index of "program rule"
size_t pascalParser::ProgramContext::getRuleIndex() const {
  //cout << "pascalParser::ProgramContext::getRuleIndex() called" << endl;
  return pascalParser::RuleProgram;
}

//accept() checks if visitor is pascalVisitor and calls visitProgram() otherwise calls visitChildreN()
antlrcpp::Any pascalParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

//program() starts parsing "program" rule
pascalParser::ProgramContext* pascalParser::program() {
  
  //creates new instance of ProgramContext
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());

  //enters "program" rules
  enterRule(_localctx, 0, pascalParser::RuleProgram);

  //ensures exit of "program" rules
  auto onExit = finally([=] {
    exitRule();
  });

  //parses "program" rule
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    programHeader();
    setState(183);
    block();
    setState(184);
    match(pascalParser::T__0);
   
  } //if exception, reports error to error handler, stores exception, tries to recover from error by resyncing parser and input stream
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramHeaderContext ------------------------------------------------------------------

pascalParser::ProgramHeaderContext::ProgramHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ProgramHeaderContext::PROGRAM() {
  return getToken(pascalParser::PROGRAM, 0);
}

pascalParser::ProgramIdentifierContext* pascalParser::ProgramHeaderContext::programIdentifier() {
  return getRuleContext<pascalParser::ProgramIdentifierContext>(0);
}

pascalParser::ProgramParametersContext* pascalParser::ProgramHeaderContext::programParameters() {
  return getRuleContext<pascalParser::ProgramParametersContext>(0);
}


size_t pascalParser::ProgramHeaderContext::getRuleIndex() const {
  return pascalParser::RuleProgramHeader;
}


antlrcpp::Any pascalParser::ProgramHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProgramHeader(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProgramHeaderContext* pascalParser::programHeader() {
  ProgramHeaderContext *_localctx = _tracker.createInstance<ProgramHeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, pascalParser::RuleProgramHeader);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(pascalParser::PROGRAM);
    setState(187);
    programIdentifier();
    setState(189);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::T__2) {
      setState(188);
      programParameters();
    }
    setState(191);
    match(pascalParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramParametersContext ------------------------------------------------------------------

pascalParser::ProgramParametersContext::ProgramParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> pascalParser::ProgramParametersContext::IDENTIFIER() {
  return getTokens(pascalParser::IDENTIFIER);
}

tree::TerminalNode* pascalParser::ProgramParametersContext::IDENTIFIER(size_t i) {
  return getToken(pascalParser::IDENTIFIER, i);
}


size_t pascalParser::ProgramParametersContext::getRuleIndex() const {
  return pascalParser::RuleProgramParameters;
}


antlrcpp::Any pascalParser::ProgramParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProgramParameters(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProgramParametersContext* pascalParser::programParameters() {
  ProgramParametersContext *_localctx = _tracker.createInstance<ProgramParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, pascalParser::RuleProgramParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    match(pascalParser::T__2);
    setState(194);
    match(pascalParser::IDENTIFIER);
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(195);
      match(pascalParser::T__3);
      setState(196);
      match(pascalParser::IDENTIFIER);
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(202);
    match(pascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramIdentifierContext ------------------------------------------------------------------

pascalParser::ProgramIdentifierContext::ProgramIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ProgramIdentifierContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}


size_t pascalParser::ProgramIdentifierContext::getRuleIndex() const {
  return pascalParser::RuleProgramIdentifier;
}


antlrcpp::Any pascalParser::ProgramIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProgramIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProgramIdentifierContext* pascalParser::programIdentifier() {
  ProgramIdentifierContext *_localctx = _tracker.createInstance<ProgramIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 6, pascalParser::RuleProgramIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);

    Token* identToken = match(pascalParser::IDENTIFIER);
    _localctx->entry = stack->enterLocal(identToken->getText(), Kind::PROGRAM);
    
    Symtab* newTable = new Symtab(stack->getCurrNestingLevel() + 1);
    stack->push(newTable);
    newTable->setOwner(_localctx->entry);
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

pascalParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::DeclarationsContext* pascalParser::BlockContext::declarations() {
  return getRuleContext<pascalParser::DeclarationsContext>(0);
}

pascalParser::CompoundStatementContext* pascalParser::BlockContext::compoundStatement() {
  return getRuleContext<pascalParser::CompoundStatementContext>(0);
}


size_t pascalParser::BlockContext::getRuleIndex() const {
  return pascalParser::RuleBlock;
}


antlrcpp::Any pascalParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::BlockContext* pascalParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, pascalParser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    declarations();
    setState(207);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

pascalParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ConstantsPartContext* pascalParser::DeclarationsContext::constantsPart() {
  return getRuleContext<pascalParser::ConstantsPartContext>(0);
}

pascalParser::TypesPartContext* pascalParser::DeclarationsContext::typesPart() {
  return getRuleContext<pascalParser::TypesPartContext>(0);
}

pascalParser::VariablesPartContext* pascalParser::DeclarationsContext::variablesPart() {
  return getRuleContext<pascalParser::VariablesPartContext>(0);
}

pascalParser::RoutinesPartContext* pascalParser::DeclarationsContext::routinesPart() {
  return getRuleContext<pascalParser::RoutinesPartContext>(0);
}


size_t pascalParser::DeclarationsContext::getRuleIndex() const {
  return pascalParser::RuleDeclarations;
}


antlrcpp::Any pascalParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::DeclarationsContext* pascalParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 10, pascalParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::CONST) {
      setState(209);
      constantsPart();
      setState(210);
      match(pascalParser::T__1);
    }
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::TYPE) {
      setState(214);
      typesPart();
      setState(215);
      match(pascalParser::T__1);
    }
    setState(222);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::VAR) {
      setState(219);
      variablesPart();
      setState(220);
      match(pascalParser::T__1);
    }
    setState(227);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::PROCEDURE

    || _la == pascalParser::FUNCTION) {
      setState(224);
      routinesPart();
      setState(225);
      match(pascalParser::T__1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantsPartContext ------------------------------------------------------------------

pascalParser::ConstantsPartContext::ConstantsPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ConstantsPartContext::CONST() {
  return getToken(pascalParser::CONST, 0);
}

pascalParser::ConstantDefinitionsListContext* pascalParser::ConstantsPartContext::constantDefinitionsList() {
  return getRuleContext<pascalParser::ConstantDefinitionsListContext>(0);
}


size_t pascalParser::ConstantsPartContext::getRuleIndex() const {
  return pascalParser::RuleConstantsPart;
}


antlrcpp::Any pascalParser::ConstantsPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstantsPart(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantsPartContext* pascalParser::constantsPart() {
  ConstantsPartContext *_localctx = _tracker.createInstance<ConstantsPartContext>(_ctx, getState());
  enterRule(_localctx, 12, pascalParser::RuleConstantsPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(pascalParser::CONST);
    setState(230);
    constantDefinitionsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionsListContext ------------------------------------------------------------------

pascalParser::ConstantDefinitionsListContext::ConstantDefinitionsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::ConstantDefinitionContext *> pascalParser::ConstantDefinitionsListContext::constantDefinition() {
  return getRuleContexts<pascalParser::ConstantDefinitionContext>();
}

pascalParser::ConstantDefinitionContext* pascalParser::ConstantDefinitionsListContext::constantDefinition(size_t i) {
  return getRuleContext<pascalParser::ConstantDefinitionContext>(i);
}


size_t pascalParser::ConstantDefinitionsListContext::getRuleIndex() const {
  return pascalParser::RuleConstantDefinitionsList;
}


antlrcpp::Any pascalParser::ConstantDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantDefinitionsListContext* pascalParser::constantDefinitionsList() {
  ConstantDefinitionsListContext *_localctx = _tracker.createInstance<ConstantDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 14, pascalParser::RuleConstantDefinitionsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(232);
    constantDefinition();
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(233);
        match(pascalParser::T__1);
        setState(234);
        constantDefinition(); 
      }
      setState(239);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionContext ------------------------------------------------------------------

pascalParser::ConstantDefinitionContext::ConstantDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ConstantIdentifierContext* pascalParser::ConstantDefinitionContext::constantIdentifier() {
  return getRuleContext<pascalParser::ConstantIdentifierContext>(0);
}

pascalParser::ConstantContext* pascalParser::ConstantDefinitionContext::constant() {
  return getRuleContext<pascalParser::ConstantContext>(0);
}


size_t pascalParser::ConstantDefinitionContext::getRuleIndex() const {
  return pascalParser::RuleConstantDefinition;
}


antlrcpp::Any pascalParser::ConstantDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinition(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantDefinitionContext* pascalParser::constantDefinition() {
  ConstantDefinitionContext *_localctx = _tracker.createInstance<ConstantDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 16, pascalParser::RuleConstantDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    constantIdentifier();
    setState(241);
    match(pascalParser::T__5);
    setState(242);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantIdentifierContext ------------------------------------------------------------------

pascalParser::ConstantIdentifierContext::ConstantIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ConstantIdentifierContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}


size_t pascalParser::ConstantIdentifierContext::getRuleIndex() const {
  return pascalParser::RuleConstantIdentifier;
}


antlrcpp::Any pascalParser::ConstantIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstantIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantIdentifierContext* pascalParser::constantIdentifier() {
  ConstantIdentifierContext *_localctx = _tracker.createInstance<ConstantIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 18, pascalParser::RuleConstantIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(pascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

pascalParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ConstantContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}

pascalParser::UnsignedNumberContext* pascalParser::ConstantContext::unsignedNumber() {
  return getRuleContext<pascalParser::UnsignedNumberContext>(0);
}

pascalParser::SignContext* pascalParser::ConstantContext::sign() {
  return getRuleContext<pascalParser::SignContext>(0);
}

pascalParser::CharacterConstantContext* pascalParser::ConstantContext::characterConstant() {
  return getRuleContext<pascalParser::CharacterConstantContext>(0);
}

pascalParser::StringConstantContext* pascalParser::ConstantContext::stringConstant() {
  return getRuleContext<pascalParser::StringConstantContext>(0);
}


size_t pascalParser::ConstantContext::getRuleIndex() const {
  return pascalParser::RuleConstant;
}


antlrcpp::Any pascalParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantContext* pascalParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 20, pascalParser::RuleConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(255);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::T__6:
      case pascalParser::T__7:
      case pascalParser::IDENTIFIER:
      case pascalParser::INTEGER:
      case pascalParser::REAL: {
        enterOuterAlt(_localctx, 1);
        setState(247);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == pascalParser::T__6

        || _la == pascalParser::T__7) {
          setState(246);
          sign();
        }
        setState(251);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case pascalParser::IDENTIFIER: {
            setState(249);
            match(pascalParser::IDENTIFIER);
            break;
          }

          case pascalParser::INTEGER:
          case pascalParser::REAL: {
            setState(250);
            unsignedNumber();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case pascalParser::CHARACTER: {
        enterOuterAlt(_localctx, 2);
        setState(253);
        characterConstant();
        break;
      }

      case pascalParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(254);
        stringConstant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

pascalParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pascalParser::SignContext::getRuleIndex() const {
  return pascalParser::RuleSign;
}


antlrcpp::Any pascalParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::SignContext* pascalParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 22, pascalParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    _la = _input->LA(1);
    if (!(_la == pascalParser::T__6

    || _la == pascalParser::T__7)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypesPartContext ------------------------------------------------------------------

pascalParser::TypesPartContext::TypesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::TypesPartContext::TYPE() {
  return getToken(pascalParser::TYPE, 0);
}

pascalParser::TypeDefinitionsListContext* pascalParser::TypesPartContext::typeDefinitionsList() {
  return getRuleContext<pascalParser::TypeDefinitionsListContext>(0);
}


size_t pascalParser::TypesPartContext::getRuleIndex() const {
  return pascalParser::RuleTypesPart;
}


antlrcpp::Any pascalParser::TypesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypesPart(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TypesPartContext* pascalParser::typesPart() {
  TypesPartContext *_localctx = _tracker.createInstance<TypesPartContext>(_ctx, getState());
  enterRule(_localctx, 24, pascalParser::RuleTypesPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(pascalParser::TYPE);
    setState(260);
    typeDefinitionsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionsListContext ------------------------------------------------------------------

pascalParser::TypeDefinitionsListContext::TypeDefinitionsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::TypeDefinitionContext *> pascalParser::TypeDefinitionsListContext::typeDefinition() {
  return getRuleContexts<pascalParser::TypeDefinitionContext>();
}

pascalParser::TypeDefinitionContext* pascalParser::TypeDefinitionsListContext::typeDefinition(size_t i) {
  return getRuleContext<pascalParser::TypeDefinitionContext>(i);
}


size_t pascalParser::TypeDefinitionsListContext::getRuleIndex() const {
  return pascalParser::RuleTypeDefinitionsList;
}


antlrcpp::Any pascalParser::TypeDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TypeDefinitionsListContext* pascalParser::typeDefinitionsList() {
  TypeDefinitionsListContext *_localctx = _tracker.createInstance<TypeDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 26, pascalParser::RuleTypeDefinitionsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(262);
    typeDefinition();
    setState(267);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(263);
        match(pascalParser::T__1);
        setState(264);
        typeDefinition(); 
      }
      setState(269);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionContext ------------------------------------------------------------------

pascalParser::TypeDefinitionContext::TypeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::TypeIdentifierContext* pascalParser::TypeDefinitionContext::typeIdentifier() {
  return getRuleContext<pascalParser::TypeIdentifierContext>(0);
}

pascalParser::TypeSpecificationContext* pascalParser::TypeDefinitionContext::typeSpecification() {
  return getRuleContext<pascalParser::TypeSpecificationContext>(0);
}


size_t pascalParser::TypeDefinitionContext::getRuleIndex() const {
  return pascalParser::RuleTypeDefinition;
}


antlrcpp::Any pascalParser::TypeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinition(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TypeDefinitionContext* pascalParser::typeDefinition() {
  TypeDefinitionContext *_localctx = _tracker.createInstance<TypeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 28, pascalParser::RuleTypeDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    typeIdentifier();
    setState(271);
    match(pascalParser::T__5);
    setState(272);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIdentifierContext ------------------------------------------------------------------

pascalParser::TypeIdentifierContext::TypeIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::TypeIdentifierContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}


size_t pascalParser::TypeIdentifierContext::getRuleIndex() const {
  return pascalParser::RuleTypeIdentifier;
}


antlrcpp::Any pascalParser::TypeIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TypeIdentifierContext* pascalParser::typeIdentifier() {
  TypeIdentifierContext *_localctx = _tracker.createInstance<TypeIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 30, pascalParser::RuleTypeIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    match(pascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecificationContext ------------------------------------------------------------------

pascalParser::TypeSpecificationContext::TypeSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pascalParser::TypeSpecificationContext::getRuleIndex() const {
  return pascalParser::RuleTypeSpecification;
}

void pascalParser::TypeSpecificationContext::copyFrom(TypeSpecificationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- SimpleTypespecContext ------------------------------------------------------------------

pascalParser::SimpleTypeContext* pascalParser::SimpleTypespecContext::simpleType() {
  return getRuleContext<pascalParser::SimpleTypeContext>(0);
}

pascalParser::SimpleTypespecContext::SimpleTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::SimpleTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitSimpleTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayTypespecContext ------------------------------------------------------------------

pascalParser::ArrayTypeContext* pascalParser::ArrayTypespecContext::arrayType() {
  return getRuleContext<pascalParser::ArrayTypeContext>(0);
}

pascalParser::ArrayTypespecContext::ArrayTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::ArrayTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitArrayTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RecordTypespecContext ------------------------------------------------------------------

pascalParser::RecordTypeContext* pascalParser::RecordTypespecContext::recordType() {
  return getRuleContext<pascalParser::RecordTypeContext>(0);
}

pascalParser::RecordTypespecContext::RecordTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::RecordTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRecordTypespec(this);
  else
    return visitor->visitChildren(this);
}
pascalParser::TypeSpecificationContext* pascalParser::typeSpecification() {
  TypeSpecificationContext *_localctx = _tracker.createInstance<TypeSpecificationContext>(_ctx, getState());
  enterRule(_localctx, 32, pascalParser::RuleTypeSpecification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(279);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::T__2:
      case pascalParser::T__6:
      case pascalParser::T__7:
      case pascalParser::IDENTIFIER:
      case pascalParser::INTEGER:
      case pascalParser::REAL:
      case pascalParser::CHARACTER:
      case pascalParser::STRING: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<pascalParser::SimpleTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(276);
        simpleType();
        break;
      }

      case pascalParser::ARRAY: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<pascalParser::ArrayTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(277);
        arrayType();
        break;
      }

      case pascalParser::RECORD: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<pascalParser::RecordTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(278);
        recordType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleTypeContext ------------------------------------------------------------------

pascalParser::SimpleTypeContext::SimpleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pascalParser::SimpleTypeContext::getRuleIndex() const {
  return pascalParser::RuleSimpleType;
}

void pascalParser::SimpleTypeContext::copyFrom(SimpleTypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- SubrangeTypespecContext ------------------------------------------------------------------

pascalParser::SubrangeTypeContext* pascalParser::SubrangeTypespecContext::subrangeType() {
  return getRuleContext<pascalParser::SubrangeTypeContext>(0);
}

pascalParser::SubrangeTypespecContext::SubrangeTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::SubrangeTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitSubrangeTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EnumerationTypespecContext ------------------------------------------------------------------

pascalParser::EnumerationTypeContext* pascalParser::EnumerationTypespecContext::enumerationType() {
  return getRuleContext<pascalParser::EnumerationTypeContext>(0);
}

pascalParser::EnumerationTypespecContext::EnumerationTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::EnumerationTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitEnumerationTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeIdentifierTypespecContext ------------------------------------------------------------------

pascalParser::TypeIdentifierContext* pascalParser::TypeIdentifierTypespecContext::typeIdentifier() {
  return getRuleContext<pascalParser::TypeIdentifierContext>(0);
}

pascalParser::TypeIdentifierTypespecContext::TypeIdentifierTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::TypeIdentifierTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifierTypespec(this);
  else
    return visitor->visitChildren(this);
}
pascalParser::SimpleTypeContext* pascalParser::simpleType() {
  SimpleTypeContext *_localctx = _tracker.createInstance<SimpleTypeContext>(_ctx, getState());
  enterRule(_localctx, 34, pascalParser::RuleSimpleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(284);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<pascalParser::TypeIdentifierTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(281);
      typeIdentifier();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<pascalParser::EnumerationTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(282);
      enumerationType();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<pascalParser::SubrangeTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(283);
      subrangeType();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationTypeContext ------------------------------------------------------------------

pascalParser::EnumerationTypeContext::EnumerationTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::EnumerationConstantContext *> pascalParser::EnumerationTypeContext::enumerationConstant() {
  return getRuleContexts<pascalParser::EnumerationConstantContext>();
}

pascalParser::EnumerationConstantContext* pascalParser::EnumerationTypeContext::enumerationConstant(size_t i) {
  return getRuleContext<pascalParser::EnumerationConstantContext>(i);
}


size_t pascalParser::EnumerationTypeContext::getRuleIndex() const {
  return pascalParser::RuleEnumerationType;
}


antlrcpp::Any pascalParser::EnumerationTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitEnumerationType(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::EnumerationTypeContext* pascalParser::enumerationType() {
  EnumerationTypeContext *_localctx = _tracker.createInstance<EnumerationTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, pascalParser::RuleEnumerationType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    match(pascalParser::T__2);
    setState(287);
    enumerationConstant();
    setState(292);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(288);
      match(pascalParser::T__3);
      setState(289);
      enumerationConstant();
      setState(294);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(295);
    match(pascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationConstantContext ------------------------------------------------------------------

pascalParser::EnumerationConstantContext::EnumerationConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ConstantIdentifierContext* pascalParser::EnumerationConstantContext::constantIdentifier() {
  return getRuleContext<pascalParser::ConstantIdentifierContext>(0);
}


size_t pascalParser::EnumerationConstantContext::getRuleIndex() const {
  return pascalParser::RuleEnumerationConstant;
}


antlrcpp::Any pascalParser::EnumerationConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitEnumerationConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::EnumerationConstantContext* pascalParser::enumerationConstant() {
  EnumerationConstantContext *_localctx = _tracker.createInstance<EnumerationConstantContext>(_ctx, getState());
  enterRule(_localctx, 38, pascalParser::RuleEnumerationConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    constantIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubrangeTypeContext ------------------------------------------------------------------

pascalParser::SubrangeTypeContext::SubrangeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::ConstantContext *> pascalParser::SubrangeTypeContext::constant() {
  return getRuleContexts<pascalParser::ConstantContext>();
}

pascalParser::ConstantContext* pascalParser::SubrangeTypeContext::constant(size_t i) {
  return getRuleContext<pascalParser::ConstantContext>(i);
}


size_t pascalParser::SubrangeTypeContext::getRuleIndex() const {
  return pascalParser::RuleSubrangeType;
}


antlrcpp::Any pascalParser::SubrangeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitSubrangeType(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::SubrangeTypeContext* pascalParser::subrangeType() {
  SubrangeTypeContext *_localctx = _tracker.createInstance<SubrangeTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, pascalParser::RuleSubrangeType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    constant();
    setState(300);
    match(pascalParser::T__8);
    setState(301);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

pascalParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ArrayTypeContext::ARRAY() {
  return getToken(pascalParser::ARRAY, 0);
}

pascalParser::ArrayDimensionListContext* pascalParser::ArrayTypeContext::arrayDimensionList() {
  return getRuleContext<pascalParser::ArrayDimensionListContext>(0);
}

tree::TerminalNode* pascalParser::ArrayTypeContext::OF() {
  return getToken(pascalParser::OF, 0);
}

pascalParser::TypeSpecificationContext* pascalParser::ArrayTypeContext::typeSpecification() {
  return getRuleContext<pascalParser::TypeSpecificationContext>(0);
}


size_t pascalParser::ArrayTypeContext::getRuleIndex() const {
  return pascalParser::RuleArrayType;
}


antlrcpp::Any pascalParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ArrayTypeContext* pascalParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 42, pascalParser::RuleArrayType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(pascalParser::ARRAY);
    setState(304);
    match(pascalParser::T__9);
    setState(305);
    arrayDimensionList();
    setState(306);
    match(pascalParser::T__10);
    setState(307);
    match(pascalParser::OF);
    setState(308);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDimensionListContext ------------------------------------------------------------------

pascalParser::ArrayDimensionListContext::ArrayDimensionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::SimpleTypeContext *> pascalParser::ArrayDimensionListContext::simpleType() {
  return getRuleContexts<pascalParser::SimpleTypeContext>();
}

pascalParser::SimpleTypeContext* pascalParser::ArrayDimensionListContext::simpleType(size_t i) {
  return getRuleContext<pascalParser::SimpleTypeContext>(i);
}


size_t pascalParser::ArrayDimensionListContext::getRuleIndex() const {
  return pascalParser::RuleArrayDimensionList;
}


antlrcpp::Any pascalParser::ArrayDimensionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitArrayDimensionList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ArrayDimensionListContext* pascalParser::arrayDimensionList() {
  ArrayDimensionListContext *_localctx = _tracker.createInstance<ArrayDimensionListContext>(_ctx, getState());
  enterRule(_localctx, 44, pascalParser::RuleArrayDimensionList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    simpleType();
    setState(315);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(311);
      match(pascalParser::T__3);
      setState(312);
      simpleType();
      setState(317);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecordTypeContext ------------------------------------------------------------------

pascalParser::RecordTypeContext::RecordTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::RecordTypeContext::RECORD() {
  return getToken(pascalParser::RECORD, 0);
}

pascalParser::RecordFieldsContext* pascalParser::RecordTypeContext::recordFields() {
  return getRuleContext<pascalParser::RecordFieldsContext>(0);
}

tree::TerminalNode* pascalParser::RecordTypeContext::END() {
  return getToken(pascalParser::END, 0);
}


size_t pascalParser::RecordTypeContext::getRuleIndex() const {
  return pascalParser::RuleRecordType;
}


antlrcpp::Any pascalParser::RecordTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRecordType(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RecordTypeContext* pascalParser::recordType() {
  RecordTypeContext *_localctx = _tracker.createInstance<RecordTypeContext>(_ctx, getState());
  enterRule(_localctx, 46, pascalParser::RuleRecordType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    match(pascalParser::RECORD);
    setState(319);
    recordFields();
    setState(321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::T__1) {
      setState(320);
      match(pascalParser::T__1);
    }
    setState(323);
    match(pascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecordFieldsContext ------------------------------------------------------------------

pascalParser::RecordFieldsContext::RecordFieldsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::VariableDeclarationsListContext* pascalParser::RecordFieldsContext::variableDeclarationsList() {
  return getRuleContext<pascalParser::VariableDeclarationsListContext>(0);
}


size_t pascalParser::RecordFieldsContext::getRuleIndex() const {
  return pascalParser::RuleRecordFields;
}


antlrcpp::Any pascalParser::RecordFieldsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRecordFields(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RecordFieldsContext* pascalParser::recordFields() {
  RecordFieldsContext *_localctx = _tracker.createInstance<RecordFieldsContext>(_ctx, getState());
  enterRule(_localctx, 48, pascalParser::RuleRecordFields);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325);
    variableDeclarationsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesPartContext ------------------------------------------------------------------

pascalParser::VariablesPartContext::VariablesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::VariablesPartContext::VAR() {
  return getToken(pascalParser::VAR, 0);
}

pascalParser::VariableDeclarationsListContext* pascalParser::VariablesPartContext::variableDeclarationsList() {
  return getRuleContext<pascalParser::VariableDeclarationsListContext>(0);
}


size_t pascalParser::VariablesPartContext::getRuleIndex() const {
  return pascalParser::RuleVariablesPart;
}


antlrcpp::Any pascalParser::VariablesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariablesPart(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariablesPartContext* pascalParser::variablesPart() {
  VariablesPartContext *_localctx = _tracker.createInstance<VariablesPartContext>(_ctx, getState());
  enterRule(_localctx, 50, pascalParser::RuleVariablesPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    match(pascalParser::VAR);
    setState(328);
    variableDeclarationsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsListContext ------------------------------------------------------------------

pascalParser::VariableDeclarationsListContext::VariableDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::VariableDeclarationsContext *> pascalParser::VariableDeclarationsListContext::variableDeclarations() {
  return getRuleContexts<pascalParser::VariableDeclarationsContext>();
}

pascalParser::VariableDeclarationsContext* pascalParser::VariableDeclarationsListContext::variableDeclarations(size_t i) {
  return getRuleContext<pascalParser::VariableDeclarationsContext>(i);
}


size_t pascalParser::VariableDeclarationsListContext::getRuleIndex() const {
  return pascalParser::RuleVariableDeclarationsList;
}


antlrcpp::Any pascalParser::VariableDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableDeclarationsListContext* pascalParser::variableDeclarationsList() {
  VariableDeclarationsListContext *_localctx = _tracker.createInstance<VariableDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 52, pascalParser::RuleVariableDeclarationsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(330);
    variableDeclarations();
    setState(335);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(331);
        match(pascalParser::T__1);
        setState(332);
        variableDeclarations(); 
      }
      setState(337);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsContext ------------------------------------------------------------------

pascalParser::VariableDeclarationsContext::VariableDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::VariableIdentifierListContext* pascalParser::VariableDeclarationsContext::variableIdentifierList() {
  return getRuleContext<pascalParser::VariableIdentifierListContext>(0);
}

pascalParser::TypeSpecificationContext* pascalParser::VariableDeclarationsContext::typeSpecification() {
  return getRuleContext<pascalParser::TypeSpecificationContext>(0);
}


size_t pascalParser::VariableDeclarationsContext::getRuleIndex() const {
  return pascalParser::RuleVariableDeclarations;
}


antlrcpp::Any pascalParser::VariableDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarations(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableDeclarationsContext* pascalParser::variableDeclarations() {
  VariableDeclarationsContext *_localctx = _tracker.createInstance<VariableDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 54, pascalParser::RuleVariableDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    variableIdentifierList();
    setState(339);
    match(pascalParser::T__11);
    setState(340);
    typeSpecification();

    
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierListContext ------------------------------------------------------------------

pascalParser::VariableIdentifierListContext::VariableIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::VariableIdentifierContext *> pascalParser::VariableIdentifierListContext::variableIdentifier() {
  return getRuleContexts<pascalParser::VariableIdentifierContext>();
}

pascalParser::VariableIdentifierContext* pascalParser::VariableIdentifierListContext::variableIdentifier(size_t i) {
  return getRuleContext<pascalParser::VariableIdentifierContext>(i);
}


size_t pascalParser::VariableIdentifierListContext::getRuleIndex() const {
  return pascalParser::RuleVariableIdentifierList;
}


antlrcpp::Any pascalParser::VariableIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableIdentifierListContext* pascalParser::variableIdentifierList() {
  VariableIdentifierListContext *_localctx = _tracker.createInstance<VariableIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 56, pascalParser::RuleVariableIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    variableIdentifier();
    setState(347);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(343);
      match(pascalParser::T__3);
      setState(344);
      variableIdentifier();
      setState(349);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierContext ------------------------------------------------------------------

pascalParser::VariableIdentifierContext::VariableIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::VariableIdentifierContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}


size_t pascalParser::VariableIdentifierContext::getRuleIndex() const {
  return pascalParser::RuleVariableIdentifier;
}


antlrcpp::Any pascalParser::VariableIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableIdentifierContext* pascalParser::variableIdentifier() {
  VariableIdentifierContext *_localctx = _tracker.createInstance<VariableIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 58, pascalParser::RuleVariableIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    match(pascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutinesPartContext ------------------------------------------------------------------

pascalParser::RoutinesPartContext::RoutinesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::RoutineDefinitionContext *> pascalParser::RoutinesPartContext::routineDefinition() {
  return getRuleContexts<pascalParser::RoutineDefinitionContext>();
}

pascalParser::RoutineDefinitionContext* pascalParser::RoutinesPartContext::routineDefinition(size_t i) {
  return getRuleContext<pascalParser::RoutineDefinitionContext>(i);
}


size_t pascalParser::RoutinesPartContext::getRuleIndex() const {
  return pascalParser::RuleRoutinesPart;
}


antlrcpp::Any pascalParser::RoutinesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRoutinesPart(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RoutinesPartContext* pascalParser::routinesPart() {
  RoutinesPartContext *_localctx = _tracker.createInstance<RoutinesPartContext>(_ctx, getState());
  enterRule(_localctx, 60, pascalParser::RuleRoutinesPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(352);
    routineDefinition();
    setState(357);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(353);
        match(pascalParser::T__1);
        setState(354);
        routineDefinition(); 
      }
      setState(359);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineDefinitionContext ------------------------------------------------------------------

pascalParser::RoutineDefinitionContext::RoutineDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::BlockContext* pascalParser::RoutineDefinitionContext::block() {
  return getRuleContext<pascalParser::BlockContext>(0);
}

pascalParser::ProcedureHeadContext* pascalParser::RoutineDefinitionContext::procedureHead() {
  return getRuleContext<pascalParser::ProcedureHeadContext>(0);
}

pascalParser::FunctionHeadContext* pascalParser::RoutineDefinitionContext::functionHead() {
  return getRuleContext<pascalParser::FunctionHeadContext>(0);
}


size_t pascalParser::RoutineDefinitionContext::getRuleIndex() const {
  return pascalParser::RuleRoutineDefinition;
}


antlrcpp::Any pascalParser::RoutineDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRoutineDefinition(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RoutineDefinitionContext* pascalParser::routineDefinition() {
  RoutineDefinitionContext *_localctx = _tracker.createInstance<RoutineDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 62, pascalParser::RuleRoutineDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::PROCEDURE: {
        setState(360);
        procedureHead();
        break;
      }

      case pascalParser::FUNCTION: {
        setState(361);
        functionHead();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(364);
    match(pascalParser::T__1);
    setState(365);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureHeadContext ------------------------------------------------------------------

pascalParser::ProcedureHeadContext::ProcedureHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ProcedureHeadContext::PROCEDURE() {
  return getToken(pascalParser::PROCEDURE, 0);
}

pascalParser::RoutineIdentifierContext* pascalParser::ProcedureHeadContext::routineIdentifier() {
  return getRuleContext<pascalParser::RoutineIdentifierContext>(0);
}

pascalParser::ParametersContext* pascalParser::ProcedureHeadContext::parameters() {
  return getRuleContext<pascalParser::ParametersContext>(0);
}


size_t pascalParser::ProcedureHeadContext::getRuleIndex() const {
  return pascalParser::RuleProcedureHead;
}


antlrcpp::Any pascalParser::ProcedureHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProcedureHead(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProcedureHeadContext* pascalParser::procedureHead() {
  ProcedureHeadContext *_localctx = _tracker.createInstance<ProcedureHeadContext>(_ctx, getState());
  enterRule(_localctx, 64, pascalParser::RuleProcedureHead);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    match(pascalParser::PROCEDURE);
    setState(368);
    routineIdentifier();
    setState(370);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::T__2) {
      setState(369);
      parameters();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionHeadContext ------------------------------------------------------------------

pascalParser::FunctionHeadContext::FunctionHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::FunctionHeadContext::FUNCTION() {
  return getToken(pascalParser::FUNCTION, 0);
}

pascalParser::RoutineIdentifierContext* pascalParser::FunctionHeadContext::routineIdentifier() {
  return getRuleContext<pascalParser::RoutineIdentifierContext>(0);
}

pascalParser::TypeIdentifierContext* pascalParser::FunctionHeadContext::typeIdentifier() {
  return getRuleContext<pascalParser::TypeIdentifierContext>(0);
}

pascalParser::ParametersContext* pascalParser::FunctionHeadContext::parameters() {
  return getRuleContext<pascalParser::ParametersContext>(0);
}


size_t pascalParser::FunctionHeadContext::getRuleIndex() const {
  return pascalParser::RuleFunctionHead;
}


antlrcpp::Any pascalParser::FunctionHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFunctionHead(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FunctionHeadContext* pascalParser::functionHead() {
  FunctionHeadContext *_localctx = _tracker.createInstance<FunctionHeadContext>(_ctx, getState());
  enterRule(_localctx, 66, pascalParser::RuleFunctionHead);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    match(pascalParser::FUNCTION);
    setState(373);
    routineIdentifier();
    setState(375);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::T__2) {
      setState(374);
      parameters();
    }
    setState(377);
    match(pascalParser::T__11);
    setState(378);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineIdentifierContext ------------------------------------------------------------------

pascalParser::RoutineIdentifierContext::RoutineIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::RoutineIdentifierContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}


size_t pascalParser::RoutineIdentifierContext::getRuleIndex() const {
  return pascalParser::RuleRoutineIdentifier;
}


antlrcpp::Any pascalParser::RoutineIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRoutineIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RoutineIdentifierContext* pascalParser::routineIdentifier() {
  RoutineIdentifierContext *_localctx = _tracker.createInstance<RoutineIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 68, pascalParser::RuleRoutineIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(pascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

pascalParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ParameterDeclarationsListContext* pascalParser::ParametersContext::parameterDeclarationsList() {
  return getRuleContext<pascalParser::ParameterDeclarationsListContext>(0);
}


size_t pascalParser::ParametersContext::getRuleIndex() const {
  return pascalParser::RuleParameters;
}


antlrcpp::Any pascalParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParametersContext* pascalParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 70, pascalParser::RuleParameters);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    match(pascalParser::T__2);
    setState(383);
    parameterDeclarationsList();
    setState(384);
    match(pascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationsListContext ------------------------------------------------------------------

pascalParser::ParameterDeclarationsListContext::ParameterDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::ParameterDeclarationsContext *> pascalParser::ParameterDeclarationsListContext::parameterDeclarations() {
  return getRuleContexts<pascalParser::ParameterDeclarationsContext>();
}

pascalParser::ParameterDeclarationsContext* pascalParser::ParameterDeclarationsListContext::parameterDeclarations(size_t i) {
  return getRuleContext<pascalParser::ParameterDeclarationsContext>(i);
}


size_t pascalParser::ParameterDeclarationsListContext::getRuleIndex() const {
  return pascalParser::RuleParameterDeclarationsList;
}


antlrcpp::Any pascalParser::ParameterDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParameterDeclarationsListContext* pascalParser::parameterDeclarationsList() {
  ParameterDeclarationsListContext *_localctx = _tracker.createInstance<ParameterDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 72, pascalParser::RuleParameterDeclarationsList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    parameterDeclarations();
    setState(391);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__1) {
      setState(387);
      match(pascalParser::T__1);
      setState(388);
      parameterDeclarations();
      setState(393);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationsContext ------------------------------------------------------------------

pascalParser::ParameterDeclarationsContext::ParameterDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ParameterIdentifierListContext* pascalParser::ParameterDeclarationsContext::parameterIdentifierList() {
  return getRuleContext<pascalParser::ParameterIdentifierListContext>(0);
}

pascalParser::TypeIdentifierContext* pascalParser::ParameterDeclarationsContext::typeIdentifier() {
  return getRuleContext<pascalParser::TypeIdentifierContext>(0);
}

tree::TerminalNode* pascalParser::ParameterDeclarationsContext::VAR() {
  return getToken(pascalParser::VAR, 0);
}


size_t pascalParser::ParameterDeclarationsContext::getRuleIndex() const {
  return pascalParser::RuleParameterDeclarations;
}


antlrcpp::Any pascalParser::ParameterDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarations(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParameterDeclarationsContext* pascalParser::parameterDeclarations() {
  ParameterDeclarationsContext *_localctx = _tracker.createInstance<ParameterDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 74, pascalParser::RuleParameterDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::VAR) {
      setState(394);
      match(pascalParser::VAR);
    }
    setState(397);
    parameterIdentifierList();
    setState(398);
    match(pascalParser::T__11);
    setState(399);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdentifierListContext ------------------------------------------------------------------

pascalParser::ParameterIdentifierListContext::ParameterIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::ParameterIdentifierContext *> pascalParser::ParameterIdentifierListContext::parameterIdentifier() {
  return getRuleContexts<pascalParser::ParameterIdentifierContext>();
}

pascalParser::ParameterIdentifierContext* pascalParser::ParameterIdentifierListContext::parameterIdentifier(size_t i) {
  return getRuleContext<pascalParser::ParameterIdentifierContext>(i);
}


size_t pascalParser::ParameterIdentifierListContext::getRuleIndex() const {
  return pascalParser::RuleParameterIdentifierList;
}


antlrcpp::Any pascalParser::ParameterIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParameterIdentifierListContext* pascalParser::parameterIdentifierList() {
  ParameterIdentifierListContext *_localctx = _tracker.createInstance<ParameterIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 76, pascalParser::RuleParameterIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    parameterIdentifier();
    setState(406);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(402);
      match(pascalParser::T__3);
      setState(403);
      parameterIdentifier();
      setState(408);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdentifierContext ------------------------------------------------------------------

pascalParser::ParameterIdentifierContext::ParameterIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ParameterIdentifierContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}


size_t pascalParser::ParameterIdentifierContext::getRuleIndex() const {
  return pascalParser::RuleParameterIdentifier;
}


antlrcpp::Any pascalParser::ParameterIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParameterIdentifierContext* pascalParser::parameterIdentifier() {
  ParameterIdentifierContext *_localctx = _tracker.createInstance<ParameterIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 78, pascalParser::RuleParameterIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    match(pascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

pascalParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::CompoundStatementContext* pascalParser::StatementContext::compoundStatement() {
  return getRuleContext<pascalParser::CompoundStatementContext>(0);
}

pascalParser::AssignmentStatementContext* pascalParser::StatementContext::assignmentStatement() {
  return getRuleContext<pascalParser::AssignmentStatementContext>(0);
}

pascalParser::IfStatementContext* pascalParser::StatementContext::ifStatement() {
  return getRuleContext<pascalParser::IfStatementContext>(0);
}

pascalParser::CaseStatementContext* pascalParser::StatementContext::caseStatement() {
  return getRuleContext<pascalParser::CaseStatementContext>(0);
}

pascalParser::RepeatStatementContext* pascalParser::StatementContext::repeatStatement() {
  return getRuleContext<pascalParser::RepeatStatementContext>(0);
}

pascalParser::WhileStatementContext* pascalParser::StatementContext::whileStatement() {
  return getRuleContext<pascalParser::WhileStatementContext>(0);
}

pascalParser::ForStatementContext* pascalParser::StatementContext::forStatement() {
  return getRuleContext<pascalParser::ForStatementContext>(0);
}

pascalParser::WriteStatementContext* pascalParser::StatementContext::writeStatement() {
  return getRuleContext<pascalParser::WriteStatementContext>(0);
}

pascalParser::WritelnStatementContext* pascalParser::StatementContext::writelnStatement() {
  return getRuleContext<pascalParser::WritelnStatementContext>(0);
}

pascalParser::ReadStatementContext* pascalParser::StatementContext::readStatement() {
  return getRuleContext<pascalParser::ReadStatementContext>(0);
}

pascalParser::ReadlnStatementContext* pascalParser::StatementContext::readlnStatement() {
  return getRuleContext<pascalParser::ReadlnStatementContext>(0);
}

pascalParser::ProcedureCallStatementContext* pascalParser::StatementContext::procedureCallStatement() {
  return getRuleContext<pascalParser::ProcedureCallStatementContext>(0);
}

pascalParser::EmptyStatementContext* pascalParser::StatementContext::emptyStatement() {
  return getRuleContext<pascalParser::EmptyStatementContext>(0);
}


size_t pascalParser::StatementContext::getRuleIndex() const {
  return pascalParser::RuleStatement;
}


antlrcpp::Any pascalParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::StatementContext* pascalParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 80, pascalParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(424);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(411);
      compoundStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(412);
      assignmentStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(413);
      ifStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(414);
      caseStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(415);
      repeatStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(416);
      whileStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(417);
      forStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(418);
      writeStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(419);
      writelnStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(420);
      readStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(421);
      readlnStatement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(422);
      procedureCallStatement();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(423);
      emptyStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

pascalParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::CompoundStatementContext::BEGIN() {
  return getToken(pascalParser::BEGIN, 0);
}

pascalParser::StatementListContext* pascalParser::CompoundStatementContext::statementList() {
  return getRuleContext<pascalParser::StatementListContext>(0);
}

tree::TerminalNode* pascalParser::CompoundStatementContext::END() {
  return getToken(pascalParser::END, 0);
}


size_t pascalParser::CompoundStatementContext::getRuleIndex() const {
  return pascalParser::RuleCompoundStatement;
}


antlrcpp::Any pascalParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CompoundStatementContext* pascalParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, pascalParser::RuleCompoundStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
    match(pascalParser::BEGIN);
    setState(427);
    statementList();
    setState(428);
    match(pascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

pascalParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pascalParser::EmptyStatementContext::getRuleIndex() const {
  return pascalParser::RuleEmptyStatement;
}


antlrcpp::Any pascalParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::EmptyStatementContext* pascalParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, pascalParser::RuleEmptyStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

pascalParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::StatementContext *> pascalParser::StatementListContext::statement() {
  return getRuleContexts<pascalParser::StatementContext>();
}

pascalParser::StatementContext* pascalParser::StatementListContext::statement(size_t i) {
  return getRuleContext<pascalParser::StatementContext>(i);
}


size_t pascalParser::StatementListContext::getRuleIndex() const {
  return pascalParser::RuleStatementList;
}


antlrcpp::Any pascalParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::StatementListContext* pascalParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 86, pascalParser::RuleStatementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    statement();
    setState(437);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__1) {
      setState(433);
      match(pascalParser::T__1);
      setState(434);
      statement();
      setState(439);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

pascalParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::LhsContext* pascalParser::AssignmentStatementContext::lhs() {
  return getRuleContext<pascalParser::LhsContext>(0);
}

pascalParser::RhsContext* pascalParser::AssignmentStatementContext::rhs() {
  return getRuleContext<pascalParser::RhsContext>(0);
}


size_t pascalParser::AssignmentStatementContext::getRuleIndex() const {
  return pascalParser::RuleAssignmentStatement;
}


antlrcpp::Any pascalParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::AssignmentStatementContext* pascalParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 88, pascalParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    lhs();
    setState(441);
    match(pascalParser::T__12);
    setState(442);
    rhs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

pascalParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::VariableContext* pascalParser::LhsContext::variable() {
  return getRuleContext<pascalParser::VariableContext>(0);
}


size_t pascalParser::LhsContext::getRuleIndex() const {
  return pascalParser::RuleLhs;
}


antlrcpp::Any pascalParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::LhsContext* pascalParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 90, pascalParser::RuleLhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsContext ------------------------------------------------------------------

pascalParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ExpressionContext* pascalParser::RhsContext::expression() {
  return getRuleContext<pascalParser::ExpressionContext>(0);
}


size_t pascalParser::RhsContext::getRuleIndex() const {
  return pascalParser::RuleRhs;
}


antlrcpp::Any pascalParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RhsContext* pascalParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 92, pascalParser::RuleRhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(446);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

pascalParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::IfStatementContext::IF() {
  return getToken(pascalParser::IF, 0);
}

pascalParser::ExpressionContext* pascalParser::IfStatementContext::expression() {
  return getRuleContext<pascalParser::ExpressionContext>(0);
}

tree::TerminalNode* pascalParser::IfStatementContext::THEN() {
  return getToken(pascalParser::THEN, 0);
}

pascalParser::TrueStatementContext* pascalParser::IfStatementContext::trueStatement() {
  return getRuleContext<pascalParser::TrueStatementContext>(0);
}

tree::TerminalNode* pascalParser::IfStatementContext::ELSE() {
  return getToken(pascalParser::ELSE, 0);
}

pascalParser::FalseStatementContext* pascalParser::IfStatementContext::falseStatement() {
  return getRuleContext<pascalParser::FalseStatementContext>(0);
}


size_t pascalParser::IfStatementContext::getRuleIndex() const {
  return pascalParser::RuleIfStatement;
}


antlrcpp::Any pascalParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::IfStatementContext* pascalParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 94, pascalParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(448);
    match(pascalParser::IF);
    setState(449);
    expression();
    setState(450);
    match(pascalParser::THEN);
    setState(451);
    trueStatement();
    setState(454);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(452);
      match(pascalParser::ELSE);
      setState(453);
      falseStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TrueStatementContext ------------------------------------------------------------------

pascalParser::TrueStatementContext::TrueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::StatementContext* pascalParser::TrueStatementContext::statement() {
  return getRuleContext<pascalParser::StatementContext>(0);
}


size_t pascalParser::TrueStatementContext::getRuleIndex() const {
  return pascalParser::RuleTrueStatement;
}


antlrcpp::Any pascalParser::TrueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTrueStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TrueStatementContext* pascalParser::trueStatement() {
  TrueStatementContext *_localctx = _tracker.createInstance<TrueStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, pascalParser::RuleTrueStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(456);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FalseStatementContext ------------------------------------------------------------------

pascalParser::FalseStatementContext::FalseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::StatementContext* pascalParser::FalseStatementContext::statement() {
  return getRuleContext<pascalParser::StatementContext>(0);
}


size_t pascalParser::FalseStatementContext::getRuleIndex() const {
  return pascalParser::RuleFalseStatement;
}


antlrcpp::Any pascalParser::FalseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFalseStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FalseStatementContext* pascalParser::falseStatement() {
  FalseStatementContext *_localctx = _tracker.createInstance<FalseStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, pascalParser::RuleFalseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

pascalParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::CaseStatementContext::CASE() {
  return getToken(pascalParser::CASE, 0);
}

pascalParser::ExpressionContext* pascalParser::CaseStatementContext::expression() {
  return getRuleContext<pascalParser::ExpressionContext>(0);
}

tree::TerminalNode* pascalParser::CaseStatementContext::OF() {
  return getToken(pascalParser::OF, 0);
}

pascalParser::CaseBranchListContext* pascalParser::CaseStatementContext::caseBranchList() {
  return getRuleContext<pascalParser::CaseBranchListContext>(0);
}

tree::TerminalNode* pascalParser::CaseStatementContext::END() {
  return getToken(pascalParser::END, 0);
}


size_t pascalParser::CaseStatementContext::getRuleIndex() const {
  return pascalParser::RuleCaseStatement;
}


antlrcpp::Any pascalParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseStatementContext* pascalParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 100, pascalParser::RuleCaseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    match(pascalParser::CASE);
    setState(461);
    expression();
    setState(462);
    match(pascalParser::OF);
    setState(463);
    caseBranchList();
    setState(464);
    match(pascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBranchListContext ------------------------------------------------------------------

pascalParser::CaseBranchListContext::CaseBranchListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::CaseBranchContext *> pascalParser::CaseBranchListContext::caseBranch() {
  return getRuleContexts<pascalParser::CaseBranchContext>();
}

pascalParser::CaseBranchContext* pascalParser::CaseBranchListContext::caseBranch(size_t i) {
  return getRuleContext<pascalParser::CaseBranchContext>(i);
}


size_t pascalParser::CaseBranchListContext::getRuleIndex() const {
  return pascalParser::RuleCaseBranchList;
}


antlrcpp::Any pascalParser::CaseBranchListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseBranchList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseBranchListContext* pascalParser::caseBranchList() {
  CaseBranchListContext *_localctx = _tracker.createInstance<CaseBranchListContext>(_ctx, getState());
  enterRule(_localctx, 102, pascalParser::RuleCaseBranchList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(466);
    caseBranch();
    setState(471);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__1) {
      setState(467);
      match(pascalParser::T__1);
      setState(468);
      caseBranch();
      setState(473);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBranchContext ------------------------------------------------------------------

pascalParser::CaseBranchContext::CaseBranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::CaseConstantListContext* pascalParser::CaseBranchContext::caseConstantList() {
  return getRuleContext<pascalParser::CaseConstantListContext>(0);
}

pascalParser::StatementContext* pascalParser::CaseBranchContext::statement() {
  return getRuleContext<pascalParser::StatementContext>(0);
}


size_t pascalParser::CaseBranchContext::getRuleIndex() const {
  return pascalParser::RuleCaseBranch;
}


antlrcpp::Any pascalParser::CaseBranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseBranch(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseBranchContext* pascalParser::caseBranch() {
  CaseBranchContext *_localctx = _tracker.createInstance<CaseBranchContext>(_ctx, getState());
  enterRule(_localctx, 104, pascalParser::RuleCaseBranch);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(479);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::T__6:
      case pascalParser::T__7:
      case pascalParser::IDENTIFIER:
      case pascalParser::INTEGER:
      case pascalParser::REAL:
      case pascalParser::CHARACTER:
      case pascalParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(474);
        caseConstantList();
        setState(475);
        match(pascalParser::T__11);
        setState(476);
        statement();
        break;
      }

      case pascalParser::T__1:
      case pascalParser::END: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseConstantListContext ------------------------------------------------------------------

pascalParser::CaseConstantListContext::CaseConstantListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::CaseConstantContext *> pascalParser::CaseConstantListContext::caseConstant() {
  return getRuleContexts<pascalParser::CaseConstantContext>();
}

pascalParser::CaseConstantContext* pascalParser::CaseConstantListContext::caseConstant(size_t i) {
  return getRuleContext<pascalParser::CaseConstantContext>(i);
}


size_t pascalParser::CaseConstantListContext::getRuleIndex() const {
  return pascalParser::RuleCaseConstantList;
}


antlrcpp::Any pascalParser::CaseConstantListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseConstantList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseConstantListContext* pascalParser::caseConstantList() {
  CaseConstantListContext *_localctx = _tracker.createInstance<CaseConstantListContext>(_ctx, getState());
  enterRule(_localctx, 106, pascalParser::RuleCaseConstantList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(481);
    caseConstant();
    setState(486);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(482);
      match(pascalParser::T__3);
      setState(483);
      caseConstant();
      setState(488);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseConstantContext ------------------------------------------------------------------

pascalParser::CaseConstantContext::CaseConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ConstantContext* pascalParser::CaseConstantContext::constant() {
  return getRuleContext<pascalParser::ConstantContext>(0);
}


size_t pascalParser::CaseConstantContext::getRuleIndex() const {
  return pascalParser::RuleCaseConstant;
}


antlrcpp::Any pascalParser::CaseConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseConstantContext* pascalParser::caseConstant() {
  CaseConstantContext *_localctx = _tracker.createInstance<CaseConstantContext>(_ctx, getState());
  enterRule(_localctx, 108, pascalParser::RuleCaseConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(489);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RepeatStatementContext ------------------------------------------------------------------

pascalParser::RepeatStatementContext::RepeatStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::RepeatStatementContext::REPEAT() {
  return getToken(pascalParser::REPEAT, 0);
}

pascalParser::StatementListContext* pascalParser::RepeatStatementContext::statementList() {
  return getRuleContext<pascalParser::StatementListContext>(0);
}

tree::TerminalNode* pascalParser::RepeatStatementContext::UNTIL() {
  return getToken(pascalParser::UNTIL, 0);
}

pascalParser::ExpressionContext* pascalParser::RepeatStatementContext::expression() {
  return getRuleContext<pascalParser::ExpressionContext>(0);
}


size_t pascalParser::RepeatStatementContext::getRuleIndex() const {
  return pascalParser::RuleRepeatStatement;
}


antlrcpp::Any pascalParser::RepeatStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRepeatStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RepeatStatementContext* pascalParser::repeatStatement() {
  RepeatStatementContext *_localctx = _tracker.createInstance<RepeatStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, pascalParser::RuleRepeatStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(491);
    match(pascalParser::REPEAT);
    setState(492);
    statementList();
    setState(493);
    match(pascalParser::UNTIL);
    setState(494);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

pascalParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::WhileStatementContext::WHILE() {
  return getToken(pascalParser::WHILE, 0);
}

pascalParser::ExpressionContext* pascalParser::WhileStatementContext::expression() {
  return getRuleContext<pascalParser::ExpressionContext>(0);
}

tree::TerminalNode* pascalParser::WhileStatementContext::DO() {
  return getToken(pascalParser::DO, 0);
}

pascalParser::StatementContext* pascalParser::WhileStatementContext::statement() {
  return getRuleContext<pascalParser::StatementContext>(0);
}


size_t pascalParser::WhileStatementContext::getRuleIndex() const {
  return pascalParser::RuleWhileStatement;
}


antlrcpp::Any pascalParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WhileStatementContext* pascalParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 112, pascalParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    match(pascalParser::WHILE);
    setState(497);
    expression();
    setState(498);
    match(pascalParser::DO);
    setState(499);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

pascalParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ForStatementContext::FOR() {
  return getToken(pascalParser::FOR, 0);
}

pascalParser::VariableContext* pascalParser::ForStatementContext::variable() {
  return getRuleContext<pascalParser::VariableContext>(0);
}

std::vector<pascalParser::ExpressionContext *> pascalParser::ForStatementContext::expression() {
  return getRuleContexts<pascalParser::ExpressionContext>();
}

pascalParser::ExpressionContext* pascalParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<pascalParser::ExpressionContext>(i);
}

tree::TerminalNode* pascalParser::ForStatementContext::DO() {
  return getToken(pascalParser::DO, 0);
}

pascalParser::StatementContext* pascalParser::ForStatementContext::statement() {
  return getRuleContext<pascalParser::StatementContext>(0);
}

tree::TerminalNode* pascalParser::ForStatementContext::TO() {
  return getToken(pascalParser::TO, 0);
}

tree::TerminalNode* pascalParser::ForStatementContext::DOWNTO() {
  return getToken(pascalParser::DOWNTO, 0);
}


size_t pascalParser::ForStatementContext::getRuleIndex() const {
  return pascalParser::RuleForStatement;
}


antlrcpp::Any pascalParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ForStatementContext* pascalParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, pascalParser::RuleForStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    match(pascalParser::FOR);
    setState(502);
    variable();
    setState(503);
    match(pascalParser::T__12);
    setState(504);
    expression();
    setState(505);
    _la = _input->LA(1);
    if (!(_la == pascalParser::TO

    || _la == pascalParser::DOWNTO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(506);
    expression();
    setState(507);
    match(pascalParser::DO);
    setState(508);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureCallStatementContext ------------------------------------------------------------------

pascalParser::ProcedureCallStatementContext::ProcedureCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ProcedureNameContext* pascalParser::ProcedureCallStatementContext::procedureName() {
  return getRuleContext<pascalParser::ProcedureNameContext>(0);
}

pascalParser::ArgumentListContext* pascalParser::ProcedureCallStatementContext::argumentList() {
  return getRuleContext<pascalParser::ArgumentListContext>(0);
}


size_t pascalParser::ProcedureCallStatementContext::getRuleIndex() const {
  return pascalParser::RuleProcedureCallStatement;
}


antlrcpp::Any pascalParser::ProcedureCallStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProcedureCallStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProcedureCallStatementContext* pascalParser::procedureCallStatement() {
  ProcedureCallStatementContext *_localctx = _tracker.createInstance<ProcedureCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 116, pascalParser::RuleProcedureCallStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(510);
    procedureName();
    setState(511);
    match(pascalParser::T__2);
    setState(513);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pascalParser::T__2)
      | (1ULL << pascalParser::T__6)
      | (1ULL << pascalParser::T__7)
      | (1ULL << pascalParser::NOT)
      | (1ULL << pascalParser::IDENTIFIER)
      | (1ULL << pascalParser::INTEGER)
      | (1ULL << pascalParser::REAL)
      | (1ULL << pascalParser::CHARACTER)
      | (1ULL << pascalParser::STRING))) != 0)) {
      setState(512);
      argumentList();
    }
    setState(515);
    match(pascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureNameContext ------------------------------------------------------------------

pascalParser::ProcedureNameContext::ProcedureNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ProcedureNameContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}


size_t pascalParser::ProcedureNameContext::getRuleIndex() const {
  return pascalParser::RuleProcedureName;
}


antlrcpp::Any pascalParser::ProcedureNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProcedureName(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProcedureNameContext* pascalParser::procedureName() {
  ProcedureNameContext *_localctx = _tracker.createInstance<ProcedureNameContext>(_ctx, getState());
  enterRule(_localctx, 118, pascalParser::RuleProcedureName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    match(pascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

pascalParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::ArgumentContext *> pascalParser::ArgumentListContext::argument() {
  return getRuleContexts<pascalParser::ArgumentContext>();
}

pascalParser::ArgumentContext* pascalParser::ArgumentListContext::argument(size_t i) {
  return getRuleContext<pascalParser::ArgumentContext>(i);
}


size_t pascalParser::ArgumentListContext::getRuleIndex() const {
  return pascalParser::RuleArgumentList;
}


antlrcpp::Any pascalParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ArgumentListContext* pascalParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 120, pascalParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(519);
    argument();
    setState(524);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(520);
      match(pascalParser::T__3);
      setState(521);
      argument();
      setState(526);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

pascalParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ExpressionContext* pascalParser::ArgumentContext::expression() {
  return getRuleContext<pascalParser::ExpressionContext>(0);
}


size_t pascalParser::ArgumentContext::getRuleIndex() const {
  return pascalParser::RuleArgument;
}


antlrcpp::Any pascalParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ArgumentContext* pascalParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 122, pascalParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(527);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteStatementContext ------------------------------------------------------------------

pascalParser::WriteStatementContext::WriteStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::WriteStatementContext::WRITE() {
  return getToken(pascalParser::WRITE, 0);
}

pascalParser::WriteArgumentsContext* pascalParser::WriteStatementContext::writeArguments() {
  return getRuleContext<pascalParser::WriteArgumentsContext>(0);
}


size_t pascalParser::WriteStatementContext::getRuleIndex() const {
  return pascalParser::RuleWriteStatement;
}


antlrcpp::Any pascalParser::WriteStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWriteStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WriteStatementContext* pascalParser::writeStatement() {
  WriteStatementContext *_localctx = _tracker.createInstance<WriteStatementContext>(_ctx, getState());
  enterRule(_localctx, 124, pascalParser::RuleWriteStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    match(pascalParser::WRITE);
    setState(530);
    writeArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WritelnStatementContext ------------------------------------------------------------------

pascalParser::WritelnStatementContext::WritelnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::WritelnStatementContext::WRITELN() {
  return getToken(pascalParser::WRITELN, 0);
}

pascalParser::WriteArgumentsContext* pascalParser::WritelnStatementContext::writeArguments() {
  return getRuleContext<pascalParser::WriteArgumentsContext>(0);
}


size_t pascalParser::WritelnStatementContext::getRuleIndex() const {
  return pascalParser::RuleWritelnStatement;
}


antlrcpp::Any pascalParser::WritelnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWritelnStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WritelnStatementContext* pascalParser::writelnStatement() {
  WritelnStatementContext *_localctx = _tracker.createInstance<WritelnStatementContext>(_ctx, getState());
  enterRule(_localctx, 126, pascalParser::RuleWritelnStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(532);
    match(pascalParser::WRITELN);
    setState(534);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::T__2) {
      setState(533);
      writeArguments();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteArgumentsContext ------------------------------------------------------------------

pascalParser::WriteArgumentsContext::WriteArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::WriteArgumentContext *> pascalParser::WriteArgumentsContext::writeArgument() {
  return getRuleContexts<pascalParser::WriteArgumentContext>();
}

pascalParser::WriteArgumentContext* pascalParser::WriteArgumentsContext::writeArgument(size_t i) {
  return getRuleContext<pascalParser::WriteArgumentContext>(i);
}


size_t pascalParser::WriteArgumentsContext::getRuleIndex() const {
  return pascalParser::RuleWriteArguments;
}


antlrcpp::Any pascalParser::WriteArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWriteArguments(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WriteArgumentsContext* pascalParser::writeArguments() {
  WriteArgumentsContext *_localctx = _tracker.createInstance<WriteArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 128, pascalParser::RuleWriteArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(536);
    match(pascalParser::T__2);
    setState(537);
    writeArgument();
    setState(542);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(538);
      match(pascalParser::T__3);
      setState(539);
      writeArgument();
      setState(544);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(545);
    match(pascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteArgumentContext ------------------------------------------------------------------

pascalParser::WriteArgumentContext::WriteArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ExpressionContext* pascalParser::WriteArgumentContext::expression() {
  return getRuleContext<pascalParser::ExpressionContext>(0);
}

pascalParser::FieldWidthContext* pascalParser::WriteArgumentContext::fieldWidth() {
  return getRuleContext<pascalParser::FieldWidthContext>(0);
}


size_t pascalParser::WriteArgumentContext::getRuleIndex() const {
  return pascalParser::RuleWriteArgument;
}


antlrcpp::Any pascalParser::WriteArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWriteArgument(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WriteArgumentContext* pascalParser::writeArgument() {
  WriteArgumentContext *_localctx = _tracker.createInstance<WriteArgumentContext>(_ctx, getState());
  enterRule(_localctx, 130, pascalParser::RuleWriteArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(547);
    expression();
    setState(550);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::T__11) {
      setState(548);
      match(pascalParser::T__11);
      setState(549);
      fieldWidth();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldWidthContext ------------------------------------------------------------------

pascalParser::FieldWidthContext::FieldWidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::IntegerConstantContext* pascalParser::FieldWidthContext::integerConstant() {
  return getRuleContext<pascalParser::IntegerConstantContext>(0);
}

pascalParser::SignContext* pascalParser::FieldWidthContext::sign() {
  return getRuleContext<pascalParser::SignContext>(0);
}

pascalParser::DecimalPlacesContext* pascalParser::FieldWidthContext::decimalPlaces() {
  return getRuleContext<pascalParser::DecimalPlacesContext>(0);
}


size_t pascalParser::FieldWidthContext::getRuleIndex() const {
  return pascalParser::RuleFieldWidth;
}


antlrcpp::Any pascalParser::FieldWidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFieldWidth(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FieldWidthContext* pascalParser::fieldWidth() {
  FieldWidthContext *_localctx = _tracker.createInstance<FieldWidthContext>(_ctx, getState());
  enterRule(_localctx, 132, pascalParser::RuleFieldWidth);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(553);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::T__6

    || _la == pascalParser::T__7) {
      setState(552);
      sign();
    }
    setState(555);
    integerConstant();
    setState(558);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::T__11) {
      setState(556);
      match(pascalParser::T__11);
      setState(557);
      decimalPlaces();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecimalPlacesContext ------------------------------------------------------------------

pascalParser::DecimalPlacesContext::DecimalPlacesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::IntegerConstantContext* pascalParser::DecimalPlacesContext::integerConstant() {
  return getRuleContext<pascalParser::IntegerConstantContext>(0);
}


size_t pascalParser::DecimalPlacesContext::getRuleIndex() const {
  return pascalParser::RuleDecimalPlaces;
}


antlrcpp::Any pascalParser::DecimalPlacesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitDecimalPlaces(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::DecimalPlacesContext* pascalParser::decimalPlaces() {
  DecimalPlacesContext *_localctx = _tracker.createInstance<DecimalPlacesContext>(_ctx, getState());
  enterRule(_localctx, 134, pascalParser::RuleDecimalPlaces);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(560);
    integerConstant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadStatementContext ------------------------------------------------------------------

pascalParser::ReadStatementContext::ReadStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ReadStatementContext::READ() {
  return getToken(pascalParser::READ, 0);
}

pascalParser::ReadArgumentsContext* pascalParser::ReadStatementContext::readArguments() {
  return getRuleContext<pascalParser::ReadArgumentsContext>(0);
}


size_t pascalParser::ReadStatementContext::getRuleIndex() const {
  return pascalParser::RuleReadStatement;
}


antlrcpp::Any pascalParser::ReadStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitReadStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ReadStatementContext* pascalParser::readStatement() {
  ReadStatementContext *_localctx = _tracker.createInstance<ReadStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, pascalParser::RuleReadStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(562);
    match(pascalParser::READ);
    setState(563);
    readArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadlnStatementContext ------------------------------------------------------------------

pascalParser::ReadlnStatementContext::ReadlnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ReadlnStatementContext::READLN() {
  return getToken(pascalParser::READLN, 0);
}

pascalParser::ReadArgumentsContext* pascalParser::ReadlnStatementContext::readArguments() {
  return getRuleContext<pascalParser::ReadArgumentsContext>(0);
}


size_t pascalParser::ReadlnStatementContext::getRuleIndex() const {
  return pascalParser::RuleReadlnStatement;
}


antlrcpp::Any pascalParser::ReadlnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitReadlnStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ReadlnStatementContext* pascalParser::readlnStatement() {
  ReadlnStatementContext *_localctx = _tracker.createInstance<ReadlnStatementContext>(_ctx, getState());
  enterRule(_localctx, 138, pascalParser::RuleReadlnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    match(pascalParser::READLN);
    setState(566);
    readArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadArgumentsContext ------------------------------------------------------------------

pascalParser::ReadArgumentsContext::ReadArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::VariableContext *> pascalParser::ReadArgumentsContext::variable() {
  return getRuleContexts<pascalParser::VariableContext>();
}

pascalParser::VariableContext* pascalParser::ReadArgumentsContext::variable(size_t i) {
  return getRuleContext<pascalParser::VariableContext>(i);
}


size_t pascalParser::ReadArgumentsContext::getRuleIndex() const {
  return pascalParser::RuleReadArguments;
}


antlrcpp::Any pascalParser::ReadArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitReadArguments(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ReadArgumentsContext* pascalParser::readArguments() {
  ReadArgumentsContext *_localctx = _tracker.createInstance<ReadArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 140, pascalParser::RuleReadArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(568);
    match(pascalParser::T__2);
    setState(569);
    variable();
    setState(574);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(570);
      match(pascalParser::T__3);
      setState(571);
      variable();
      setState(576);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(577);
    match(pascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

pascalParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::SimpleExpressionContext *> pascalParser::ExpressionContext::simpleExpression() {
  return getRuleContexts<pascalParser::SimpleExpressionContext>();
}

pascalParser::SimpleExpressionContext* pascalParser::ExpressionContext::simpleExpression(size_t i) {
  return getRuleContext<pascalParser::SimpleExpressionContext>(i);
}

pascalParser::RelOpContext* pascalParser::ExpressionContext::relOp() {
  return getRuleContext<pascalParser::RelOpContext>(0);
}


size_t pascalParser::ExpressionContext::getRuleIndex() const {
  return pascalParser::RuleExpression;
}


antlrcpp::Any pascalParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ExpressionContext* pascalParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 142, pascalParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(579);
    simpleExpression();
    setState(583);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pascalParser::T__5)
      | (1ULL << pascalParser::T__13)
      | (1ULL << pascalParser::T__14)
      | (1ULL << pascalParser::T__15)
      | (1ULL << pascalParser::T__16)
      | (1ULL << pascalParser::T__17))) != 0)) {
      setState(580);
      relOp();
      setState(581);
      simpleExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

pascalParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::TermContext *> pascalParser::SimpleExpressionContext::term() {
  return getRuleContexts<pascalParser::TermContext>();
}

pascalParser::TermContext* pascalParser::SimpleExpressionContext::term(size_t i) {
  return getRuleContext<pascalParser::TermContext>(i);
}

pascalParser::SignContext* pascalParser::SimpleExpressionContext::sign() {
  return getRuleContext<pascalParser::SignContext>(0);
}

std::vector<pascalParser::AddOpContext *> pascalParser::SimpleExpressionContext::addOp() {
  return getRuleContexts<pascalParser::AddOpContext>();
}

pascalParser::AddOpContext* pascalParser::SimpleExpressionContext::addOp(size_t i) {
  return getRuleContext<pascalParser::AddOpContext>(i);
}


size_t pascalParser::SimpleExpressionContext::getRuleIndex() const {
  return pascalParser::RuleSimpleExpression;
}


antlrcpp::Any pascalParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::SimpleExpressionContext* pascalParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 144, pascalParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(586);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(585);
      sign();
      break;
    }

    }
    setState(588);
    term();
    setState(594);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pascalParser::T__6)
      | (1ULL << pascalParser::T__7)
      | (1ULL << pascalParser::OR))) != 0)) {
      setState(589);
      addOp();
      setState(590);
      term();
      setState(596);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

pascalParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::FactorContext *> pascalParser::TermContext::factor() {
  return getRuleContexts<pascalParser::FactorContext>();
}

pascalParser::FactorContext* pascalParser::TermContext::factor(size_t i) {
  return getRuleContext<pascalParser::FactorContext>(i);
}

std::vector<pascalParser::MulOpContext *> pascalParser::TermContext::mulOp() {
  return getRuleContexts<pascalParser::MulOpContext>();
}

pascalParser::MulOpContext* pascalParser::TermContext::mulOp(size_t i) {
  return getRuleContext<pascalParser::MulOpContext>(i);
}


size_t pascalParser::TermContext::getRuleIndex() const {
  return pascalParser::RuleTerm;
}


antlrcpp::Any pascalParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TermContext* pascalParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 146, pascalParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(597);
    factor();
    setState(603);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pascalParser::T__18)
      | (1ULL << pascalParser::T__19)
      | (1ULL << pascalParser::DIV)
      | (1ULL << pascalParser::MOD)
      | (1ULL << pascalParser::AND))) != 0)) {
      setState(598);
      mulOp();
      setState(599);
      factor();
      setState(605);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

pascalParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pascalParser::FactorContext::getRuleIndex() const {
  return pascalParser::RuleFactor;
}

void pascalParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- NumberFactorContext ------------------------------------------------------------------

pascalParser::NumberContext* pascalParser::NumberFactorContext::number() {
  return getRuleContext<pascalParser::NumberContext>(0);
}

pascalParser::NumberFactorContext::NumberFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::NumberFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitNumberFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringFactorContext ------------------------------------------------------------------

pascalParser::StringConstantContext* pascalParser::StringFactorContext::stringConstant() {
  return getRuleContext<pascalParser::StringConstantContext>(0);
}

pascalParser::StringFactorContext::StringFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::StringFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitStringFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharacterFactorContext ------------------------------------------------------------------

pascalParser::CharacterConstantContext* pascalParser::CharacterFactorContext::characterConstant() {
  return getRuleContext<pascalParser::CharacterConstantContext>(0);
}

pascalParser::CharacterFactorContext::CharacterFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::CharacterFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCharacterFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableFactorContext ------------------------------------------------------------------

pascalParser::VariableContext* pascalParser::VariableFactorContext::variable() {
  return getRuleContext<pascalParser::VariableContext>(0);
}

pascalParser::VariableFactorContext::VariableFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::VariableFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariableFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallFactorContext ------------------------------------------------------------------

pascalParser::FunctionCallContext* pascalParser::FunctionCallFactorContext::functionCall() {
  return getRuleContext<pascalParser::FunctionCallContext>(0);
}

pascalParser::FunctionCallFactorContext::FunctionCallFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::FunctionCallFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFunctionCallFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotFactorContext ------------------------------------------------------------------

tree::TerminalNode* pascalParser::NotFactorContext::NOT() {
  return getToken(pascalParser::NOT, 0);
}

pascalParser::FactorContext* pascalParser::NotFactorContext::factor() {
  return getRuleContext<pascalParser::FactorContext>(0);
}

pascalParser::NotFactorContext::NotFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::NotFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitNotFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedFactorContext ------------------------------------------------------------------

pascalParser::ExpressionContext* pascalParser::ParenthesizedFactorContext::expression() {
  return getRuleContext<pascalParser::ExpressionContext>(0);
}

pascalParser::ParenthesizedFactorContext::ParenthesizedFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any pascalParser::ParenthesizedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParenthesizedFactor(this);
  else
    return visitor->visitChildren(this);
}
pascalParser::FactorContext* pascalParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 148, pascalParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(617);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<pascalParser::VariableFactorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(606);
      variable();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<pascalParser::NumberFactorContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(607);
      number();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<pascalParser::CharacterFactorContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(608);
      characterConstant();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<pascalParser::StringFactorContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(609);
      stringConstant();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<pascalParser::FunctionCallFactorContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(610);
      functionCall();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<pascalParser::NotFactorContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(611);
      match(pascalParser::NOT);
      setState(612);
      factor();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<pascalParser::ParenthesizedFactorContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(613);
      match(pascalParser::T__2);
      setState(614);
      expression();
      setState(615);
      match(pascalParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

pascalParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::VariableIdentifierContext* pascalParser::VariableContext::variableIdentifier() {
  return getRuleContext<pascalParser::VariableIdentifierContext>(0);
}

std::vector<pascalParser::ModifierContext *> pascalParser::VariableContext::modifier() {
  return getRuleContexts<pascalParser::ModifierContext>();
}

pascalParser::ModifierContext* pascalParser::VariableContext::modifier(size_t i) {
  return getRuleContext<pascalParser::ModifierContext>(i);
}


size_t pascalParser::VariableContext::getRuleIndex() const {
  return pascalParser::RuleVariable;
}


antlrcpp::Any pascalParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableContext* pascalParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 150, pascalParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619);
    variableIdentifier();
    setState(623);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__0

    || _la == pascalParser::T__9) {
      setState(620);
      modifier();
      setState(625);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierContext ------------------------------------------------------------------

pascalParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::IndexListContext* pascalParser::ModifierContext::indexList() {
  return getRuleContext<pascalParser::IndexListContext>(0);
}

pascalParser::FieldContext* pascalParser::ModifierContext::field() {
  return getRuleContext<pascalParser::FieldContext>(0);
}


size_t pascalParser::ModifierContext::getRuleIndex() const {
  return pascalParser::RuleModifier;
}


antlrcpp::Any pascalParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ModifierContext* pascalParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 152, pascalParser::RuleModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(632);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(626);
        match(pascalParser::T__9);
        setState(627);
        indexList();
        setState(628);
        match(pascalParser::T__10);
        break;
      }

      case pascalParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(630);
        match(pascalParser::T__0);
        setState(631);
        field();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexListContext ------------------------------------------------------------------

pascalParser::IndexListContext::IndexListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::IndexContext *> pascalParser::IndexListContext::index() {
  return getRuleContexts<pascalParser::IndexContext>();
}

pascalParser::IndexContext* pascalParser::IndexListContext::index(size_t i) {
  return getRuleContext<pascalParser::IndexContext>(i);
}


size_t pascalParser::IndexListContext::getRuleIndex() const {
  return pascalParser::RuleIndexList;
}


antlrcpp::Any pascalParser::IndexListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitIndexList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::IndexListContext* pascalParser::indexList() {
  IndexListContext *_localctx = _tracker.createInstance<IndexListContext>(_ctx, getState());
  enterRule(_localctx, 154, pascalParser::RuleIndexList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    index();
    setState(639);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pascalParser::T__3) {
      setState(635);
      match(pascalParser::T__3);
      setState(636);
      index();
      setState(641);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

pascalParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ExpressionContext* pascalParser::IndexContext::expression() {
  return getRuleContext<pascalParser::ExpressionContext>(0);
}


size_t pascalParser::IndexContext::getRuleIndex() const {
  return pascalParser::RuleIndex;
}


antlrcpp::Any pascalParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::IndexContext* pascalParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 156, pascalParser::RuleIndex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(642);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

pascalParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::FieldContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}


size_t pascalParser::FieldContext::getRuleIndex() const {
  return pascalParser::RuleField;
}


antlrcpp::Any pascalParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FieldContext* pascalParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 158, pascalParser::RuleField);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(644);
    match(pascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

pascalParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::FunctionNameContext* pascalParser::FunctionCallContext::functionName() {
  return getRuleContext<pascalParser::FunctionNameContext>(0);
}

pascalParser::ArgumentListContext* pascalParser::FunctionCallContext::argumentList() {
  return getRuleContext<pascalParser::ArgumentListContext>(0);
}


size_t pascalParser::FunctionCallContext::getRuleIndex() const {
  return pascalParser::RuleFunctionCall;
}


antlrcpp::Any pascalParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FunctionCallContext* pascalParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 160, pascalParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(646);
    functionName();
    setState(647);
    match(pascalParser::T__2);
    setState(649);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pascalParser::T__2)
      | (1ULL << pascalParser::T__6)
      | (1ULL << pascalParser::T__7)
      | (1ULL << pascalParser::NOT)
      | (1ULL << pascalParser::IDENTIFIER)
      | (1ULL << pascalParser::INTEGER)
      | (1ULL << pascalParser::REAL)
      | (1ULL << pascalParser::CHARACTER)
      | (1ULL << pascalParser::STRING))) != 0)) {
      setState(648);
      argumentList();
    }
    setState(651);
    match(pascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

pascalParser::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::FunctionNameContext::IDENTIFIER() {
  return getToken(pascalParser::IDENTIFIER, 0);
}


size_t pascalParser::FunctionNameContext::getRuleIndex() const {
  return pascalParser::RuleFunctionName;
}


antlrcpp::Any pascalParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FunctionNameContext* pascalParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 162, pascalParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
    match(pascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

pascalParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::UnsignedNumberContext* pascalParser::NumberContext::unsignedNumber() {
  return getRuleContext<pascalParser::UnsignedNumberContext>(0);
}

pascalParser::SignContext* pascalParser::NumberContext::sign() {
  return getRuleContext<pascalParser::SignContext>(0);
}


size_t pascalParser::NumberContext::getRuleIndex() const {
  return pascalParser::RuleNumber;
}


antlrcpp::Any pascalParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::NumberContext* pascalParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 164, pascalParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(656);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pascalParser::T__6

    || _la == pascalParser::T__7) {
      setState(655);
      sign();
    }
    setState(658);
    unsignedNumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedNumberContext ------------------------------------------------------------------

pascalParser::UnsignedNumberContext::UnsignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::IntegerConstantContext* pascalParser::UnsignedNumberContext::integerConstant() {
  return getRuleContext<pascalParser::IntegerConstantContext>(0);
}

pascalParser::RealConstantContext* pascalParser::UnsignedNumberContext::realConstant() {
  return getRuleContext<pascalParser::RealConstantContext>(0);
}


size_t pascalParser::UnsignedNumberContext::getRuleIndex() const {
  return pascalParser::RuleUnsignedNumber;
}


antlrcpp::Any pascalParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::UnsignedNumberContext* pascalParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 166, pascalParser::RuleUnsignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(662);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(660);
        integerConstant();
        break;
      }

      case pascalParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(661);
        realConstant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerConstantContext ------------------------------------------------------------------

pascalParser::IntegerConstantContext::IntegerConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::IntegerConstantContext::INTEGER() {
  return getToken(pascalParser::INTEGER, 0);
}


size_t pascalParser::IntegerConstantContext::getRuleIndex() const {
  return pascalParser::RuleIntegerConstant;
}


antlrcpp::Any pascalParser::IntegerConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitIntegerConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::IntegerConstantContext* pascalParser::integerConstant() {
  IntegerConstantContext *_localctx = _tracker.createInstance<IntegerConstantContext>(_ctx, getState());
  enterRule(_localctx, 168, pascalParser::RuleIntegerConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(664);
    match(pascalParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealConstantContext ------------------------------------------------------------------

pascalParser::RealConstantContext::RealConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::RealConstantContext::REAL() {
  return getToken(pascalParser::REAL, 0);
}


size_t pascalParser::RealConstantContext::getRuleIndex() const {
  return pascalParser::RuleRealConstant;
}


antlrcpp::Any pascalParser::RealConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRealConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RealConstantContext* pascalParser::realConstant() {
  RealConstantContext *_localctx = _tracker.createInstance<RealConstantContext>(_ctx, getState());
  enterRule(_localctx, 170, pascalParser::RuleRealConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(666);
    match(pascalParser::REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CharacterConstantContext ------------------------------------------------------------------

pascalParser::CharacterConstantContext::CharacterConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::CharacterConstantContext::CHARACTER() {
  return getToken(pascalParser::CHARACTER, 0);
}


size_t pascalParser::CharacterConstantContext::getRuleIndex() const {
  return pascalParser::RuleCharacterConstant;
}


antlrcpp::Any pascalParser::CharacterConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCharacterConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CharacterConstantContext* pascalParser::characterConstant() {
  CharacterConstantContext *_localctx = _tracker.createInstance<CharacterConstantContext>(_ctx, getState());
  enterRule(_localctx, 172, pascalParser::RuleCharacterConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(668);
    match(pascalParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringConstantContext ------------------------------------------------------------------

pascalParser::StringConstantContext::StringConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::StringConstantContext::STRING() {
  return getToken(pascalParser::STRING, 0);
}


size_t pascalParser::StringConstantContext::getRuleIndex() const {
  return pascalParser::RuleStringConstant;
}


antlrcpp::Any pascalParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::StringConstantContext* pascalParser::stringConstant() {
  StringConstantContext *_localctx = _tracker.createInstance<StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 174, pascalParser::RuleStringConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(670);
    match(pascalParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

pascalParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pascalParser::RelOpContext::getRuleIndex() const {
  return pascalParser::RuleRelOp;
}


antlrcpp::Any pascalParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RelOpContext* pascalParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 176, pascalParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(672);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pascalParser::T__5)
      | (1ULL << pascalParser::T__13)
      | (1ULL << pascalParser::T__14)
      | (1ULL << pascalParser::T__15)
      | (1ULL << pascalParser::T__16)
      | (1ULL << pascalParser::T__17))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

pascalParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::AddOpContext::OR() {
  return getToken(pascalParser::OR, 0);
}


size_t pascalParser::AddOpContext::getRuleIndex() const {
  return pascalParser::RuleAddOp;
}


antlrcpp::Any pascalParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::AddOpContext* pascalParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 178, pascalParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(674);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pascalParser::T__6)
      | (1ULL << pascalParser::T__7)
      | (1ULL << pascalParser::OR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

pascalParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::MulOpContext::DIV() {
  return getToken(pascalParser::DIV, 0);
}

tree::TerminalNode* pascalParser::MulOpContext::MOD() {
  return getToken(pascalParser::MOD, 0);
}

tree::TerminalNode* pascalParser::MulOpContext::AND() {
  return getToken(pascalParser::AND, 0);
}


size_t pascalParser::MulOpContext::getRuleIndex() const {
  return pascalParser::RuleMulOp;
}


antlrcpp::Any pascalParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::MulOpContext* pascalParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 180, pascalParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(676);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pascalParser::T__18)
      | (1ULL << pascalParser::T__19)
      | (1ULL << pascalParser::DIV)
      | (1ULL << pascalParser::MOD)
      | (1ULL << pascalParser::AND))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> pascalParser::_decisionToDFA;
atn::PredictionContextCache pascalParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN pascalParser::_atn;
std::vector<uint16_t> pascalParser::_serializedATN;

std::vector<std::string> pascalParser::_ruleNames = {
  "program", "programHeader", "programParameters", "programIdentifier", 
  "block", "declarations", "constantsPart", "constantDefinitionsList", "constantDefinition", 
  "constantIdentifier", "constant", "sign", "typesPart", "typeDefinitionsList", 
  "typeDefinition", "typeIdentifier", "typeSpecification", "simpleType", 
  "enumerationType", "enumerationConstant", "subrangeType", "arrayType", 
  "arrayDimensionList", "recordType", "recordFields", "variablesPart", "variableDeclarationsList", 
  "variableDeclarations", "variableIdentifierList", "variableIdentifier", 
  "routinesPart", "routineDefinition", "procedureHead", "functionHead", 
  "routineIdentifier", "parameters", "parameterDeclarationsList", "parameterDeclarations", 
  "parameterIdentifierList", "parameterIdentifier", "statement", "compoundStatement", 
  "emptyStatement", "statementList", "assignmentStatement", "lhs", "rhs", 
  "ifStatement", "trueStatement", "falseStatement", "caseStatement", "caseBranchList", 
  "caseBranch", "caseConstantList", "caseConstant", "repeatStatement", "whileStatement", 
  "forStatement", "procedureCallStatement", "procedureName", "argumentList", 
  "argument", "writeStatement", "writelnStatement", "writeArguments", "writeArgument", 
  "fieldWidth", "decimalPlaces", "readStatement", "readlnStatement", "readArguments", 
  "expression", "simpleExpression", "term", "factor", "variable", "modifier", 
  "indexList", "index", "field", "functionCall", "functionName", "number", 
  "unsignedNumber", "integerConstant", "realConstant", "characterConstant", 
  "stringConstant", "relOp", "addOp", "mulOp"
};

std::vector<std::string> pascalParser::_literalNames = {
  "", "'.'", "';'", "'('", "','", "')'", "'='", "'-'", "'+'", "'..'", "'['", 
  "']'", "':'", "':='", "'<>'", "'<'", "'<='", "'>'", "'>='", "'*'", "'/'", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "'''"
};

std::vector<std::string> pascalParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "PROGRAM", "CONST", "TYPE", "ARRAY", "OF", "RECORD", "VAR", 
  "BEGIN", "END", "DIV", "MOD", "AND", "OR", "NOT", "IF", "THEN", "ELSE", 
  "CASE", "REPEAT", "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO", "WRITE", 
  "WRITELN", "READ", "READLN", "PROCEDURE", "FUNCTION", "IDENTIFIER", "INTEGER", 
  "REAL", "NEWLINE", "WS", "QUOTE", "CHARACTER", "STRING", "COMMENT"
};

dfa::Vocabulary pascalParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> pascalParser::_tokenNames;

pascalParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x3e, 0x2a9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0xc0, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0xc8, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xcb, 0xb, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xd7, 0xa, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xdc, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0xe1, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0xe6, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x7, 0x9, 0xee, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xf1, 0xb, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x5, 
    0xc, 0xfa, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xfe, 0xa, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0x102, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x10c, 0xa, 
    0xf, 0xc, 0xf, 0xe, 0xf, 0x10f, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0x11a, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 
    0x11f, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 
    0x125, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x128, 0xb, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x13c, 0xa, 0x18, 
    0xc, 0x18, 0xe, 0x18, 0x13f, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x5, 0x19, 0x144, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 
    0x1c, 0x150, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x153, 0xb, 0x1c, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x7, 0x1e, 0x15c, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x15f, 0xb, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x166, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x169, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x5, 0x21, 0x16d, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x175, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x5, 0x23, 0x17a, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x188, 0xa, 0x26, 0xc, 0x26, 
    0xe, 0x26, 0x18b, 0xb, 0x26, 0x3, 0x27, 0x5, 0x27, 0x18e, 0xa, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x7, 0x28, 0x197, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x19a, 0xb, 
    0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1ab, 0xa, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x1b6, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
    0x1b9, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x1c9, 0xa, 0x31, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
    0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 
    0x1d8, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x1db, 0xb, 0x35, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x1e2, 0xa, 0x36, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x1e7, 0xa, 0x37, 0xc, 0x37, 
    0xe, 0x37, 0x1ea, 0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x5, 0x3c, 0x204, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x20d, 0xa, 0x3e, 
    0xc, 0x3e, 0xe, 0x3e, 0x210, 0xb, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x219, 0xa, 0x41, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x21f, 0xa, 0x42, 
    0xc, 0x42, 0xe, 0x42, 0x222, 0xb, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x229, 0xa, 0x43, 0x3, 0x44, 0x5, 0x44, 
    0x22c, 0xa, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x231, 
    0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x7, 0x48, 0x23f, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x242, 0xb, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 
    0x49, 0x24a, 0xa, 0x49, 0x3, 0x4a, 0x5, 0x4a, 0x24d, 0xa, 0x4a, 0x3, 
    0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 0x253, 0xa, 0x4a, 
    0xc, 0x4a, 0xe, 0x4a, 0x256, 0xb, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 
    0x3, 0x4b, 0x7, 0x4b, 0x25c, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x25f, 
    0xb, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
    0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 
    0x26c, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x270, 0xa, 0x4d, 
    0xc, 0x4d, 0xe, 0x4d, 0x273, 0xb, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x27b, 0xa, 0x4e, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x4f, 0x7, 0x4f, 0x280, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 
    0x283, 0xb, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 
    0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 0x28c, 0xa, 0x52, 0x3, 0x52, 0x3, 0x52, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x5, 0x54, 0x293, 0xa, 0x54, 0x3, 0x54, 
    0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x299, 0xa, 0x55, 0x3, 0x56, 
    0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 
    0x3, 0x5c, 0x2, 0x2, 0x5d, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
    0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 
    0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 
    0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0x2, 
    0x7, 0x3, 0x2, 0x9, 0xa, 0x3, 0x2, 0x2e, 0x2f, 0x4, 0x2, 0x8, 0x8, 0x10, 
    0x14, 0x4, 0x2, 0x9, 0xa, 0x23, 0x23, 0x4, 0x2, 0x15, 0x16, 0x20, 0x22, 
    0x2, 0x292, 0x2, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x4, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x8, 0xce, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xe, 0xe7, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xea, 0x3, 0x2, 0x2, 0x2, 0x12, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x16, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x103, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x105, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x108, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x110, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x114, 0x3, 0x2, 0x2, 0x2, 0x22, 0x119, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x26, 0x120, 0x3, 0x2, 0x2, 0x2, 0x28, 0x12b, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x138, 0x3, 0x2, 0x2, 0x2, 0x30, 0x140, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x147, 0x3, 0x2, 0x2, 0x2, 0x34, 0x149, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x38, 0x154, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x160, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x162, 0x3, 0x2, 0x2, 0x2, 0x40, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x42, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x176, 0x3, 0x2, 0x2, 0x2, 0x46, 0x17e, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x180, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x193, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1aa, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x1b2, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1be, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1c2, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1cc, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1d4, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1e3, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x70, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x1f2, 0x3, 0x2, 0x2, 0x2, 0x74, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x76, 0x200, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x207, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x209, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x211, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x213, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x216, 0x3, 0x2, 0x2, 0x2, 0x82, 0x21a, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x225, 0x3, 0x2, 0x2, 0x2, 0x86, 0x22b, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x232, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x234, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x237, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x90, 0x245, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x94, 0x257, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x98, 0x26d, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x27c, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x284, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x286, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0x288, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x28f, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x292, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x298, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x29a, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0x29c, 0x3, 0x2, 0x2, 0x2, 0xae, 0x29e, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x2a2, 0x3, 0x2, 
    0x2, 0x2, 0xb4, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x2a6, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb9, 0x5, 0x4, 0x3, 0x2, 0xb9, 0xba, 0x5, 0xa, 0x6, 0x2, 
    0xba, 0xbb, 0x7, 0x3, 0x2, 0x2, 0xbb, 0x3, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0xbd, 0x7, 0x17, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0x8, 0x5, 0x2, 0xbe, 0xc0, 
    0x5, 0x6, 0x4, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x4, 
    0x2, 0x2, 0xc2, 0x5, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x5, 0x2, 
    0x2, 0xc4, 0xc9, 0x7, 0x36, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x6, 0x2, 0x2, 
    0xc6, 0xc8, 0x7, 0x36, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x7, 0x2, 0x2, 0xcd, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0xce, 0xcf, 0x7, 0x36, 0x2, 0x2, 0xcf, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0xd1, 0x5, 0xc, 0x7, 0x2, 0xd1, 0xd2, 0x5, 0x54, 0x2b, 0x2, 
    0xd2, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0xe, 0x8, 0x2, 0xd4, 
    0xd5, 0x7, 0x4, 0x2, 0x2, 0xd5, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd3, 
    0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x1a, 0xe, 0x2, 0xd9, 0xda, 0x7, 0x4, 
    0x2, 0x2, 0xda, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xdd, 0xde, 0x5, 0x34, 0x1b, 0x2, 0xde, 0xdf, 0x7, 0x4, 0x2, 0x2, 0xdf, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x5, 
    0x3e, 0x20, 0x2, 0xe3, 0xe4, 0x7, 0x4, 0x2, 0x2, 0xe4, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xe5, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xd, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x18, 0x2, 0x2, 
    0xe8, 0xe9, 0x5, 0x10, 0x9, 0x2, 0xe9, 0xf, 0x3, 0x2, 0x2, 0x2, 0xea, 
    0xef, 0x5, 0x12, 0xa, 0x2, 0xeb, 0xec, 0x7, 0x4, 0x2, 0x2, 0xec, 0xee, 
    0x5, 0x12, 0xa, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0x11, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xf2, 0xf3, 0x5, 0x14, 0xb, 0x2, 0xf3, 0xf4, 0x7, 0x8, 0x2, 0x2, 
    0xf4, 0xf5, 0x5, 0x16, 0xc, 0x2, 0xf5, 0x13, 0x3, 0x2, 0x2, 0x2, 0xf6, 
    0xf7, 0x7, 0x36, 0x2, 0x2, 0xf7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfa, 
    0x5, 0x18, 0xd, 0x2, 0xf9, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfe, 0x7, 0x36, 
    0x2, 0x2, 0xfc, 0xfe, 0x5, 0xa8, 0x55, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 
    0x2, 0xfd, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0xff, 0x102, 0x5, 0xae, 0x58, 0x2, 0x100, 0x102, 0x5, 0xb0, 0x59, 0x2, 
    0x101, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x17, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 
    0x9, 0x2, 0x2, 0x2, 0x104, 0x19, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 
    0x19, 0x2, 0x2, 0x106, 0x107, 0x5, 0x1c, 0xf, 0x2, 0x107, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x10d, 0x5, 0x1e, 0x10, 0x2, 0x109, 0x10a, 0x7, 
    0x4, 0x2, 0x2, 0x10a, 0x10c, 0x5, 0x1e, 0x10, 0x2, 0x10b, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x10c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x5, 0x20, 
    0x11, 0x2, 0x111, 0x112, 0x7, 0x8, 0x2, 0x2, 0x112, 0x113, 0x5, 0x22, 
    0x12, 0x2, 0x113, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x7, 0x36, 
    0x2, 0x2, 0x115, 0x21, 0x3, 0x2, 0x2, 0x2, 0x116, 0x11a, 0x5, 0x24, 
    0x13, 0x2, 0x117, 0x11a, 0x5, 0x2c, 0x17, 0x2, 0x118, 0x11a, 0x5, 0x30, 
    0x19, 0x2, 0x119, 0x116, 0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x11f, 0x5, 0x20, 0x11, 0x2, 0x11c, 0x11f, 0x5, 0x26, 0x14, 
    0x2, 0x11d, 0x11f, 0x5, 0x2a, 0x16, 0x2, 0x11e, 0x11b, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x25, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x7, 0x5, 0x2, 0x2, 
    0x121, 0x126, 0x5, 0x28, 0x15, 0x2, 0x122, 0x123, 0x7, 0x6, 0x2, 0x2, 
    0x123, 0x125, 0x5, 0x28, 0x15, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x128, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 
    0x126, 0x127, 0x3, 0x2, 0x2, 0x2, 0x127, 0x129, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x7, 0x2, 0x2, 
    0x12a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x14, 0xb, 0x2, 
    0x12c, 0x29, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0x16, 0xc, 0x2, 
    0x12e, 0x12f, 0x7, 0xb, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x16, 0xc, 0x2, 
    0x130, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x7, 0x1a, 0x2, 0x2, 
    0x132, 0x133, 0x7, 0xc, 0x2, 0x2, 0x133, 0x134, 0x5, 0x2e, 0x18, 0x2, 
    0x134, 0x135, 0x7, 0xd, 0x2, 0x2, 0x135, 0x136, 0x7, 0x1b, 0x2, 0x2, 
    0x136, 0x137, 0x5, 0x22, 0x12, 0x2, 0x137, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x138, 0x13d, 0x5, 0x24, 0x13, 0x2, 0x139, 0x13a, 0x7, 0x6, 0x2, 0x2, 
    0x13a, 0x13c, 0x5, 0x24, 0x13, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 
    0x13d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x13d, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x7, 0x1c, 0x2, 0x2, 0x141, 
    0x143, 0x5, 0x32, 0x1a, 0x2, 0x142, 0x144, 0x7, 0x4, 0x2, 0x2, 0x143, 
    0x142, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x7, 0x1f, 0x2, 0x2, 0x146, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x5, 0x36, 0x1c, 0x2, 0x148, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x1d, 0x2, 0x2, 0x14a, 
    0x14b, 0x5, 0x36, 0x1c, 0x2, 0x14b, 0x35, 0x3, 0x2, 0x2, 0x2, 0x14c, 
    0x151, 0x5, 0x38, 0x1d, 0x2, 0x14d, 0x14e, 0x7, 0x4, 0x2, 0x2, 0x14e, 
    0x150, 0x5, 0x38, 0x1d, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x150, 
    0x153, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x151, 
    0x152, 0x3, 0x2, 0x2, 0x2, 0x152, 0x37, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 
    0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x5, 0x3a, 0x1e, 0x2, 0x155, 0x156, 
    0x7, 0xe, 0x2, 0x2, 0x156, 0x157, 0x5, 0x22, 0x12, 0x2, 0x157, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x158, 0x15d, 0x5, 0x3c, 0x1f, 0x2, 0x159, 0x15a, 
    0x7, 0x6, 0x2, 0x2, 0x15a, 0x15c, 0x5, 0x3c, 0x1f, 0x2, 0x15b, 0x159, 
    0x3, 0x2, 0x2, 0x2, 0x15c, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15b, 
    0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x7, 
    0x36, 0x2, 0x2, 0x161, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x162, 0x167, 0x5, 
    0x40, 0x21, 0x2, 0x163, 0x164, 0x7, 0x4, 0x2, 0x2, 0x164, 0x166, 0x5, 
    0x40, 0x21, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x166, 0x169, 0x3, 
    0x2, 0x2, 0x2, 0x167, 0x165, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x3, 
    0x2, 0x2, 0x2, 0x168, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 0x2, 
    0x2, 0x2, 0x16a, 0x16d, 0x5, 0x42, 0x22, 0x2, 0x16b, 0x16d, 0x5, 0x44, 
    0x23, 0x2, 0x16c, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16b, 0x3, 0x2, 
    0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x7, 0x4, 
    0x2, 0x2, 0x16f, 0x170, 0x5, 0xa, 0x6, 0x2, 0x170, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x171, 0x172, 0x7, 0x34, 0x2, 0x2, 0x172, 0x174, 0x5, 0x46, 0x24, 
    0x2, 0x173, 0x175, 0x5, 0x48, 0x25, 0x2, 0x174, 0x173, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x176, 0x177, 0x7, 0x35, 0x2, 0x2, 0x177, 0x179, 0x5, 0x46, 0x24, 0x2, 
    0x178, 0x17a, 0x5, 0x48, 0x25, 0x2, 0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 
    0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 
    0x17b, 0x17c, 0x7, 0xe, 0x2, 0x2, 0x17c, 0x17d, 0x5, 0x20, 0x11, 0x2, 
    0x17d, 0x45, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x36, 0x2, 0x2, 
    0x17f, 0x47, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x7, 0x5, 0x2, 0x2, 0x181, 
    0x182, 0x5, 0x4a, 0x26, 0x2, 0x182, 0x183, 0x7, 0x7, 0x2, 0x2, 0x183, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x184, 0x189, 0x5, 0x4c, 0x27, 0x2, 0x185, 
    0x186, 0x7, 0x4, 0x2, 0x2, 0x186, 0x188, 0x5, 0x4c, 0x27, 0x2, 0x187, 
    0x185, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x189, 
    0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18e, 
    0x7, 0x1d, 0x2, 0x2, 0x18d, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 
    0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 
    0x5, 0x4e, 0x28, 0x2, 0x190, 0x191, 0x7, 0xe, 0x2, 0x2, 0x191, 0x192, 
    0x5, 0x20, 0x11, 0x2, 0x192, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x193, 0x198, 
    0x5, 0x50, 0x29, 0x2, 0x194, 0x195, 0x7, 0x6, 0x2, 0x2, 0x195, 0x197, 
    0x5, 0x50, 0x29, 0x2, 0x196, 0x194, 0x3, 0x2, 0x2, 0x2, 0x197, 0x19a, 
    0x3, 0x2, 0x2, 0x2, 0x198, 0x196, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 
    0x3, 0x2, 0x2, 0x2, 0x199, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x198, 0x3, 
    0x2, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x36, 0x2, 0x2, 0x19c, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x19d, 0x1ab, 0x5, 0x54, 0x2b, 0x2, 0x19e, 0x1ab, 0x5, 
    0x5a, 0x2e, 0x2, 0x19f, 0x1ab, 0x5, 0x60, 0x31, 0x2, 0x1a0, 0x1ab, 0x5, 
    0x66, 0x34, 0x2, 0x1a1, 0x1ab, 0x5, 0x70, 0x39, 0x2, 0x1a2, 0x1ab, 0x5, 
    0x72, 0x3a, 0x2, 0x1a3, 0x1ab, 0x5, 0x74, 0x3b, 0x2, 0x1a4, 0x1ab, 0x5, 
    0x7e, 0x40, 0x2, 0x1a5, 0x1ab, 0x5, 0x80, 0x41, 0x2, 0x1a6, 0x1ab, 0x5, 
    0x8a, 0x46, 0x2, 0x1a7, 0x1ab, 0x5, 0x8c, 0x47, 0x2, 0x1a8, 0x1ab, 0x5, 
    0x76, 0x3c, 0x2, 0x1a9, 0x1ab, 0x5, 0x56, 0x2c, 0x2, 0x1aa, 0x19d, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x19f, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a1, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a3, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a5, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a7, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a9, 0x3, 
    0x2, 0x2, 0x2, 0x1ab, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x1e, 
    0x2, 0x2, 0x1ad, 0x1ae, 0x5, 0x58, 0x2d, 0x2, 0x1ae, 0x1af, 0x7, 0x1f, 
    0x2, 0x2, 0x1af, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b7, 0x5, 0x52, 0x2a, 
    0x2, 0x1b3, 0x1b4, 0x7, 0x4, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 0x52, 0x2a, 
    0x2, 0x1b5, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b9, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x3, 0x2, 0x2, 
    0x2, 0x1b8, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1b7, 0x3, 0x2, 0x2, 0x2, 
    0x1ba, 0x1bb, 0x5, 0x5c, 0x2f, 0x2, 0x1bb, 0x1bc, 0x7, 0xf, 0x2, 0x2, 
    0x1bc, 0x1bd, 0x5, 0x5e, 0x30, 0x2, 0x1bd, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x1be, 0x1bf, 0x5, 0x98, 0x4d, 0x2, 0x1bf, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x1c0, 0x1c1, 0x5, 0x90, 0x49, 0x2, 0x1c1, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x1c2, 0x1c3, 0x7, 0x25, 0x2, 0x2, 0x1c3, 0x1c4, 0x5, 0x90, 0x49, 0x2, 
    0x1c4, 0x1c5, 0x7, 0x26, 0x2, 0x2, 0x1c5, 0x1c8, 0x5, 0x62, 0x32, 0x2, 
    0x1c6, 0x1c7, 0x7, 0x27, 0x2, 0x2, 0x1c7, 0x1c9, 0x5, 0x64, 0x33, 0x2, 
    0x1c8, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x3, 0x2, 0x2, 0x2, 
    0x1c9, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cb, 0x5, 0x52, 0x2a, 0x2, 
    0x1cb, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x5, 0x52, 0x2a, 0x2, 
    0x1cd, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 0x7, 0x28, 0x2, 0x2, 
    0x1cf, 0x1d0, 0x5, 0x90, 0x49, 0x2, 0x1d0, 0x1d1, 0x7, 0x1b, 0x2, 0x2, 
    0x1d1, 0x1d2, 0x5, 0x68, 0x35, 0x2, 0x1d2, 0x1d3, 0x7, 0x1f, 0x2, 0x2, 
    0x1d3, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d9, 0x5, 0x6a, 0x36, 0x2, 
    0x1d5, 0x1d6, 0x7, 0x4, 0x2, 0x2, 0x1d6, 0x1d8, 0x5, 0x6a, 0x36, 0x2, 
    0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1db, 0x3, 0x2, 0x2, 0x2, 
    0x1d9, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x3, 0x2, 0x2, 0x2, 
    0x1da, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1dc, 
    0x1dd, 0x5, 0x6c, 0x37, 0x2, 0x1dd, 0x1de, 0x7, 0xe, 0x2, 0x2, 0x1de, 
    0x1df, 0x5, 0x52, 0x2a, 0x2, 0x1df, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e0, 
    0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1e1, 
    0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e8, 
    0x5, 0x6e, 0x38, 0x2, 0x1e4, 0x1e5, 0x7, 0x6, 0x2, 0x2, 0x1e5, 0x1e7, 
    0x5, 0x6e, 0x38, 0x2, 0x1e6, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1ea, 
    0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 
    0x3, 0x2, 0x2, 0x2, 0x1e9, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1e8, 0x3, 
    0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x16, 0xc, 0x2, 0x1ec, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x29, 0x2, 0x2, 0x1ee, 0x1ef, 0x5, 
    0x58, 0x2d, 0x2, 0x1ef, 0x1f0, 0x7, 0x2a, 0x2, 0x2, 0x1f0, 0x1f1, 0x5, 
    0x90, 0x49, 0x2, 0x1f1, 0x71, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x7, 
    0x2b, 0x2, 0x2, 0x1f3, 0x1f4, 0x5, 0x90, 0x49, 0x2, 0x1f4, 0x1f5, 0x7, 
    0x2c, 0x2, 0x2, 0x1f5, 0x1f6, 0x5, 0x52, 0x2a, 0x2, 0x1f6, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x2d, 0x2, 0x2, 0x1f8, 0x1f9, 0x5, 
    0x98, 0x4d, 0x2, 0x1f9, 0x1fa, 0x7, 0xf, 0x2, 0x2, 0x1fa, 0x1fb, 0x5, 
    0x90, 0x49, 0x2, 0x1fb, 0x1fc, 0x9, 0x3, 0x2, 0x2, 0x1fc, 0x1fd, 0x5, 
    0x90, 0x49, 0x2, 0x1fd, 0x1fe, 0x7, 0x2c, 0x2, 0x2, 0x1fe, 0x1ff, 0x5, 
    0x52, 0x2a, 0x2, 0x1ff, 0x75, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x5, 
    0x78, 0x3d, 0x2, 0x201, 0x203, 0x7, 0x5, 0x2, 0x2, 0x202, 0x204, 0x5, 
    0x7a, 0x3e, 0x2, 0x203, 0x202, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 0x3, 
    0x2, 0x2, 0x2, 0x204, 0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x7, 
    0x7, 0x2, 0x2, 0x206, 0x77, 0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x7, 0x36, 
    0x2, 0x2, 0x208, 0x79, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20e, 0x5, 0x7c, 
    0x3f, 0x2, 0x20a, 0x20b, 0x7, 0x6, 0x2, 0x2, 0x20b, 0x20d, 0x5, 0x7c, 
    0x3f, 0x2, 0x20c, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x210, 0x3, 0x2, 
    0x2, 0x2, 0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20f, 0x3, 0x2, 
    0x2, 0x2, 0x20f, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20e, 0x3, 0x2, 0x2, 
    0x2, 0x211, 0x212, 0x5, 0x90, 0x49, 0x2, 0x212, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x213, 0x214, 0x7, 0x30, 0x2, 0x2, 0x214, 0x215, 0x5, 0x82, 0x42, 
    0x2, 0x215, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x216, 0x218, 0x7, 0x31, 0x2, 
    0x2, 0x217, 0x219, 0x5, 0x82, 0x42, 0x2, 0x218, 0x217, 0x3, 0x2, 0x2, 
    0x2, 0x218, 0x219, 0x3, 0x2, 0x2, 0x2, 0x219, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x21b, 0x7, 0x5, 0x2, 0x2, 0x21b, 0x220, 0x5, 0x84, 0x43, 0x2, 
    0x21c, 0x21d, 0x7, 0x6, 0x2, 0x2, 0x21d, 0x21f, 0x5, 0x84, 0x43, 0x2, 
    0x21e, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x220, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x223, 0x3, 0x2, 0x2, 0x2, 0x222, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x224, 0x7, 0x7, 0x2, 0x2, 0x224, 0x83, 0x3, 0x2, 0x2, 0x2, 0x225, 
    0x228, 0x5, 0x90, 0x49, 0x2, 0x226, 0x227, 0x7, 0xe, 0x2, 0x2, 0x227, 
    0x229, 0x5, 0x86, 0x44, 0x2, 0x228, 0x226, 0x3, 0x2, 0x2, 0x2, 0x228, 
    0x229, 0x3, 0x2, 0x2, 0x2, 0x229, 0x85, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22c, 
    0x5, 0x18, 0xd, 0x2, 0x22b, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 
    0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x230, 
    0x5, 0xaa, 0x56, 0x2, 0x22e, 0x22f, 0x7, 0xe, 0x2, 0x2, 0x22f, 0x231, 
    0x5, 0x88, 0x45, 0x2, 0x230, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 0x231, 
    0x3, 0x2, 0x2, 0x2, 0x231, 0x87, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 0x5, 
    0xaa, 0x56, 0x2, 0x233, 0x89, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x7, 
    0x32, 0x2, 0x2, 0x235, 0x236, 0x5, 0x8e, 0x48, 0x2, 0x236, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x237, 0x238, 0x7, 0x33, 0x2, 0x2, 0x238, 0x239, 0x5, 
    0x8e, 0x48, 0x2, 0x239, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x7, 
    0x5, 0x2, 0x2, 0x23b, 0x240, 0x5, 0x98, 0x4d, 0x2, 0x23c, 0x23d, 0x7, 
    0x6, 0x2, 0x2, 0x23d, 0x23f, 0x5, 0x98, 0x4d, 0x2, 0x23e, 0x23c, 0x3, 
    0x2, 0x2, 0x2, 0x23f, 0x242, 0x3, 0x2, 0x2, 0x2, 0x240, 0x23e, 0x3, 
    0x2, 0x2, 0x2, 0x240, 0x241, 0x3, 0x2, 0x2, 0x2, 0x241, 0x243, 0x3, 
    0x2, 0x2, 0x2, 0x242, 0x240, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 0x7, 
    0x7, 0x2, 0x2, 0x244, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x245, 0x249, 0x5, 0x92, 
    0x4a, 0x2, 0x246, 0x247, 0x5, 0xb2, 0x5a, 0x2, 0x247, 0x248, 0x5, 0x92, 
    0x4a, 0x2, 0x248, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x249, 0x246, 0x3, 0x2, 
    0x2, 0x2, 0x249, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x24b, 0x24d, 0x5, 0x18, 0xd, 0x2, 0x24c, 0x24b, 0x3, 0x2, 0x2, 
    0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x3, 0x2, 0x2, 
    0x2, 0x24e, 0x254, 0x5, 0x94, 0x4b, 0x2, 0x24f, 0x250, 0x5, 0xb4, 0x5b, 
    0x2, 0x250, 0x251, 0x5, 0x94, 0x4b, 0x2, 0x251, 0x253, 0x3, 0x2, 0x2, 
    0x2, 0x252, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x253, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x254, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x93, 0x3, 0x2, 0x2, 0x2, 0x256, 0x254, 0x3, 0x2, 0x2, 0x2, 
    0x257, 0x25d, 0x5, 0x96, 0x4c, 0x2, 0x258, 0x259, 0x5, 0xb6, 0x5c, 0x2, 
    0x259, 0x25a, 0x5, 0x96, 0x4c, 0x2, 0x25a, 0x25c, 0x3, 0x2, 0x2, 0x2, 
    0x25b, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25f, 0x3, 0x2, 0x2, 0x2, 
    0x25d, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x3, 0x2, 0x2, 0x2, 
    0x25e, 0x95, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x260, 
    0x26c, 0x5, 0x98, 0x4d, 0x2, 0x261, 0x26c, 0x5, 0xa6, 0x54, 0x2, 0x262, 
    0x26c, 0x5, 0xae, 0x58, 0x2, 0x263, 0x26c, 0x5, 0xb0, 0x59, 0x2, 0x264, 
    0x26c, 0x5, 0xa2, 0x52, 0x2, 0x265, 0x266, 0x7, 0x24, 0x2, 0x2, 0x266, 
    0x26c, 0x5, 0x96, 0x4c, 0x2, 0x267, 0x268, 0x7, 0x5, 0x2, 0x2, 0x268, 
    0x269, 0x5, 0x90, 0x49, 0x2, 0x269, 0x26a, 0x7, 0x7, 0x2, 0x2, 0x26a, 
    0x26c, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x260, 0x3, 0x2, 0x2, 0x2, 0x26b, 
    0x261, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x262, 0x3, 0x2, 0x2, 0x2, 0x26b, 
    0x263, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x264, 0x3, 0x2, 0x2, 0x2, 0x26b, 
    0x265, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x267, 0x3, 0x2, 0x2, 0x2, 0x26c, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x271, 0x5, 0x3c, 0x1f, 0x2, 0x26e, 
    0x270, 0x5, 0x9a, 0x4e, 0x2, 0x26f, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x270, 
    0x273, 0x3, 0x2, 0x2, 0x2, 0x271, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x271, 
    0x272, 0x3, 0x2, 0x2, 0x2, 0x272, 0x99, 0x3, 0x2, 0x2, 0x2, 0x273, 0x271, 
    0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x7, 0xc, 0x2, 0x2, 0x275, 0x276, 
    0x5, 0x9c, 0x4f, 0x2, 0x276, 0x277, 0x7, 0xd, 0x2, 0x2, 0x277, 0x27b, 
    0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 0x7, 0x3, 0x2, 0x2, 0x279, 0x27b, 
    0x5, 0xa0, 0x51, 0x2, 0x27a, 0x274, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x278, 
    0x3, 0x2, 0x2, 0x2, 0x27b, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x281, 0x5, 
    0x9e, 0x50, 0x2, 0x27d, 0x27e, 0x7, 0x6, 0x2, 0x2, 0x27e, 0x280, 0x5, 
    0x9e, 0x50, 0x2, 0x27f, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x280, 0x283, 0x3, 
    0x2, 0x2, 0x2, 0x281, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x3, 
    0x2, 0x2, 0x2, 0x282, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x283, 0x281, 0x3, 0x2, 
    0x2, 0x2, 0x284, 0x285, 0x5, 0x90, 0x49, 0x2, 0x285, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0x286, 0x287, 0x7, 0x36, 0x2, 0x2, 0x287, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0x288, 0x289, 0x5, 0xa4, 0x53, 0x2, 0x289, 0x28b, 0x7, 0x5, 
    0x2, 0x2, 0x28a, 0x28c, 0x5, 0x7a, 0x3e, 0x2, 0x28b, 0x28a, 0x3, 0x2, 
    0x2, 0x2, 0x28b, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 0x3, 0x2, 
    0x2, 0x2, 0x28d, 0x28e, 0x7, 0x7, 0x2, 0x2, 0x28e, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0x28f, 0x290, 0x7, 0x36, 0x2, 0x2, 0x290, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0x291, 0x293, 0x5, 0x18, 0xd, 0x2, 0x292, 0x291, 0x3, 0x2, 0x2, 
    0x2, 0x292, 0x293, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 0x2, 
    0x2, 0x294, 0x295, 0x5, 0xa8, 0x55, 0x2, 0x295, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0x296, 0x299, 0x5, 0xaa, 0x56, 0x2, 0x297, 0x299, 0x5, 0xac, 0x57, 
    0x2, 0x298, 0x296, 0x3, 0x2, 0x2, 0x2, 0x298, 0x297, 0x3, 0x2, 0x2, 
    0x2, 0x299, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29b, 0x7, 0x37, 0x2, 
    0x2, 0x29b, 0xab, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x7, 0x38, 0x2, 
    0x2, 0x29d, 0xad, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29f, 0x7, 0x3c, 0x2, 
    0x2, 0x29f, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a1, 0x7, 0x3d, 0x2, 
    0x2, 0x2a1, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a3, 0x9, 0x4, 0x2, 0x2, 
    0x2a3, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x9, 0x5, 0x2, 0x2, 0x2a5, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 0x9, 0x6, 0x2, 0x2, 0x2a7, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0xbf, 0xc9, 0xd6, 0xdb, 0xe0, 0xe5, 0xef, 
    0xf9, 0xfd, 0x101, 0x10d, 0x119, 0x11e, 0x126, 0x13d, 0x143, 0x151, 
    0x15d, 0x167, 0x16c, 0x174, 0x179, 0x189, 0x18d, 0x198, 0x1aa, 0x1b7, 
    0x1c8, 0x1d9, 0x1e1, 0x1e8, 0x203, 0x20e, 0x218, 0x220, 0x228, 0x22b, 
    0x230, 0x240, 0x249, 0x24c, 0x254, 0x25d, 0x26b, 0x271, 0x27a, 0x281, 
    0x28b, 0x292, 0x298, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

pascalParser::Initializer pascalParser::_init;
