CMPE152_Sp23_Team_64-Bit
To run, run "make" in a bash terminal.
The scanner will take in an input from "test-in.txt" and output to "test-out.txt"

The end of file is determined by reading a null terminator in the "symbolTable"

To recognize reserved words, we first read in a complete word and then before returning it we check it against a 
table of reserved words. If the word is found, we return that version of the word. Else, we return "IDENTIFIER".
