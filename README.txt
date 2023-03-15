CMPE152_Sp23_Team_64-Bit

===== How To Run ===== 
Run "make scanner" in a bash terminal.

===== Notes ===== 
Antlr4 files based on pascal.g4 are already created, but if they need to be rebuilt then run "make antlr4".
For some reason, our installation of Ubuntu seems to be buggy and won't run the above command.
If it turns out that it's not just our system, you can run "antlr4 -Dlanguage=Cpp pascal.g4".

===== Scanner Details ===== 
We recieved Ron Mak's test file and modified it so that it only creates a lexer and not a parser.
We also modified the output to print the token name and the text that generated it.