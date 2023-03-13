#ifndef SCANNER_H_
#define SCANNER_H_

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <cstdio>
using namespace std;

const int NS_TABLE_HEIGHT = 36;
const int NS_TABLE_WIDTH = 27;

class Scanner
{
    private:
        map <char, int> symbolMap;
        string input;
        string currTkn, nextTkn; // The recognized token
        string currTxt, nextTxt; // The text from the input for the current token
        int currCharIndex = 0; 

        void mapPopulator() 
        {
            symbolMap['+'] = 4;
            symbolMap['-'] = 5;
            symbolMap['*'] = 6;
            symbolMap['/'] = 7;
            symbolMap[':'] = 8;
            symbolMap['='] = 9;
            symbolMap['<'] = 10;
            symbolMap['>'] = 11;
            symbolMap['^'] = 12;
            symbolMap[';'] = 13;
            symbolMap['.'] = 14;
            symbolMap[','] = 15;
            symbolMap['('] = 16;
            symbolMap[')'] = 17;
            symbolMap['['] = 18;
            symbolMap[']'] = 19;
            symbolMap['{'] = 20;
            symbolMap['}'] = 21;
            symbolMap['\''] = 22;
            symbolMap[' '] = 23;
            symbolMap['\t'] = 24;
            symbolMap['\n'] = 25;
            symbolMap['\0'] = 26; // not actually eof but read as eof
        }

