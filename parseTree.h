#include "scanner.h"

using namespace std;

class ParseTree
{
private:
    NodeType *root;
    Scanner scn;

public:
    ParseTree()
    {
    }

    NodeType parseProgram()
    {
        if (scn.getCurrentToken() == "PROGRAM")
        {
            // create a node yada yada
        }
        else
        {
            return NodeType::EMPTY;
        }
    }

};

enum class NodeType
{
    PROGRAM, COMPOUND, ASSIGN, LOOP, TEST, WRITE, WRITELN, ADD, SUBTRACT, MULTIPLY, DIVIDE, EQ, LT, VARIABLE, INTEGER_CONSTANT, REAL_CONSTANT, STRING_CONSTANT,EMPTY
};