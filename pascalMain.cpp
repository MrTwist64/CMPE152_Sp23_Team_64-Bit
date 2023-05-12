#include <iostream>

#include "antlr4-runtime.h"
#include "pascalLexer.h"
#include "pascalParser.h"
#include "frontend/intermediatePass.h"
#include "backend/frameStack.h"
#include "backend/compiler.h"

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
	IntermediatePass* visitors = new IntermediatePass(predefined);
	visitors->visit(tree);

	// Print all symbol tables
	cout << endl << visitors->getStack()->toString() << endl;

	Symtab* testSymtab = visitors->getStack()->lookupLocal("program1")->getChild();
	cout << testSymtab->toString() << endl;
	
	// string tempStr = "";
	FrameStack* frameStack = new FrameStack();
	Frame* frame = frameStack->push(testSymtab, 1);
	cout << "Size = " << frame->getSize() << endl;
	cout << "Offset of scopeOffset = " << frame->getScopeOffset() << endl;
	cout << "Offset of alpha = " << frame->getOffset("alpha") << endl;
	cout << "Offset of beta = " << frame->getOffset("beta") << endl;

	Compiler* comp = new Compiler(testSymtab);
	cout << endl << "----- SICXE CODE FOLLOWS -----" << endl;
	cout << comp->getOutput();
	cout << "----- SICXE CODE ENDS -----" << endl <<endl;
	return 0;
}