        // Determines the next state of the scanner
        // Column 0: Whether the state is a valid end state
        // Column 1: The label to print if we end in this state
        // Column 2+: The next state to go to depending on the input
        //     0+ = Go to state with number
        //     -1 = Return current state/token
        //     -2 = Return with error
        int nsTable[NS_TABLE_HEIGHT][NS_TABLE_WIDTH] = {
            {0,-1,3,1,4,5,6,7,30,9,13,14,19,20,31,21,22,23,24,25,26,27,33,0,0,0,35}, //
            {1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,2,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,3,3,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,4,-1,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,5,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,6,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,7,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,13,-1,-1,-1,-1,-1,-1,-1,11,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,14,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,22,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {0,-1,-2,-2,-2,-2,-2,-2,-2,8,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2}, //
            {1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {1,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //
            {0,-1,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,34,33,33,33,-2}, //
            {1,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 
            {1,0,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2} //
        };

        // int nsTable[NS_TABLE_HEIGHT][NS_TABLE_WIDTH] = {
        //     { 0,-1, 3, 1, 4, 5, 6, 7,30, 9,13,14,19,20,31,21,22,23,24,25,26,27, 0, 0, 0,33}, // 0
        //     { 1, 1,-1, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 1
        //     { 1, 2,-1, 2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 2
        //     { 1, 3, 3, 3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 3
        //     { 1, 4,-1,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 4
        //     { 1, 5,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 5
        //     { 1, 6,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,-1}, // 6
        //     { 1, 7,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 7
        //     { 1, 8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 8
        //     { 1, 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 9
        //     { 1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 10
        //     { 1,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 11
        //     { 1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 12
        //     { 1,13,-1,-1,-1,-1,-1,-1,-1,11,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 13
        //     { 1,14,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 14
        //     { 1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 15
        //     { 1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 16
        //     { 1,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 17
        //     { 1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 18
        //     { 1,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 19
        //     { 1,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 20
        //     { 1,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 21
        //     { 1,22,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 22
        //     { 1,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 23
        //     { 1,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 24
        //     { 1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 25
        //     { 1,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 26
        //     { 1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 27
        //     { 1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 28
        //     { 1,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 29
        //     { 0,-1,-2,-2,-2,-2,-2,-2,-2, 8,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2}, // 30
        //     { 1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 31
        //     { 1,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 32
        //     { 1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}  // 33
        // };

        string labelTable[33] = {
            /* 0-4 */ "EOF", "INTEGER", "REAL", "IDENTIFIER", "PLUSOP",
            /* 5-9 */ "MINUSOP", "MULTOP", "DIVOP", "ASSIGN", "EQUAL",
            /*10-14*/ "NE", "LTEQ", "GTEQ", "LT", "GT",
            /*15-19*/ "PLUSEQUAL", "MINUSEQUAL", "MULTEQUAL", "DIVEQUAL", "CARAT",
            /*20-24*/ "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LBRACKET",
            /*25-29*/ "RBRACKET", "LBRACE", "RBRACE", "LCOMMENT", "RCOMMENT",
            /*30-34*/ "PERIOD", "DOTDOT", "STRING"};
        
        map <string, string> reservedWords; // map of reserved words
        void reservePopulator() {
            reservedWords["and"] = "AND";
            reservedWords["array"] = "ARRAY";
            reservedWords["asm"] = "ASM";
            reservedWords["begin"] = "BEGIN";
            reservedWords["break"] = "BREAK";
            reservedWords["case"] = "CASE";
            reservedWords["const"] = "CONST";
            reservedWords["constructor"] = "CONSTRUCTOR";
            reservedWords["continue"] = "CONTINUE";
            reservedWords["destructor"] = "DESTRUCTOR";
            reservedWords["div"] = "DIV";
            reservedWords["do"] = "DO";
            reservedWords["downto"] = "DOWNTO";
            reservedWords["else"] = "ELSE";
            reservedWords["end"] = "END";
            reservedWords["file"] = "FILE";
            reservedWords["for"] = "FOR";
            reservedWords["function"] = "FUNCTION";
            reservedWords["goto"] = "GOTO";
            reservedWords["if"] = "IF";
            reservedWords["implementation"] = "IMPLEMENTATION";
            reservedWords["in"] = "IN";
            reservedWords["inline"] = "IN";
            reservedWords["interface"] = "INTERFACE";
            reservedWords["label"] = "LABEL";
            reservedWords["mod"] = "MOD";
            reservedWords["nil"] = "NIL";
            reservedWords["not"] = "NOT";
            reservedWords["object"] = "OBJECT";
            reservedWords["of"] = "OF";
            reservedWords["on"] = "ON";
            reservedWords["operator"] = "OPERATOR";
            reservedWords["or"] = "OR";
            reservedWords["packed"] = "PACKED";
            reservedWords["procedure"] = "PROCEDURE";
            reservedWords["program"] = "PROGRAM";
            reservedWords["record"] = "RECORD";
            reservedWords["repeat"] = "REPEAT";
            reservedWords["set"] = "SET";
            reservedWords["shl"] = "SHL";
            reservedWords["shr"] = "SHR";
            reservedWords["string"] = "STRING";
            reservedWords["then"] = "THEN";
            reservedWords["to"] = "TO";
            reservedWords["TRUE"] = "TRUE";
            reservedWords["type"] = "TYPE";
            reservedWords["unit"] = "UNIT";
            reservedWords["until"] = "UNTIL";
            reservedWords["uses"] = "USES";
            reservedWords["var"] = "VAR";
            reservedWords["while"] = "WHILE";
            reservedWords["with"] = "WITH";
            reservedWords["xor"] = "XOR";
        }

    public:
        Scanner()
        {
            mapPopulator(); 
            reservePopulator();
            string temp="";
            this->input="";
            this->currCharIndex = 0;

            int i = 0;

            while(getline(cin, temp))
            {
                if (temp.empty()) // This will end the read if given 500 blank lines in a row
                {
                    i++;
                    if (i >= 500) // If this gets triggered, then we advise you rethink your career choice
                        break; // no offense, but totally full offense
                }
                i = 0;
                this->input += temp;
                this->input += '\n';
            }

            nextToken();
            nextToken();
        }
        
        string getCurrToken() {return this->currTkn;}
        string getNextToken() {return this->nextTkn;}
        string getCurrText() {return this->currTxt;}
        string getNextText() {return this->nextTxt;}
        string getInput() {return this->input;}

        void nextToken()
        {
            this->currTkn = this->nextTkn;
            this->currTxt = this->nextTxt;
                
            if (this->currTkn != "EOF")
                readNextToken();
        }

        void readNextToken()
        {
            this->nextTkn = "";
            this->nextTxt = "";
            char ch;

            int CS = 0;
            int NS = 0;

            auto symbolIterator = symbolMap.begin();
            auto reservedWordsIterator = reservedWords.begin();

            while(true)
            {
                // Determines current character and next state
                ch = tolower(this->input[this->currCharIndex]);
                symbolIterator = symbolMap.find(ch);
                if (isalpha(ch))
                    NS = nsTable[CS][2];
                else if (isdigit(ch))
                    NS = nsTable[CS][3];
                else if (symbolIterator != symbolMap.end())
                    NS = nsTable[CS][symbolIterator->second]; // Char was recognized as valid operator
                else
                    NS = -1;
                
                // If whitespace, skip it and continue
                if (NS == 0)
                {
                    this->currCharIndex++;
                    CS = NS;
                    continue;
                }

                // Possible Returns
                if (CS == 35) // If end of file
                {
                    this->nextTkn = "EOF";
                    return;
                }
                if (NS == -2) // if return with error found
                {
                    this->nextTkn = "ERROR";
                    return;
                }
                if (NS == -1) // if return found
                {
                    if (!nsTable[CS][0]) // If invalid return state
                    {
                        this->currCharIndex++;
                        this->nextTkn = "ERROR";
                    }
                    else if (CS == 3) // If current state is identifier
                    {
                        reservedWordsIterator = reservedWords.find(this->nextTxt);
                        if (reservedWordsIterator != reservedWords.end()) // If token is reserved word
                            this->nextTkn = reservedWordsIterator->second;
                        else
                            this->nextTkn = labelTable[nsTable[CS][1]];
                    }
                    else
                        this->nextTkn = labelTable[nsTable[CS][1]];
                    
                    return;
                }

                // No returns found
                // Continue to next character
                this->nextTxt += ch;
                this->currCharIndex++;
                CS = NS;
            }
        }
        
};

#endif
