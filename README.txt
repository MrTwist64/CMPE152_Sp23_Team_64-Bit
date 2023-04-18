CMPE152_Sp23_Team_64-Bit
Assignment 5

===== README =====
- We request that you read this entire README.
- We ran into many problems and issues with this assignment and we have attempted to mention them all below.
- Over

===== How To Run ===== 
1. Run "make parser" in a bash terminal.

===== Notes ===== 
- The grammar file used was provided by the professor as the supplied BNF features errors including left-recursive statements that antlr4.12 cannot generate code for.
- If you would like to recreate the antlr4 files from our grammar file, you MUST change the path of the ANTLRCC macro to one for your machine.

===== Errors =====
- Our group was not able to finish this assignment due to multiple issues that we had over the two weeks we were given to work on this assignment.
- Our first week we were not able to work on the project due to the pascal BNF file we were working with being incompatible with antlr4. We had to wait till the professor could address our issue, which took till about 4 days before the assignment due date. One Friday he supplied us with a new grammar file, which did work with our antlr4 version (the latest version 4.12).
- We immediately met again as a group afterward to start working again, but ran into odd errors within our coding environment. 
    - For example, our IDE was erroring out because of 'missing' files that were in the same directory of the file that we were in. 
    - Another issue is that 'std::any' is underlined as an error, even though our IDE is set to use C++17. We were able to mitigate this issue by switching that type to 'antlrcpp::Any' when extending the files that used them.
- After running into these errors and other issue that we have detailed below, we emailed the professor to set up a time to meet and solve some of these issues. We sent the email Saturday morning and have not recieved a reply as of Tuesday morning.
- Because we haven't been able to solve these issues, we have been stuck and unable to continue working on this assignment.
- As far as we can tell, we are not the only group that are having these issues.

===== Symbol Table =====
- Our symbol table stack includes a base nesting level which is populated at the start of pass 2. It also includes a nesting level counter, a vector of symbol tables acting as our stack, and a program ID pointing to the top level program.
- Our symbol tables also includes nesting levels, an ID for the table's owner, and a map of symbol table entries acting as the symbol table.
- The symbol table entries include a host of information regarding each symbol and line numbers to help find and report errors. 
- The type specification links with the symbol table entries to provide extra information regarding types of scalars, arrays, subranges, records, and enumerations.
- All together, these four files create a symbol table stack with proper symbol table's and their entries with linked type specifications where needed.

===== Pass One & Pass Two =====
- Our pass one contained visit functions on assignment statement, expression, simple expression, and term.
- Our pass two creates a symbol table stack with the different types. Pass two also contains visit functions on program and program header.
- We tried to figure out exactly how we might extend the visitor classes, but we were never able to fully figure out how to interact with the children inside each visitor and what the ctx object could be used for. We feel that we were not properly informed how to do this part of the assignment, even though we understand the theory well enough.
