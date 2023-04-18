#include <iostream>

#include "antlr4-runtime.h"
#include "pascalLexer.h"
#include "pascalParser.h"
#include "frontend/PassOne.h"
#include "frontend/PassTwo.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;
using namespace frontend;

int main(int argc, const char *args[])
{
	ANTLRInputStream input(std::cin);
	
	// Create a lexer which scans the input stream
	// to create a token stream.
	pascalLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	
	// Print the token stream.
	cout << "Tokens:" << endl;
	tokens.fill();
	for (Token *token : tokens.getTokens())
	{
        std::cout << lexer.getVocabulary().getSymbolicName(token->getType());
        std::cout << " : ";
        std::cout << token->getText();
		std::cout << std::endl;
	}

	// Create a parser which parses the token stream
	// to create a parse tree.
	pascalParser parser(&tokens);
	tree::ParseTree *tree = parser.program();

	// Print the parse tree in Lisp format.
	cout << endl << "Parse tree (Lisp format):" << endl;
	std::cout << tree->toStringTree(&parser) << endl;

	PassOne* visitor = new PassOne;
	visitor->visit(tree);

	// PassTwo* visitor = new PassTwo;
	// visitor->visit(tree);
	
	return 0;
}