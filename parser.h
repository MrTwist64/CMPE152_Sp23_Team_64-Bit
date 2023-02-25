#include "scanner.h"
#include "symTabEntry.h"
#include "parseTreeNode.h"
#include "parseTree.h"

using namespace std;

class Parser
{
private:
    parseTree parseTree;
    Scanner scn;
    string curr;

public:
    Parser()
    {
        
    }

    parseTreeNode* parseProgram()
    {
        if (scn.getCurrentToken() != "PROGRAM")
            return NULL;
        scn.nextToken();

        parseTreeNode* identifier = parseIdentifier();
        if(!identifier)
            return NULL;

        if (scn.getCurrentToken() != ";")
            return NULL;
        scn.nextToken();

        parseTreeNode* block = parseBlock();
        if(!block)
            return NULL;

        if (scn.getCurrentToken() != ".")
            return NULL;
        scn.nextToken();
        
        parseTreeNode* programNode = parseTree.createNode(NodeType::PROGRAM);
        programNode->adopt(identifier);
        programNode->adopt(block);
        return programNode;
    }

    parseTreeNode * parseIdentifier()
    {
        if (scn.getCurrentToken() != "IDENTIFIER")
            return NULL;
        string IDName = scn.getCurrText();
        scn.nextToken();

        parseTreeNode * identifier = parseTree.createNode(NodeType::IDENTIFIER);
        parseTree.setName(identifier, IDName);
        return identifier;
    }

    parseTreeNode * parseBlock()
    {
        
    }
    // parseTreeNode parseStatement(){

    // }

    // parseTreeNode parseAssignmentStatement(){

    // }

    // parseTreeNode parseCompoundStatement(){

    // }

    // parseTreeNode parseRepeatStatement(){

    // }

    // parseTreeNode parseWriteStatement(){

    // }

    // parseTreeNode parseWritelnStatement(){

    // }

    // parseTreeNode parseExpression(){

    // }

    // parseTreeNode parseSimpleExpression(){

    // }

    // parseTreeNode parseTerm(){

    // }

    // parseTreeNode parseFactor(){

    // }

    // parseTreeNode parseVariable(){

    // }

    // parseTreeNode parseIntegerConstant(){

    // }

    // parseTreeNode parseRealConstant(){

    // }

    // parseTreeNode parseStringConstant(){

    // }
 
};