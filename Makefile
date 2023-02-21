CC=g++
CFLAGS=-I

testScanner: scanner.h testScanner.cpp
	$(CC) -o testScanner scanner.h testScanner.cpp
	./testScanner < test-in.txt > test-out.txt

testSymbolTable: symTab.h testSymbolTable.cpp
	$(CC) -o testSymbolTable symTab.h testSymbolTable.cpp
	./testSymbolTable