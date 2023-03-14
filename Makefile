CC=g++
CFLAGS= -I/usr/local/include/antlr4-runtime 
CPPFLAGS= -lantlr4-runtime
ANTLRCC = antlr4

antlr41: pascal.g4
	$(shell $(ANTLRCC) -Dlanguage=Cpp pascal.g4)

antlr42: pascal.g4
	$(ANTLRCC) -Dlanguage=Cpp pascal.g4

scanner: pascalLexer.h pascalLexer.cpp
	$(CC) $(CFLAGS) -o pascal pascal*.cpp $(CPPFLAGS) \
	&& ./pascal < test-in.txt > test-out.txt