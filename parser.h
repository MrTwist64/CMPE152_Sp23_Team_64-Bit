#include "scanner.h"

using namespace std;

class Parser
{
private:
    NodeType *root;
    Scanner scn;

public:
    Parser()
    {
        
    }

    NodeType parseProgram()
    {
        if (scn.getCurrentToken() == "PROGRAM")
        {
            
        }
        else
        {
            return NodeType::EMPTY;
        }
    }

    // NodeType parseStatement(){

    // }

    // NodeType parseAssignmentStatement(){

    // }

    // NodeType parseCompoundStatement(){

    // }

    // NodeType parseRepeatStatement(){

    // }

    // NodeType parseWriteStatement(){

    // }

    // NodeType parseWritelnStatement(){

    // }

    // NodeType parseExpression(){

    // }

    // NodeType parseSimpleExpression(){

    // }

    // NodeType parseTerm(){

    // }

    // NodeType parseFactor(){

    // }

    // NodeType parseVariable(){

    // }

    // NodeType parseIntegerConstant(){

    // }

    // NodeType parseRealConstant(){

    // }

    // NodeType parseStringConstant(){

    // }
 
};

enum class NodeType
{
    EMPTY, PROGRAM, COMPOUND, ASSIGN, LOOP, TEST, WRITE, WRITELN, ADD, SUBTRACT, MULTIPLY, DIVIDE, EQ, LT, VARIABLE, INTEGER_CONSTANT, REAL_CONSTANT, STRING_CONSTANT
};