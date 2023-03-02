#include <iostream>
#include <string>
#include "../../parser.h"
#include "../../parseTree.h"
#include "../../parseTreeNode.h"

using namespace std;

int main()
{
    Parser parser;
    ParseTree parseTree;
    parseTreeNode* node;

    node = parser.parseCompoundStatement();

    // node = parser.parseAssignmentStatement();
    // node = parser.parseSimpleExpression();

    if(node)
        parseTree.printTreeWalker(node);
    else   
        cout << "Node = NULL" << endl;
}