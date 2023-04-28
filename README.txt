CMPE152_Sp23_Team_64-Bit
Assignment 5

===== README =====
- We request that you read this entire README.

===== How To Run ===== 
1. Enter a test pascal program into the test-in.txt file.
2. Run "make parser" in a bash terminal.
3. View the parser output in test-out.txt.

===== Notes ===== 
- The grammar file used was provided by the professor as the supplied BNF features errors including left-recursive statements that antlr4.12 cannot generate code for.
- After having many issues with Antlr4.12, the professor gave our group an extension to work on the project and turn it in after the due date.
- Our code is partially based off of the code from Ron Mak.
- If you would like to recreate the antlr4 files from our grammar file, you MUST change the path of the ANTLRCC macro to one for your machine.
- The type definitions noted in the output for this assignment have been combined into the symbol table output.

===== IntermediatePass.h ===== 
- IntermediatePass is a class that extends pascalBaseVisitor, and contains modified visit functions that construct the Pascal symbol table as it traverses the ANTLR4-generated parse tree.
- IntermediatePass also contains error handling and convenience functions that assist in symbol table construction.
- To use the class, create an instance and use the visit() function which takes in a parse tree.
- IntermediatePass does not visit enumerated types and records, as it was not required for this assignment.

===== ErrStr.h ===== 
- Here we have created an error class within the intermediate namespace which contains several convenience functions to display different error types.
- These functions are called when the parser encounters an error within the visit functions. 

===== TypeChecker.h ===== 
- Here we have created a TypeChecker class within the intermediate namespace which contains convenience functions to check the compatibility between different argument types.
- These functions are called to determine if two variables are of the same type.

===== Object.h ===== 
- Object creates three convenience functions to convert strings between upper case, lower case, and to prepare an input string for storage. 

===== Symbol Table, Typespec, and Predefined Files =====
- Our symbol table stack includes a base nesting level which is populated at the start of pass 2. It also includes a nesting level counter, a vector of symbol tables acting as our stack, and a program ID pointing to the top level program.
- Our symbol tables also includes nesting levels, an ID for the table's owner, and a map of symbol table entries acting as the symbol table.
- The symbol table entries include a host of information regarding each symbol and line numbers to help find and report errors. 
- The type specification links with the symbol table entries to provide extra information regarding types of scalars, arrays, subranges, records, and enumerations.
- Predefined.h fills the base level of the symbol table stack with the predefined constants and types included in pascal. 
- All together, these four files create a symbol table stack with proper symbol table's and their entries with linked type specifications where needed.

===== test-in.txt =====
- We provided an extensive test program to verify our parser.
- We test many different assignment statements within the main block of the program.
- Many of these statements are purposely incorrect, which are noted by a comment in curly braces with the expected error.