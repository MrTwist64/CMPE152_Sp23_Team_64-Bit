#include <iostream>

#include "antlr4-runtime.h"
#include "pascalLexer.h"
#include "pascalParser.h"
#include "frontend/intermediatePass.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;
using namespace intermediate;
using namespace frontend;

int main(int argc, const char *args[])
{
	ANTLRInputStream input(cin);
	
	// Create a lexer which scans the input stream
	// to create a token stream.
	pascalLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	
	// Print the token stream.
	// cout << "Tokens:" << endl;
	// tokens.fill();
	// for (Token *token : tokens.getTokens())
	// {
    //     cout << lexer.getVocabulary().getSymbolicName(token->getType());
    //     cout << " : ";
    //     cout << token->getText();
	// 	cout << endl;
	// }

	// Create a parser which parses the token stream
	// to create a parse tree.
	pascalParser parser(&tokens);
	tree::ParseTree *tree = parser.program();

	// Print the parse tree in Lisp format.
	cout << endl << "Parse tree (Lisp format):" << endl;
	cout << tree->toStringTree(&parser) << endl << endl;

	// Create the intermediate symbol table and perform type checking
	Predefined* predefined = new Predefined();
	IntermediatePass* visitor = new IntermediatePass(predefined);
	visitor->visit(tree);

	// Print all symbol tables
	cout << endl << visitor->getStack()->toString() << endl;
	
	return 0;
}