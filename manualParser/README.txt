CMPE152_Sp23_Team_64-Bit

===== How To Run ===== 
To run, run "make testParser" in a bash terminal.
The scanner will take in an input from "test-in.txt" and the parser will output to "test-out.txt".
NOTE: The test-in.txt and test-out.txt for the parser can be found in tests/testParser.

To test our symbol table, check below in Symbol Table Details.

===== Scanner Details =====
The end of file is determined by reading a null terminator in the "symbolTable"

To recognize reserved words, we first read in a complete word and then before returning it we check it against a 
table of reserved words. If the word is found, we return that version of the word. Else, we return "IDENTIFIER".

===== Parser Details =====
We had to make multiple changes to the structure of the BNF given to us for this project to make it work. This was 
not including ignoring many types of grammars, specifically anything to do with definitions, declarations, functions,
and procedures. These were ignored based on the assignment specificiations.

For example, parseUnsignedReal() requests an exponential identifier as "E". This was not specified within Assignment 02
and so we refrained from implementing that case. Furthermore, parseScaleFactor was only needed for this case and thus was 
also not implemented.

Both parseSimpleExpression() and parseTerm() had left-recursion, so we modified both to be right-recursive. For both 
of those files, we also restructured the order of which tokens were assigned, making the more complex "expression"
get tested first, before the simpler "expression".

parseVariable() has it's calls to parseComponentVariable() and parseReferencedVariable() commented out. This is 
because leaving them in causes an infinite loop. The top-down parser continually searches downward until it finds a 
fit, but both of these functions eventually point back toward parseVariable without consuming any tokens. The only
solution was to break the loop by not calling them in the first place.

===== Symbol Table Details =====
SymbolTable gives a segmentation fault (Makefile Error: 139) when adding a new entry from the parser, but works in testSymbolTable.cpp. 
To run testSymbolTable.cpp, run "make testSymbolTable" in a bash terminal. The inputs are given within testSymbolTable.cpp.
NOTE: The test-out.txt for the testSymbolTable can be found in tests/testSymbolTable.

At the lowest level of the Symbol Table we have the typespec. Typespec is called whenever we encounter an array, 
subrange, scalar, enumeration, or record. Each of these types has a specific set of member variables which are 
set when it is called based on the kind of the encountered type. Typespec is currently not linked with the parser 
because we are only looking for variables which can be stored in the SymbolTableEntry. 

Next we have SymbolTableEntry which calls upon typespec whenever a symbol containing a typespec is found. Otherwise, 
SymbolTableEntry stores identifiers whenever the parser encounters them within the symbolTable created alongside
the parser object.

The symbolTable stores new SymbolTableEntries which are gathered whenever the parser encounters an identifier. 
