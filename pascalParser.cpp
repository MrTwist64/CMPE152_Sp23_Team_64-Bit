
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from pascal.g4 by ANTLR 4.12.0


#include "pascalVisitor.h"

#include "pascalParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PascalParserStaticData final {
  PascalParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PascalParserStaticData(const PascalParserStaticData&) = delete;
  PascalParserStaticData(PascalParserStaticData&&) = delete;
  PascalParserStaticData& operator=(const PascalParserStaticData&) = delete;
  PascalParserStaticData& operator=(PascalParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag pascalParserOnceFlag;
PascalParserStaticData *pascalParserStaticData = nullptr;

void pascalParserInitialize() {
  assert(pascalParserStaticData == nullptr);
  auto staticData = std::make_unique<PascalParserStaticData>(
    std::vector<std::string>{
      "program", "programHeader", "programParameters", "programIdentifier", 
      "block", "declarations", "constantsPart", "constantDefinitionsList", 
      "constantDefinition", "constantIdentifier", "constant", "sign", "typesPart", 
      "typeDefinitionsList", "typeDefinition", "typeIdentifier", "typeSpecification", 
      "simpleType", "enumerationType", "enumerationConstant", "subrangeType", 
      "arrayType", "arrayDimensionList", "recordType", "recordFields", "variablesPart", 
      "variableDeclarationsList", "variableDeclarations", "variableIdentifierList", 
      "variableIdentifier", "routinesPart", "routineDefinition", "procedureHead", 
      "functionHead", "routineIdentifier", "parameters", "parameterDeclarationsList", 
      "parameterDeclarations", "parameterIdentifierList", "parameterIdentifier", 
      "statement", "compoundStatement", "emptyStatement", "statementList", 
      "assignmentStatement", "lhs", "rhs", "ifStatement", "trueStatement", 
      "falseStatement", "caseStatement", "caseBranchList", "caseBranch", 
      "caseConstantList", "caseConstant", "repeatStatement", "whileStatement", 
      "forStatement", "procedureCallStatement", "procedureName", "argumentList", 
      "argument", "writeStatement", "writelnStatement", "writeArguments", 
      "writeArgument", "fieldWidth", "decimalPlaces", "readStatement", "readlnStatement", 
      "readArguments", "expression", "simpleExpression", "term", "factor", 
      "variable", "modifier", "indexList", "index", "field", "functionCall", 
      "functionName", "number", "unsignedNumber", "integerConstant", "realConstant", 
      "characterConstant", "stringConstant", "relOp", "addOp", "mulOp"
    },
    std::vector<std::string>{
      "", "'.'", "';'", "'('", "','", "')'", "'='", "'-'", "'+'", "'..'", 
      "'['", "']'", "':'", "':='", "'<>'", "'<'", "'<='", "'>'", "'>='", 
      "'*'", "'/'", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "'''"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "PROGRAM", "CONST", "TYPE", "ARRAY", "OF", "RECORD", 
      "VAR", "BEGIN", "END", "DIV", "MOD", "AND", "OR", "NOT", "IF", "THEN", 
      "ELSE", "CASE", "REPEAT", "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO", 
      "WRITE", "WRITELN", "READ", "READLN", "PROCEDURE", "FUNCTION", "IDENTIFIER", 
      "INTEGER", "REAL", "NEWLINE", "WS", "QUOTE", "CHARACTER", "STRING", 
      "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,60,679,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,7,
  	63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,2,70,7,
  	70,2,71,7,71,2,72,7,72,2,73,7,73,2,74,7,74,2,75,7,75,2,76,7,76,2,77,7,
  	77,2,78,7,78,2,79,7,79,2,80,7,80,2,81,7,81,2,82,7,82,2,83,7,83,2,84,7,
  	84,2,85,7,85,2,86,7,86,2,87,7,87,2,88,7,88,2,89,7,89,2,90,7,90,1,0,1,
  	0,1,0,1,0,1,1,1,1,1,1,3,1,190,8,1,1,1,1,1,1,2,1,2,1,2,1,2,5,2,198,8,2,
  	10,2,12,2,201,9,2,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,5,1,5,1,5,3,5,213,8,5,
  	1,5,1,5,1,5,3,5,218,8,5,1,5,1,5,1,5,3,5,223,8,5,1,5,1,5,1,5,3,5,228,8,
  	5,1,6,1,6,1,6,1,7,1,7,1,7,5,7,236,8,7,10,7,12,7,239,9,7,1,8,1,8,1,8,1,
  	8,1,9,1,9,1,10,3,10,248,8,10,1,10,1,10,3,10,252,8,10,1,10,1,10,3,10,256,
  	8,10,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,5,13,266,8,13,10,13,12,13,
  	269,9,13,1,14,1,14,1,14,1,14,1,15,1,15,1,16,1,16,1,16,3,16,280,8,16,1,
  	17,1,17,1,17,3,17,285,8,17,1,18,1,18,1,18,1,18,5,18,291,8,18,10,18,12,
  	18,294,9,18,1,18,1,18,1,19,1,19,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,22,1,22,1,22,5,22,314,8,22,10,22,12,22,317,9,22,1,
  	23,1,23,1,23,3,23,322,8,23,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,1,
  	26,1,26,5,26,334,8,26,10,26,12,26,337,9,26,1,27,1,27,1,27,1,27,1,28,1,
  	28,1,28,5,28,346,8,28,10,28,12,28,349,9,28,1,29,1,29,1,30,1,30,1,30,5,
  	30,356,8,30,10,30,12,30,359,9,30,1,31,1,31,3,31,363,8,31,1,31,1,31,1,
  	31,1,32,1,32,1,32,3,32,371,8,32,1,33,1,33,1,33,3,33,376,8,33,1,33,1,33,
  	1,33,1,34,1,34,1,35,1,35,1,35,1,35,1,36,1,36,1,36,5,36,390,8,36,10,36,
  	12,36,393,9,36,1,37,3,37,396,8,37,1,37,1,37,1,37,1,37,1,38,1,38,1,38,
  	5,38,405,8,38,10,38,12,38,408,9,38,1,39,1,39,1,40,1,40,1,40,1,40,1,40,
  	1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,3,40,425,8,40,1,41,1,41,1,41,
  	1,41,1,42,1,42,1,43,1,43,1,43,5,43,436,8,43,10,43,12,43,439,9,43,1,44,
  	1,44,1,44,1,44,1,45,1,45,1,46,1,46,1,47,1,47,1,47,1,47,1,47,1,47,3,47,
  	455,8,47,1,48,1,48,1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,50,1,51,1,51,
  	1,51,5,51,470,8,51,10,51,12,51,473,9,51,1,52,1,52,1,52,1,52,1,52,3,52,
  	480,8,52,1,53,1,53,1,53,5,53,485,8,53,10,53,12,53,488,9,53,1,54,1,54,
  	1,55,1,55,1,55,1,55,1,55,1,56,1,56,1,56,1,56,1,56,1,57,1,57,1,57,1,57,
  	1,57,1,57,1,57,1,57,1,57,1,58,1,58,1,58,3,58,514,8,58,1,58,1,58,1,59,
  	1,59,1,60,1,60,1,60,5,60,523,8,60,10,60,12,60,526,9,60,1,61,1,61,1,62,
  	1,62,1,62,1,63,1,63,3,63,535,8,63,1,64,1,64,1,64,1,64,5,64,541,8,64,10,
  	64,12,64,544,9,64,1,64,1,64,1,65,1,65,1,65,3,65,551,8,65,1,66,3,66,554,
  	8,66,1,66,1,66,1,66,3,66,559,8,66,1,67,1,67,1,68,1,68,1,68,1,69,1,69,
  	1,69,1,70,1,70,1,70,1,70,5,70,573,8,70,10,70,12,70,576,9,70,1,70,1,70,
  	1,71,1,71,1,71,1,71,3,71,584,8,71,1,72,3,72,587,8,72,1,72,1,72,1,72,1,
  	72,5,72,593,8,72,10,72,12,72,596,9,72,1,73,1,73,1,73,1,73,5,73,602,8,
  	73,10,73,12,73,605,9,73,1,74,1,74,1,74,1,74,1,74,1,74,1,74,1,74,1,74,
  	1,74,1,74,3,74,618,8,74,1,75,1,75,5,75,622,8,75,10,75,12,75,625,9,75,
  	1,76,1,76,1,76,1,76,1,76,1,76,3,76,633,8,76,1,77,1,77,1,77,5,77,638,8,
  	77,10,77,12,77,641,9,77,1,78,1,78,1,79,1,79,1,80,1,80,1,80,3,80,650,8,
  	80,1,80,1,80,1,81,1,81,1,82,3,82,657,8,82,1,82,1,82,1,83,1,83,3,83,663,
  	8,83,1,84,1,84,1,85,1,85,1,86,1,86,1,87,1,87,1,88,1,88,1,89,1,89,1,90,
  	1,90,1,90,0,0,91,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,
  	38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,
  	84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,
  	124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,
  	160,162,164,166,168,170,172,174,176,178,180,0,5,1,0,7,8,1,0,44,45,2,0,
  	6,6,14,18,2,0,7,8,33,33,2,0,19,20,30,32,656,0,182,1,0,0,0,2,186,1,0,0,
  	0,4,193,1,0,0,0,6,204,1,0,0,0,8,206,1,0,0,0,10,212,1,0,0,0,12,229,1,0,
  	0,0,14,232,1,0,0,0,16,240,1,0,0,0,18,244,1,0,0,0,20,255,1,0,0,0,22,257,
  	1,0,0,0,24,259,1,0,0,0,26,262,1,0,0,0,28,270,1,0,0,0,30,274,1,0,0,0,32,
  	279,1,0,0,0,34,284,1,0,0,0,36,286,1,0,0,0,38,297,1,0,0,0,40,299,1,0,0,
  	0,42,303,1,0,0,0,44,310,1,0,0,0,46,318,1,0,0,0,48,325,1,0,0,0,50,327,
  	1,0,0,0,52,330,1,0,0,0,54,338,1,0,0,0,56,342,1,0,0,0,58,350,1,0,0,0,60,
  	352,1,0,0,0,62,362,1,0,0,0,64,367,1,0,0,0,66,372,1,0,0,0,68,380,1,0,0,
  	0,70,382,1,0,0,0,72,386,1,0,0,0,74,395,1,0,0,0,76,401,1,0,0,0,78,409,
  	1,0,0,0,80,424,1,0,0,0,82,426,1,0,0,0,84,430,1,0,0,0,86,432,1,0,0,0,88,
  	440,1,0,0,0,90,444,1,0,0,0,92,446,1,0,0,0,94,448,1,0,0,0,96,456,1,0,0,
  	0,98,458,1,0,0,0,100,460,1,0,0,0,102,466,1,0,0,0,104,479,1,0,0,0,106,
  	481,1,0,0,0,108,489,1,0,0,0,110,491,1,0,0,0,112,496,1,0,0,0,114,501,1,
  	0,0,0,116,510,1,0,0,0,118,517,1,0,0,0,120,519,1,0,0,0,122,527,1,0,0,0,
  	124,529,1,0,0,0,126,532,1,0,0,0,128,536,1,0,0,0,130,547,1,0,0,0,132,553,
  	1,0,0,0,134,560,1,0,0,0,136,562,1,0,0,0,138,565,1,0,0,0,140,568,1,0,0,
  	0,142,579,1,0,0,0,144,586,1,0,0,0,146,597,1,0,0,0,148,617,1,0,0,0,150,
  	619,1,0,0,0,152,632,1,0,0,0,154,634,1,0,0,0,156,642,1,0,0,0,158,644,1,
  	0,0,0,160,646,1,0,0,0,162,653,1,0,0,0,164,656,1,0,0,0,166,662,1,0,0,0,
  	168,664,1,0,0,0,170,666,1,0,0,0,172,668,1,0,0,0,174,670,1,0,0,0,176,672,
  	1,0,0,0,178,674,1,0,0,0,180,676,1,0,0,0,182,183,3,2,1,0,183,184,3,8,4,
  	0,184,185,5,1,0,0,185,1,1,0,0,0,186,187,5,21,0,0,187,189,3,6,3,0,188,
  	190,3,4,2,0,189,188,1,0,0,0,189,190,1,0,0,0,190,191,1,0,0,0,191,192,5,
  	2,0,0,192,3,1,0,0,0,193,194,5,3,0,0,194,199,5,52,0,0,195,196,5,4,0,0,
  	196,198,5,52,0,0,197,195,1,0,0,0,198,201,1,0,0,0,199,197,1,0,0,0,199,
  	200,1,0,0,0,200,202,1,0,0,0,201,199,1,0,0,0,202,203,5,5,0,0,203,5,1,0,
  	0,0,204,205,5,52,0,0,205,7,1,0,0,0,206,207,3,10,5,0,207,208,3,82,41,0,
  	208,9,1,0,0,0,209,210,3,12,6,0,210,211,5,2,0,0,211,213,1,0,0,0,212,209,
  	1,0,0,0,212,213,1,0,0,0,213,217,1,0,0,0,214,215,3,24,12,0,215,216,5,2,
  	0,0,216,218,1,0,0,0,217,214,1,0,0,0,217,218,1,0,0,0,218,222,1,0,0,0,219,
  	220,3,50,25,0,220,221,5,2,0,0,221,223,1,0,0,0,222,219,1,0,0,0,222,223,
  	1,0,0,0,223,227,1,0,0,0,224,225,3,60,30,0,225,226,5,2,0,0,226,228,1,0,
  	0,0,227,224,1,0,0,0,227,228,1,0,0,0,228,11,1,0,0,0,229,230,5,22,0,0,230,
  	231,3,14,7,0,231,13,1,0,0,0,232,237,3,16,8,0,233,234,5,2,0,0,234,236,
  	3,16,8,0,235,233,1,0,0,0,236,239,1,0,0,0,237,235,1,0,0,0,237,238,1,0,
  	0,0,238,15,1,0,0,0,239,237,1,0,0,0,240,241,3,18,9,0,241,242,5,6,0,0,242,
  	243,3,20,10,0,243,17,1,0,0,0,244,245,5,52,0,0,245,19,1,0,0,0,246,248,
  	3,22,11,0,247,246,1,0,0,0,247,248,1,0,0,0,248,251,1,0,0,0,249,252,5,52,
  	0,0,250,252,3,166,83,0,251,249,1,0,0,0,251,250,1,0,0,0,252,256,1,0,0,
  	0,253,256,3,172,86,0,254,256,3,174,87,0,255,247,1,0,0,0,255,253,1,0,0,
  	0,255,254,1,0,0,0,256,21,1,0,0,0,257,258,7,0,0,0,258,23,1,0,0,0,259,260,
  	5,23,0,0,260,261,3,26,13,0,261,25,1,0,0,0,262,267,3,28,14,0,263,264,5,
  	2,0,0,264,266,3,28,14,0,265,263,1,0,0,0,266,269,1,0,0,0,267,265,1,0,0,
  	0,267,268,1,0,0,0,268,27,1,0,0,0,269,267,1,0,0,0,270,271,3,30,15,0,271,
  	272,5,6,0,0,272,273,3,32,16,0,273,29,1,0,0,0,274,275,5,52,0,0,275,31,
  	1,0,0,0,276,280,3,34,17,0,277,280,3,42,21,0,278,280,3,46,23,0,279,276,
  	1,0,0,0,279,277,1,0,0,0,279,278,1,0,0,0,280,33,1,0,0,0,281,285,3,30,15,
  	0,282,285,3,36,18,0,283,285,3,40,20,0,284,281,1,0,0,0,284,282,1,0,0,0,
  	284,283,1,0,0,0,285,35,1,0,0,0,286,287,5,3,0,0,287,292,3,38,19,0,288,
  	289,5,4,0,0,289,291,3,38,19,0,290,288,1,0,0,0,291,294,1,0,0,0,292,290,
  	1,0,0,0,292,293,1,0,0,0,293,295,1,0,0,0,294,292,1,0,0,0,295,296,5,5,0,
  	0,296,37,1,0,0,0,297,298,3,18,9,0,298,39,1,0,0,0,299,300,3,20,10,0,300,
  	301,5,9,0,0,301,302,3,20,10,0,302,41,1,0,0,0,303,304,5,24,0,0,304,305,
  	5,10,0,0,305,306,3,44,22,0,306,307,5,11,0,0,307,308,5,25,0,0,308,309,
  	3,32,16,0,309,43,1,0,0,0,310,315,3,34,17,0,311,312,5,4,0,0,312,314,3,
  	34,17,0,313,311,1,0,0,0,314,317,1,0,0,0,315,313,1,0,0,0,315,316,1,0,0,
  	0,316,45,1,0,0,0,317,315,1,0,0,0,318,319,5,26,0,0,319,321,3,48,24,0,320,
  	322,5,2,0,0,321,320,1,0,0,0,321,322,1,0,0,0,322,323,1,0,0,0,323,324,5,
  	29,0,0,324,47,1,0,0,0,325,326,3,52,26,0,326,49,1,0,0,0,327,328,5,27,0,
  	0,328,329,3,52,26,0,329,51,1,0,0,0,330,335,3,54,27,0,331,332,5,2,0,0,
  	332,334,3,54,27,0,333,331,1,0,0,0,334,337,1,0,0,0,335,333,1,0,0,0,335,
  	336,1,0,0,0,336,53,1,0,0,0,337,335,1,0,0,0,338,339,3,56,28,0,339,340,
  	5,12,0,0,340,341,3,32,16,0,341,55,1,0,0,0,342,347,3,58,29,0,343,344,5,
  	4,0,0,344,346,3,58,29,0,345,343,1,0,0,0,346,349,1,0,0,0,347,345,1,0,0,
  	0,347,348,1,0,0,0,348,57,1,0,0,0,349,347,1,0,0,0,350,351,5,52,0,0,351,
  	59,1,0,0,0,352,357,3,62,31,0,353,354,5,2,0,0,354,356,3,62,31,0,355,353,
  	1,0,0,0,356,359,1,0,0,0,357,355,1,0,0,0,357,358,1,0,0,0,358,61,1,0,0,
  	0,359,357,1,0,0,0,360,363,3,64,32,0,361,363,3,66,33,0,362,360,1,0,0,0,
  	362,361,1,0,0,0,363,364,1,0,0,0,364,365,5,2,0,0,365,366,3,8,4,0,366,63,
  	1,0,0,0,367,368,5,50,0,0,368,370,3,68,34,0,369,371,3,70,35,0,370,369,
  	1,0,0,0,370,371,1,0,0,0,371,65,1,0,0,0,372,373,5,51,0,0,373,375,3,68,
  	34,0,374,376,3,70,35,0,375,374,1,0,0,0,375,376,1,0,0,0,376,377,1,0,0,
  	0,377,378,5,12,0,0,378,379,3,30,15,0,379,67,1,0,0,0,380,381,5,52,0,0,
  	381,69,1,0,0,0,382,383,5,3,0,0,383,384,3,72,36,0,384,385,5,5,0,0,385,
  	71,1,0,0,0,386,391,3,74,37,0,387,388,5,2,0,0,388,390,3,74,37,0,389,387,
  	1,0,0,0,390,393,1,0,0,0,391,389,1,0,0,0,391,392,1,0,0,0,392,73,1,0,0,
  	0,393,391,1,0,0,0,394,396,5,27,0,0,395,394,1,0,0,0,395,396,1,0,0,0,396,
  	397,1,0,0,0,397,398,3,76,38,0,398,399,5,12,0,0,399,400,3,30,15,0,400,
  	75,1,0,0,0,401,406,3,78,39,0,402,403,5,4,0,0,403,405,3,78,39,0,404,402,
  	1,0,0,0,405,408,1,0,0,0,406,404,1,0,0,0,406,407,1,0,0,0,407,77,1,0,0,
  	0,408,406,1,0,0,0,409,410,5,52,0,0,410,79,1,0,0,0,411,425,3,82,41,0,412,
  	425,3,88,44,0,413,425,3,94,47,0,414,425,3,100,50,0,415,425,3,110,55,0,
  	416,425,3,112,56,0,417,425,3,114,57,0,418,425,3,124,62,0,419,425,3,126,
  	63,0,420,425,3,136,68,0,421,425,3,138,69,0,422,425,3,116,58,0,423,425,
  	3,84,42,0,424,411,1,0,0,0,424,412,1,0,0,0,424,413,1,0,0,0,424,414,1,0,
  	0,0,424,415,1,0,0,0,424,416,1,0,0,0,424,417,1,0,0,0,424,418,1,0,0,0,424,
  	419,1,0,0,0,424,420,1,0,0,0,424,421,1,0,0,0,424,422,1,0,0,0,424,423,1,
  	0,0,0,425,81,1,0,0,0,426,427,5,28,0,0,427,428,3,86,43,0,428,429,5,29,
  	0,0,429,83,1,0,0,0,430,431,1,0,0,0,431,85,1,0,0,0,432,437,3,80,40,0,433,
  	434,5,2,0,0,434,436,3,80,40,0,435,433,1,0,0,0,436,439,1,0,0,0,437,435,
  	1,0,0,0,437,438,1,0,0,0,438,87,1,0,0,0,439,437,1,0,0,0,440,441,3,90,45,
  	0,441,442,5,13,0,0,442,443,3,92,46,0,443,89,1,0,0,0,444,445,3,150,75,
  	0,445,91,1,0,0,0,446,447,3,142,71,0,447,93,1,0,0,0,448,449,5,35,0,0,449,
  	450,3,142,71,0,450,451,5,36,0,0,451,454,3,96,48,0,452,453,5,37,0,0,453,
  	455,3,98,49,0,454,452,1,0,0,0,454,455,1,0,0,0,455,95,1,0,0,0,456,457,
  	3,80,40,0,457,97,1,0,0,0,458,459,3,80,40,0,459,99,1,0,0,0,460,461,5,38,
  	0,0,461,462,3,142,71,0,462,463,5,25,0,0,463,464,3,102,51,0,464,465,5,
  	29,0,0,465,101,1,0,0,0,466,471,3,104,52,0,467,468,5,2,0,0,468,470,3,104,
  	52,0,469,467,1,0,0,0,470,473,1,0,0,0,471,469,1,0,0,0,471,472,1,0,0,0,
  	472,103,1,0,0,0,473,471,1,0,0,0,474,475,3,106,53,0,475,476,5,12,0,0,476,
  	477,3,80,40,0,477,480,1,0,0,0,478,480,1,0,0,0,479,474,1,0,0,0,479,478,
  	1,0,0,0,480,105,1,0,0,0,481,486,3,108,54,0,482,483,5,4,0,0,483,485,3,
  	108,54,0,484,482,1,0,0,0,485,488,1,0,0,0,486,484,1,0,0,0,486,487,1,0,
  	0,0,487,107,1,0,0,0,488,486,1,0,0,0,489,490,3,20,10,0,490,109,1,0,0,0,
  	491,492,5,39,0,0,492,493,3,86,43,0,493,494,5,40,0,0,494,495,3,142,71,
  	0,495,111,1,0,0,0,496,497,5,41,0,0,497,498,3,142,71,0,498,499,5,42,0,
  	0,499,500,3,80,40,0,500,113,1,0,0,0,501,502,5,43,0,0,502,503,3,150,75,
  	0,503,504,5,13,0,0,504,505,3,142,71,0,505,506,7,1,0,0,506,507,3,142,71,
  	0,507,508,5,42,0,0,508,509,3,80,40,0,509,115,1,0,0,0,510,511,3,118,59,
  	0,511,513,5,3,0,0,512,514,3,120,60,0,513,512,1,0,0,0,513,514,1,0,0,0,
  	514,515,1,0,0,0,515,516,5,5,0,0,516,117,1,0,0,0,517,518,5,52,0,0,518,
  	119,1,0,0,0,519,524,3,122,61,0,520,521,5,4,0,0,521,523,3,122,61,0,522,
  	520,1,0,0,0,523,526,1,0,0,0,524,522,1,0,0,0,524,525,1,0,0,0,525,121,1,
  	0,0,0,526,524,1,0,0,0,527,528,3,142,71,0,528,123,1,0,0,0,529,530,5,46,
  	0,0,530,531,3,128,64,0,531,125,1,0,0,0,532,534,5,47,0,0,533,535,3,128,
  	64,0,534,533,1,0,0,0,534,535,1,0,0,0,535,127,1,0,0,0,536,537,5,3,0,0,
  	537,542,3,130,65,0,538,539,5,4,0,0,539,541,3,130,65,0,540,538,1,0,0,0,
  	541,544,1,0,0,0,542,540,1,0,0,0,542,543,1,0,0,0,543,545,1,0,0,0,544,542,
  	1,0,0,0,545,546,5,5,0,0,546,129,1,0,0,0,547,550,3,142,71,0,548,549,5,
  	12,0,0,549,551,3,132,66,0,550,548,1,0,0,0,550,551,1,0,0,0,551,131,1,0,
  	0,0,552,554,3,22,11,0,553,552,1,0,0,0,553,554,1,0,0,0,554,555,1,0,0,0,
  	555,558,3,168,84,0,556,557,5,12,0,0,557,559,3,134,67,0,558,556,1,0,0,
  	0,558,559,1,0,0,0,559,133,1,0,0,0,560,561,3,168,84,0,561,135,1,0,0,0,
  	562,563,5,48,0,0,563,564,3,140,70,0,564,137,1,0,0,0,565,566,5,49,0,0,
  	566,567,3,140,70,0,567,139,1,0,0,0,568,569,5,3,0,0,569,574,3,150,75,0,
  	570,571,5,4,0,0,571,573,3,150,75,0,572,570,1,0,0,0,573,576,1,0,0,0,574,
  	572,1,0,0,0,574,575,1,0,0,0,575,577,1,0,0,0,576,574,1,0,0,0,577,578,5,
  	5,0,0,578,141,1,0,0,0,579,583,3,144,72,0,580,581,3,176,88,0,581,582,3,
  	144,72,0,582,584,1,0,0,0,583,580,1,0,0,0,583,584,1,0,0,0,584,143,1,0,
  	0,0,585,587,3,22,11,0,586,585,1,0,0,0,586,587,1,0,0,0,587,588,1,0,0,0,
  	588,594,3,146,73,0,589,590,3,178,89,0,590,591,3,146,73,0,591,593,1,0,
  	0,0,592,589,1,0,0,0,593,596,1,0,0,0,594,592,1,0,0,0,594,595,1,0,0,0,595,
  	145,1,0,0,0,596,594,1,0,0,0,597,603,3,148,74,0,598,599,3,180,90,0,599,
  	600,3,148,74,0,600,602,1,0,0,0,601,598,1,0,0,0,602,605,1,0,0,0,603,601,
  	1,0,0,0,603,604,1,0,0,0,604,147,1,0,0,0,605,603,1,0,0,0,606,618,3,150,
  	75,0,607,618,3,164,82,0,608,618,3,172,86,0,609,618,3,174,87,0,610,618,
  	3,160,80,0,611,612,5,34,0,0,612,618,3,148,74,0,613,614,5,3,0,0,614,615,
  	3,142,71,0,615,616,5,5,0,0,616,618,1,0,0,0,617,606,1,0,0,0,617,607,1,
  	0,0,0,617,608,1,0,0,0,617,609,1,0,0,0,617,610,1,0,0,0,617,611,1,0,0,0,
  	617,613,1,0,0,0,618,149,1,0,0,0,619,623,3,58,29,0,620,622,3,152,76,0,
  	621,620,1,0,0,0,622,625,1,0,0,0,623,621,1,0,0,0,623,624,1,0,0,0,624,151,
  	1,0,0,0,625,623,1,0,0,0,626,627,5,10,0,0,627,628,3,154,77,0,628,629,5,
  	11,0,0,629,633,1,0,0,0,630,631,5,1,0,0,631,633,3,158,79,0,632,626,1,0,
  	0,0,632,630,1,0,0,0,633,153,1,0,0,0,634,639,3,156,78,0,635,636,5,4,0,
  	0,636,638,3,156,78,0,637,635,1,0,0,0,638,641,1,0,0,0,639,637,1,0,0,0,
  	639,640,1,0,0,0,640,155,1,0,0,0,641,639,1,0,0,0,642,643,3,142,71,0,643,
  	157,1,0,0,0,644,645,5,52,0,0,645,159,1,0,0,0,646,647,3,162,81,0,647,649,
  	5,3,0,0,648,650,3,120,60,0,649,648,1,0,0,0,649,650,1,0,0,0,650,651,1,
  	0,0,0,651,652,5,5,0,0,652,161,1,0,0,0,653,654,5,52,0,0,654,163,1,0,0,
  	0,655,657,3,22,11,0,656,655,1,0,0,0,656,657,1,0,0,0,657,658,1,0,0,0,658,
  	659,3,166,83,0,659,165,1,0,0,0,660,663,3,168,84,0,661,663,3,170,85,0,
  	662,660,1,0,0,0,662,661,1,0,0,0,663,167,1,0,0,0,664,665,5,53,0,0,665,
  	169,1,0,0,0,666,667,5,54,0,0,667,171,1,0,0,0,668,669,5,58,0,0,669,173,
  	1,0,0,0,670,671,5,59,0,0,671,175,1,0,0,0,672,673,7,2,0,0,673,177,1,0,
  	0,0,674,675,7,3,0,0,675,179,1,0,0,0,676,677,7,4,0,0,677,181,1,0,0,0,50,
  	189,199,212,217,222,227,237,247,251,255,267,279,284,292,315,321,335,347,
  	357,362,370,375,391,395,406,424,437,454,471,479,486,513,524,534,542,550,
  	553,558,574,583,586,594,603,617,623,632,639,649,656,662
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pascalParserStaticData = staticData.release();
}

}

pascalParser::pascalParser(TokenStream *input) : pascalParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

pascalParser::pascalParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  pascalParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *pascalParserStaticData->atn, pascalParserStaticData->decisionToDFA, pascalParserStaticData->sharedContextCache, options);
}

