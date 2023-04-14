CC=g++
CFLAGS= -I/usr/local/include/antlr4-runtime 
CPPFLAGS= -lantlr4-runtime
ANTLRCC = java -jar /home/aaron/ANTLR-4.12.0/antlr-4.12.0-complete.jar

antlr4: pascal.g4
	$(ANTLRCC) -Dlanguage=Cpp pascal.g4

scanner: pascalLexer.h pascalLexer.cpp
	$(CC) $(CFLAGS) -o pascal pascal*.cpp $(CPPFLAGS) \
	&& ./pascal < test-in.txt > test-out.txt