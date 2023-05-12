CC=g++
CFLAGS= -I/usr/local/include/antlr4-runtime 
CPPFLAGS= -lantlr4-runtime
ANTLRCC = java -jar /home/aaron/ANTLR-4.7.2/antlr-4.7.2-complete.jar

# Commented to protect code
#antlr4: pascal.g4
#	$(ANTLRCC) -Dlanguage=Cpp pascal.g4 -visitor -no-listener

compiler: pascal*.cpp pascal*.h
	$(CC) $(CFLAGS) -o pascal pascal*.cpp $(CPPFLAGS) \
	&& ./pascal < test-in.txt > test-out.txt