pascalParser::~pascalParser() {
  delete _interpreter;
}

const atn::ATN& pascalParser::getATN() const {
  return *pascalParserStaticData->atn;
}

std::string pascalParser::getGrammarFileName() const {
  return "pascal.g4";
}

const std::vector<std::string>& pascalParser::getRuleNames() const {
  return pascalParserStaticData->ruleNames;
}

const dfa::Vocabulary& pascalParser::getVocabulary() const {
  return pascalParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView pascalParser::getSerializedATN() const {
  return pascalParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

pascalParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::ProgramHeaderContext* pascalParser::ProgramContext::programHeader() {
  return getRuleContext<pascalParser::ProgramHeaderContext>(0);
}

pascalParser::BlockContext* pascalParser::ProgramContext::block() {
  return getRuleContext<pascalParser::BlockContext>(0);
}


size_t pascalParser::ProgramContext::getRuleIndex() const {
  return pascalParser::RuleProgram;
}


std::any pascalParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProgramContext* pascalParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, pascalParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    programHeader();
    setState(183);
    block();
    setState(184);
    match(pascalParser::T__0);
   
  }
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


std::any pascalParser::ProgramHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProgramHeader(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProgramHeaderContext* pascalParser::programHeader() {
  ProgramHeaderContext *_localctx = _tracker.createInstance<ProgramHeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, pascalParser::RuleProgramHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ProgramParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProgramParameters(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProgramParametersContext* pascalParser::programParameters() {
  ProgramParametersContext *_localctx = _tracker.createInstance<ProgramParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, pascalParser::RuleProgramParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ProgramIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProgramIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProgramIdentifierContext* pascalParser::programIdentifier() {
  ProgramIdentifierContext *_localctx = _tracker.createInstance<ProgramIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 6, pascalParser::RuleProgramIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    match(pascalParser::IDENTIFIER);
   
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


std::any pascalParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::BlockContext* pascalParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, pascalParser::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::DeclarationsContext* pascalParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 10, pascalParser::RuleDeclarations);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ConstantsPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstantsPart(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantsPartContext* pascalParser::constantsPart() {
  ConstantsPartContext *_localctx = _tracker.createInstance<ConstantsPartContext>(_ctx, getState());
  enterRule(_localctx, 12, pascalParser::RuleConstantsPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ConstantDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantDefinitionsListContext* pascalParser::constantDefinitionsList() {
  ConstantDefinitionsListContext *_localctx = _tracker.createInstance<ConstantDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 14, pascalParser::RuleConstantDefinitionsList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ConstantDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinition(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantDefinitionContext* pascalParser::constantDefinition() {
  ConstantDefinitionContext *_localctx = _tracker.createInstance<ConstantDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 16, pascalParser::RuleConstantDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ConstantIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstantIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantIdentifierContext* pascalParser::constantIdentifier() {
  ConstantIdentifierContext *_localctx = _tracker.createInstance<ConstantIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 18, pascalParser::RuleConstantIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ConstantContext* pascalParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 20, pascalParser::RuleConstant);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::SignContext* pascalParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 22, pascalParser::RuleSign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::TypesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypesPart(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TypesPartContext* pascalParser::typesPart() {
  TypesPartContext *_localctx = _tracker.createInstance<TypesPartContext>(_ctx, getState());
  enterRule(_localctx, 24, pascalParser::RuleTypesPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::TypeDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TypeDefinitionsListContext* pascalParser::typeDefinitionsList() {
  TypeDefinitionsListContext *_localctx = _tracker.createInstance<TypeDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 26, pascalParser::RuleTypeDefinitionsList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::TypeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinition(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TypeDefinitionContext* pascalParser::typeDefinition() {
  TypeDefinitionContext *_localctx = _tracker.createInstance<TypeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 28, pascalParser::RuleTypeDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::TypeIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TypeIdentifierContext* pascalParser::typeIdentifier() {
  TypeIdentifierContext *_localctx = _tracker.createInstance<TypeIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 30, pascalParser::RuleTypeIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::SimpleTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::ArrayTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::RecordTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRecordTypespec(this);
  else
    return visitor->visitChildren(this);
}
pascalParser::TypeSpecificationContext* pascalParser::typeSpecification() {
  TypeSpecificationContext *_localctx = _tracker.createInstance<TypeSpecificationContext>(_ctx, getState());
  enterRule(_localctx, 32, pascalParser::RuleTypeSpecification);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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
        _localctx = _tracker.createInstance<pascalParser::SimpleTypespecContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(276);
        simpleType();
        break;
      }

      case pascalParser::ARRAY: {
        _localctx = _tracker.createInstance<pascalParser::ArrayTypespecContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(277);
        arrayType();
        break;
      }

      case pascalParser::RECORD: {
        _localctx = _tracker.createInstance<pascalParser::RecordTypespecContext>(_localctx);
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


std::any pascalParser::SubrangeTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::EnumerationTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::TypeIdentifierTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifierTypespec(this);
  else
    return visitor->visitChildren(this);
}
pascalParser::SimpleTypeContext* pascalParser::simpleType() {
  SimpleTypeContext *_localctx = _tracker.createInstance<SimpleTypeContext>(_ctx, getState());
  enterRule(_localctx, 34, pascalParser::RuleSimpleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(284);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<pascalParser::TypeIdentifierTypespecContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(281);
      typeIdentifier();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<pascalParser::EnumerationTypespecContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(282);
      enumerationType();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<pascalParser::SubrangeTypespecContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(283);
      subrangeType();
      break;
    }

    default:
      break;
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


std::any pascalParser::EnumerationTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitEnumerationType(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::EnumerationTypeContext* pascalParser::enumerationType() {
  EnumerationTypeContext *_localctx = _tracker.createInstance<EnumerationTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, pascalParser::RuleEnumerationType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::EnumerationConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitEnumerationConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::EnumerationConstantContext* pascalParser::enumerationConstant() {
  EnumerationConstantContext *_localctx = _tracker.createInstance<EnumerationConstantContext>(_ctx, getState());
  enterRule(_localctx, 38, pascalParser::RuleEnumerationConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::SubrangeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitSubrangeType(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::SubrangeTypeContext* pascalParser::subrangeType() {
  SubrangeTypeContext *_localctx = _tracker.createInstance<SubrangeTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, pascalParser::RuleSubrangeType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ArrayTypeContext* pascalParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 42, pascalParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ArrayDimensionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitArrayDimensionList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ArrayDimensionListContext* pascalParser::arrayDimensionList() {
  ArrayDimensionListContext *_localctx = _tracker.createInstance<ArrayDimensionListContext>(_ctx, getState());
  enterRule(_localctx, 44, pascalParser::RuleArrayDimensionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::RecordTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRecordType(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RecordTypeContext* pascalParser::recordType() {
  RecordTypeContext *_localctx = _tracker.createInstance<RecordTypeContext>(_ctx, getState());
  enterRule(_localctx, 46, pascalParser::RuleRecordType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::RecordFieldsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRecordFields(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RecordFieldsContext* pascalParser::recordFields() {
  RecordFieldsContext *_localctx = _tracker.createInstance<RecordFieldsContext>(_ctx, getState());
  enterRule(_localctx, 48, pascalParser::RuleRecordFields);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::VariablesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariablesPart(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariablesPartContext* pascalParser::variablesPart() {
  VariablesPartContext *_localctx = _tracker.createInstance<VariablesPartContext>(_ctx, getState());
  enterRule(_localctx, 50, pascalParser::RuleVariablesPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::VariableDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableDeclarationsListContext* pascalParser::variableDeclarationsList() {
  VariableDeclarationsListContext *_localctx = _tracker.createInstance<VariableDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 52, pascalParser::RuleVariableDeclarationsList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::VariableDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarations(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableDeclarationsContext* pascalParser::variableDeclarations() {
  VariableDeclarationsContext *_localctx = _tracker.createInstance<VariableDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 54, pascalParser::RuleVariableDeclarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::VariableIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableIdentifierListContext* pascalParser::variableIdentifierList() {
  VariableIdentifierListContext *_localctx = _tracker.createInstance<VariableIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 56, pascalParser::RuleVariableIdentifierList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::VariableIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableIdentifierContext* pascalParser::variableIdentifier() {
  VariableIdentifierContext *_localctx = _tracker.createInstance<VariableIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 58, pascalParser::RuleVariableIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::RoutinesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRoutinesPart(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RoutinesPartContext* pascalParser::routinesPart() {
  RoutinesPartContext *_localctx = _tracker.createInstance<RoutinesPartContext>(_ctx, getState());
  enterRule(_localctx, 60, pascalParser::RuleRoutinesPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::RoutineDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRoutineDefinition(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RoutineDefinitionContext* pascalParser::routineDefinition() {
  RoutineDefinitionContext *_localctx = _tracker.createInstance<RoutineDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 62, pascalParser::RuleRoutineDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ProcedureHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProcedureHead(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProcedureHeadContext* pascalParser::procedureHead() {
  ProcedureHeadContext *_localctx = _tracker.createInstance<ProcedureHeadContext>(_ctx, getState());
  enterRule(_localctx, 64, pascalParser::RuleProcedureHead);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::FunctionHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFunctionHead(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FunctionHeadContext* pascalParser::functionHead() {
  FunctionHeadContext *_localctx = _tracker.createInstance<FunctionHeadContext>(_ctx, getState());
  enterRule(_localctx, 66, pascalParser::RuleFunctionHead);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::RoutineIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRoutineIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RoutineIdentifierContext* pascalParser::routineIdentifier() {
  RoutineIdentifierContext *_localctx = _tracker.createInstance<RoutineIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 68, pascalParser::RuleRoutineIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParametersContext* pascalParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 70, pascalParser::RuleParameters);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ParameterDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParameterDeclarationsListContext* pascalParser::parameterDeclarationsList() {
  ParameterDeclarationsListContext *_localctx = _tracker.createInstance<ParameterDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 72, pascalParser::RuleParameterDeclarationsList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ParameterDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarations(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParameterDeclarationsContext* pascalParser::parameterDeclarations() {
  ParameterDeclarationsContext *_localctx = _tracker.createInstance<ParameterDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 74, pascalParser::RuleParameterDeclarations);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ParameterIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParameterIdentifierListContext* pascalParser::parameterIdentifierList() {
  ParameterIdentifierListContext *_localctx = _tracker.createInstance<ParameterIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 76, pascalParser::RuleParameterIdentifierList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ParameterIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ParameterIdentifierContext* pascalParser::parameterIdentifier() {
  ParameterIdentifierContext *_localctx = _tracker.createInstance<ParameterIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 78, pascalParser::RuleParameterIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::StatementContext* pascalParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 80, pascalParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

    default:
      break;
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


std::any pascalParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CompoundStatementContext* pascalParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, pascalParser::RuleCompoundStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::EmptyStatementContext* pascalParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, pascalParser::RuleEmptyStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::StatementListContext* pascalParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 86, pascalParser::RuleStatementList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::AssignmentStatementContext* pascalParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 88, pascalParser::RuleAssignmentStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::LhsContext* pascalParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 90, pascalParser::RuleLhs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RhsContext* pascalParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 92, pascalParser::RuleRhs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::IfStatementContext* pascalParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 94, pascalParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

    default:
      break;
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


std::any pascalParser::TrueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTrueStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TrueStatementContext* pascalParser::trueStatement() {
  TrueStatementContext *_localctx = _tracker.createInstance<TrueStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, pascalParser::RuleTrueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::FalseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFalseStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FalseStatementContext* pascalParser::falseStatement() {
  FalseStatementContext *_localctx = _tracker.createInstance<FalseStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, pascalParser::RuleFalseStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseStatementContext* pascalParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 100, pascalParser::RuleCaseStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::CaseBranchListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseBranchList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseBranchListContext* pascalParser::caseBranchList() {
  CaseBranchListContext *_localctx = _tracker.createInstance<CaseBranchListContext>(_ctx, getState());
  enterRule(_localctx, 102, pascalParser::RuleCaseBranchList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::CaseBranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseBranch(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseBranchContext* pascalParser::caseBranch() {
  CaseBranchContext *_localctx = _tracker.createInstance<CaseBranchContext>(_ctx, getState());
  enterRule(_localctx, 104, pascalParser::RuleCaseBranch);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::CaseConstantListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseConstantList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseConstantListContext* pascalParser::caseConstantList() {
  CaseConstantListContext *_localctx = _tracker.createInstance<CaseConstantListContext>(_ctx, getState());
  enterRule(_localctx, 106, pascalParser::RuleCaseConstantList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::CaseConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCaseConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CaseConstantContext* pascalParser::caseConstant() {
  CaseConstantContext *_localctx = _tracker.createInstance<CaseConstantContext>(_ctx, getState());
  enterRule(_localctx, 108, pascalParser::RuleCaseConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::RepeatStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRepeatStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RepeatStatementContext* pascalParser::repeatStatement() {
  RepeatStatementContext *_localctx = _tracker.createInstance<RepeatStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, pascalParser::RuleRepeatStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WhileStatementContext* pascalParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 112, pascalParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ForStatementContext* pascalParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, pascalParser::RuleForStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ProcedureCallStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProcedureCallStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProcedureCallStatementContext* pascalParser::procedureCallStatement() {
  ProcedureCallStatementContext *_localctx = _tracker.createInstance<ProcedureCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 116, pascalParser::RuleProcedureCallStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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
      ((1ULL << _la) & 896216343026598280) != 0)) {
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


std::any pascalParser::ProcedureNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitProcedureName(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ProcedureNameContext* pascalParser::procedureName() {
  ProcedureNameContext *_localctx = _tracker.createInstance<ProcedureNameContext>(_ctx, getState());
  enterRule(_localctx, 118, pascalParser::RuleProcedureName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ArgumentListContext* pascalParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 120, pascalParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ArgumentContext* pascalParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 122, pascalParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::WriteStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWriteStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WriteStatementContext* pascalParser::writeStatement() {
  WriteStatementContext *_localctx = _tracker.createInstance<WriteStatementContext>(_ctx, getState());
  enterRule(_localctx, 124, pascalParser::RuleWriteStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::WritelnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWritelnStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WritelnStatementContext* pascalParser::writelnStatement() {
  WritelnStatementContext *_localctx = _tracker.createInstance<WritelnStatementContext>(_ctx, getState());
  enterRule(_localctx, 126, pascalParser::RuleWritelnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::WriteArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWriteArguments(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WriteArgumentsContext* pascalParser::writeArguments() {
  WriteArgumentsContext *_localctx = _tracker.createInstance<WriteArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 128, pascalParser::RuleWriteArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::WriteArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitWriteArgument(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::WriteArgumentContext* pascalParser::writeArgument() {
  WriteArgumentContext *_localctx = _tracker.createInstance<WriteArgumentContext>(_ctx, getState());
  enterRule(_localctx, 130, pascalParser::RuleWriteArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::FieldWidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFieldWidth(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FieldWidthContext* pascalParser::fieldWidth() {
  FieldWidthContext *_localctx = _tracker.createInstance<FieldWidthContext>(_ctx, getState());
  enterRule(_localctx, 132, pascalParser::RuleFieldWidth);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::DecimalPlacesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitDecimalPlaces(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::DecimalPlacesContext* pascalParser::decimalPlaces() {
  DecimalPlacesContext *_localctx = _tracker.createInstance<DecimalPlacesContext>(_ctx, getState());
  enterRule(_localctx, 134, pascalParser::RuleDecimalPlaces);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ReadStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitReadStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ReadStatementContext* pascalParser::readStatement() {
  ReadStatementContext *_localctx = _tracker.createInstance<ReadStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, pascalParser::RuleReadStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ReadlnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitReadlnStatement(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ReadlnStatementContext* pascalParser::readlnStatement() {
  ReadlnStatementContext *_localctx = _tracker.createInstance<ReadlnStatementContext>(_ctx, getState());
  enterRule(_localctx, 138, pascalParser::RuleReadlnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ReadArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitReadArguments(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ReadArgumentsContext* pascalParser::readArguments() {
  ReadArgumentsContext *_localctx = _tracker.createInstance<ReadArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 140, pascalParser::RuleReadArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ExpressionContext* pascalParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 142, pascalParser::RuleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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
      ((1ULL << _la) & 507968) != 0)) {
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


std::any pascalParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::SimpleExpressionContext* pascalParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 144, pascalParser::RuleSimpleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

    default:
      break;
    }
    setState(588);
    term();
    setState(594);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8589934976) != 0)) {
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


std::any pascalParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::TermContext* pascalParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 146, pascalParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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
      ((1ULL << _la) & 7517765632) != 0)) {
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


std::any pascalParser::NumberFactorContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::StringFactorContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::CharacterFactorContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::VariableFactorContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::FunctionCallFactorContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::NotFactorContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any pascalParser::ParenthesizedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitParenthesizedFactor(this);
  else
    return visitor->visitChildren(this);
}
pascalParser::FactorContext* pascalParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 148, pascalParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(617);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<pascalParser::VariableFactorContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(606);
      variable();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<pascalParser::NumberFactorContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(607);
      number();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<pascalParser::CharacterFactorContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(608);
      characterConstant();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<pascalParser::StringFactorContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(609);
      stringConstant();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<pascalParser::FunctionCallFactorContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(610);
      functionCall();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<pascalParser::NotFactorContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(611);
      match(pascalParser::NOT);
      setState(612);
      factor();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<pascalParser::ParenthesizedFactorContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(613);
      match(pascalParser::T__2);
      setState(614);
      expression();
      setState(615);
      match(pascalParser::T__4);
      break;
    }

    default:
      break;
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


std::any pascalParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::VariableContext* pascalParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 150, pascalParser::RuleVariable);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::ModifierContext* pascalParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 152, pascalParser::RuleModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::IndexListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitIndexList(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::IndexListContext* pascalParser::indexList() {
  IndexListContext *_localctx = _tracker.createInstance<IndexListContext>(_ctx, getState());
  enterRule(_localctx, 154, pascalParser::RuleIndexList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::IndexContext* pascalParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 156, pascalParser::RuleIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FieldContext* pascalParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 158, pascalParser::RuleField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FunctionCallContext* pascalParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 160, pascalParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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
      ((1ULL << _la) & 896216343026598280) != 0)) {
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


std::any pascalParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::FunctionNameContext* pascalParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 162, pascalParser::RuleFunctionName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::NumberContext* pascalParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 164, pascalParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::UnsignedNumberContext* pascalParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 166, pascalParser::RuleUnsignedNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::IntegerConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitIntegerConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::IntegerConstantContext* pascalParser::integerConstant() {
  IntegerConstantContext *_localctx = _tracker.createInstance<IntegerConstantContext>(_ctx, getState());
  enterRule(_localctx, 168, pascalParser::RuleIntegerConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::RealConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRealConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RealConstantContext* pascalParser::realConstant() {
  RealConstantContext *_localctx = _tracker.createInstance<RealConstantContext>(_ctx, getState());
  enterRule(_localctx, 170, pascalParser::RuleRealConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::CharacterConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitCharacterConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::CharacterConstantContext* pascalParser::characterConstant() {
  CharacterConstantContext *_localctx = _tracker.createInstance<CharacterConstantContext>(_ctx, getState());
  enterRule(_localctx, 172, pascalParser::RuleCharacterConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::StringConstantContext* pascalParser::stringConstant() {
  StringConstantContext *_localctx = _tracker.createInstance<StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 174, pascalParser::RuleStringConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any pascalParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::RelOpContext* pascalParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 176, pascalParser::RuleRelOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(672);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 507968) != 0))) {
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


std::any pascalParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::AddOpContext* pascalParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 178, pascalParser::RuleAddOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(674);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8589934976) != 0))) {
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


std::any pascalParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pascalVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

pascalParser::MulOpContext* pascalParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 180, pascalParser::RuleMulOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(676);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7517765632) != 0))) {
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

void pascalParser::initialize() {
  ::antlr4::internal::call_once(pascalParserOnceFlag, pascalParserInitialize);
}
