#include <iostream>

#include "antlr4-runtime.h"
#include "pascalLexer.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

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
	
	return 0;
}