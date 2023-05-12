CMPE152_Sp23_Team_64-Bit
Assignment 6

===== How To Run ===== 
1. Enter a test pascal program into the test-in.txt file.
2. Run "make compiler" in a bash terminal.
3. View the output in test-out.txt.

===== Notes ===== 
- As noted below, we were not able to complete this assignment.
- Throughout the previous assignments, especially since #3, we ran into many problems with antlr4 and our IDE's setup.
- While we were able to complete those assignments fully, we had to hyper-focus our time and energy on working around these bugs and issues.
- After finishing #5, we took a much needed break and focused our effort on other projects for other classes.
- While we tried our best to get started on this assignment, we have to admit that we've hit a stage of burnout with the project. 
- We added as much as we could, but given the approaching deadline of not only this assignment, but other projects, we had to step back from this project.
- The main structure of this assignment was planned out, as is explained below, but we had a lot of trouble with the implementation of the SICXE code, especially with the runtime stack.
- We are proud of what we were able to accomplish with our previous assignments, espcially our final submission for #5 which fulfilled all of the requirements specified. While we weren't able to complete the entire compiler, we feel that our previous work feels complete.

===== compiler.h ===== 
- The compiler class takes in a symbol table which represents the global stack.
- We also used a frameStack to manage frames within the program, keeping crcack of variables and scopes.
- The class contains functions that would eventually generate assembly code to intiialize a stack frame and its neccessary memory management.
- The visit functions were supposed to generate executable assembly code accordingly.

===== frameStack.h =====
- FrameStack is a class that creates a stack object to contain our frames. 
- The stack has functions such as push, pop, top, createline, and createlinelabel to manipulate the stack for traversal of functions
- We create a frameStack when we call the compiler constructor.
- We fill the stack with new frames when we encounter a function and remove a frame when we exit a function. 

===== frame.h =====
- Frame is a class that implements a frame for each function or procedure call.
- Frames are created in the frame.h class, containing all parameters, local variables, and other related items.
- In the constructor function, the frame get the beginning of the symtab object and iterate through each symtabEntry
- At each symtabEntry, we calculate the scopeOffset for each variable and also the return address 
- There also setters and getter functions for the scope and scopeOffset
- We were able to get this class functioning and hoped to use it with the other classes for this assignment

===== Thank You!!! =====
- We would like to thank both the TA and Professor Nicholson for a great semester. We appreciate the hard work you've both put in to help us with our problems. 
- We have had a lot of fun in this course and learned a lot. :) Thank you again and have a great summer! 
- Team 64-Bit

╭━━━━╮╱╱╱╱╱╱╱╱╭━━━┳╮╱╭╮╱╱╭╮╱╱╭╮
┃╭╮╭╮┃╱╱╱╱╱╱╱╱┃╭━━┫┃╱┃┃╱╱┃┃╱╭╯╰╮
╰╯┃┃┣┻━┳━━┳╮╭╮┃╰━━┫╰━╯┃╱╱┃╰━╋╮╭╯
╱╱┃┃┃┃━┫╭╮┃╰╯┃┃╭━╮┣━━╮┣━━┫╭╮┣┫┃
╱╱┃┃┃┃━┫╭╮┃┃┃┃┃╰━╯┃╱╱┃┣━━┫╰╯┃┃╰╮
╱╱╰╯╰━━┻╯╰┻┻┻╯╰━━━╯╱╱╰╯╱╱╰━━┻┻━╯

████████╗███████╗░█████╗░███╗░░░███╗  ░█████╗░░░██╗██╗░░░░░░██████╗░██╗████████╗
╚══██╔══╝██╔════╝██╔══██╗████╗░████║  ██╔═══╝░░██╔╝██║░░░░░░██╔══██╗██║╚══██╔══╝
░░░██║░░░█████╗░░███████║██╔████╔██║  ██████╗░██╔╝░██║█████╗██████╦╝██║░░░██║░░░
░░░██║░░░██╔══╝░░██╔══██║██║╚██╔╝██║  ██╔══██╗███████║╚════╝██╔══██╗██║░░░██║░░░
░░░██║░░░███████╗██║░░██║██║░╚═╝░██║  ╚█████╔╝╚════██║░░░░░░██████╦╝██║░░░██║░░░
░░░╚═╝░░░╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝  ░╚════╝░░░░░░╚═╝░░░░░░╚═════╝░╚═╝░░░╚═╝░░░
