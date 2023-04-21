CC=g++
CFLAGS=-I

testScanner: scanner.h tests\testScanner\testScanner.cpp
	cd tests/testScanner \
	&& $(CC) -o testScanner ../../scanner.h testScanner.cpp \
	&& ./testScanner < test-in.txt > test-out.txt

testSymbolTable: symTab.h typeSpec.h symTabEntry.h tests\testSymbolTable\testSymbolTable.cpp
	cd tests/testSymbolTable \
	&& $(CC) -o testSymbolTable ../../symTab.h testSymbolTable.cpp \
	&& ./testSymbolTable > test-out.txt

testParser: parser.h parseTree.h parseTreeNode.h symTab.h symTabEntry.h typeSpec.h tests\testParser\testParser.cpp
	cd tests/testParser \
	&& $(CC) -o testParser testParser.cpp \
	&& ./testParser < test-in.txt > test-out.txt
