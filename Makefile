CC=g++
CFLAGS= -I/usr/local/include/antlr4-runtime 
CPPFLAGS= -lantlr4-runtime
ANTLRCC = java -jar /home/aaron/ANTLR-4.7.2/antlr-4.7.2-complete.jar

# Aaron don't do it. It won't be good
#antlr4: pascal.g4
#	$(ANTLRCC) -Dlanguage=Cpp pascal.g4 -visitor -no-listener

parser: pascal*.cpp pascal*.h
	$(CC) $(CFLAGS) -o pascal pascal*.cpp $(CPPFLAGS) \
	&& ./pascal < test-in.txt > test-out.txt

testSymbolTable: 
	cd manualParser/tests/testSymbolTable \
	&& $(CC) $(CFLAGS) -o testSymbolTable ../../../intermediate/symtab/Symtab.h testSymbolTable.cpp $(CPPFLAGS) \
	&& ./testSymbolTable > test-out.txt