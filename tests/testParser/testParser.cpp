#include <iostream>
#include <string>
#include "../../parser.h"
#include "../../parseTree.h"
#include "../../parseTreeNode.h"

using namespace std;

int main()
{
    Parser parser;
    parseTreeNode* node;
    

    node = parser.parseProgram();

    if(node)
        parser.getParseTree()->printTreeWalker(node);
    else   
        cout << "Node = NULL" << endl;
}