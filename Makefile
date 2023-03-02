CC=g++
CFLAGS=-I

testScanner: scanner.h tests\testScanner\testScanner.cpp
	cd tests/testScanner \
	&& $(CC) -o testScanner ../../scanner.h testScanner.cpp \
	&& ./testScanner < test-in.txt > test-out.txt

testSymbolTable: symTab.h typeSpec.h symTabEntry.h tests\testSymbolTable\testSymbolTable.cpp
	cd tests/testSymbolTable \
	&& $(CC) -o testSymbolTable ../../symTab.h testSymbolTable.cpp \
	&& ./testSymbolTable

testParser: parser.h tests\testParser\testParser.cpp
	cd tests/testParser \
	&& $(CC) -o testParser ../../parser.h testParser.cpp \
	&& ./testParser < test-in.txt > test-out.txt