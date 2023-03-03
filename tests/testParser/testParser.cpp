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
        parser.getParseTree()->outputTree(node);
    else   
        cout << "No Parse Tree Found" << endl;
    
    // Commented out due to symbol table not working for some reason with parser.
    // To check if it works, please refer to "Symbol Table Details" in the README.txt
    // cout << parser.getSymbolTree()->toString();
}