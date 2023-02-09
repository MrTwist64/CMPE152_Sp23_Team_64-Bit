CC=g++
CFLAGS=-I

scanner: scanner.cpp
	$(CC) scanner.cpp -o scanner
	./scanner < test-in.txt > test-out.txt