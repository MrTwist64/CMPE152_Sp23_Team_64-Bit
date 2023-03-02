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

    //node = parser.parseFactor();
    node = parser.parseStatementPart();

    cout << "Printing Tree:" << endl;

    if(node)
        parseTree.printTreeWalker(node);
    else   
        cout << "Node = " << node << endl;
}