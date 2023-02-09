#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <cstdio>
using namespace std;

const int NS_TABLE_HEIGHT = 32;
const int NS_TABLE_WIDTH = 26;

enum token {tOp, tInt, tSym, tErr};

class Scanner
{
    private:
        map <char, int> symbolMap; 

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
            symbolMap[' '] = 22;
            symbolMap['\t'] = 23;
            symbolMap['\n'] = 24;
            symbolMap['\0'] = 25; // not actually eof but read as eof
        }

        // Determines the next state of the scanner
        // Column 0: Whether the state is a valid end state
        // Column 1: The label to print if we end in this state
        // Column 2+: The next state to go to depending on the input
        //     0+ = Go to state with number
        //     -1 = Return current state/token
        //     -2 = Return with error
        int nsTable[NS_TABLE_HEIGHT][NS_TABLE_WIDTH] = {
            { 0,-1, 3, 1, 4, 5, 6, 7,30, 9,13,14,19,20,-2,21,22,23,24,25,26,27, 0, 0, 0,31}, // 0
            { 1, 1,-1, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 1
            { 1, 2,-1, 2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 2
            { 1, 3, 3, 3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 3
            { 1, 4,-1,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 4
            { 1, 5,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 5
            { 1, 6,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,-1}, // 6
            { 1, 7,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 7
            { 1, 8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 8
            { 1, 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 9
            { 1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 10
            { 1,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 11
            { 1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 12
            { 1,13,-1,-1,-1,-1,-1,-1,-1,11,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 13
            { 1,14,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 14
            { 1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 15
            { 1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 16
            { 1,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 17
            { 1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 18
            { 1,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 19
            { 1,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 20
            { 1,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 21
            { 1,22,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 22
            { 1,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 23
            { 1,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 24
            { 1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 25
            { 1,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 26
            { 1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 27
            { 1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 28
            { 1,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, // 29
            { 0,-1,-2,-2,-2,-2,-2,-2,-2, 8,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2}, // 30
            { 1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}  // 32
        };

        string labelTable[30] = {"EOF", "INTEGER", "REAL", "IDENTIFIER", "PLUSOP", "MINUSOP", "MULTOP", "DIVOP", "ASSIGN", "EQUAL",
            "NE", "LTEQ", "GTEQ", "LT", "GT", "PLUSEQUAL", "MINUSEQUAL", "MULTEQUAL", "DIVEQUAL", "CARAT",
            "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LCOMMENT", "RCOMMENT"};
        
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
        }

        string nexttoken(string& input, int& i)
        {
            int CS = 0;
            int NS = 0;
            char ch;
            string currToken = "";
            auto symbolIterator = symbolMap.begin();
            auto reservedWordsIterator = reservedWords.begin();

            while(true)
            {
                // Determines current character and next state
                ch = tolower(input[i]);
                symbolIterator = symbolMap.find(ch);
                if (isalpha(ch))
                    NS = nsTable[CS][2];
                else if (isdigit(ch))
                    NS = nsTable[CS][3];
                else if (symbolIterator != symbolMap.end())
                    NS = nsTable[CS][symbolIterator->second]; // Char was recognized as valid operator
                else
                    NS == -2;
                
                // Returns or continues based on next state
                if (CS == 31)
                    return "EOF";
                else if (NS == 0)
                {
                    i++;
                    CS = NS;
                }
                else if (NS == -2)
                    return "ERROR";
                else if (NS == -1)
                {
                    if (!nsTable[CS][0])
                        return "ERROR";
                    if (CS == 3)
                    {
                        reservedWordsIterator = reservedWords.find(currToken);
                        if (reservedWordsIterator != reservedWords.end())
                            return reservedWordsIterator->second;
                    }
                    return labelTable[CS];
                }
                else
                {
                    currToken += ch;
                    i++;
                    CS = NS;
                }
            }
        }
        
};

int main()
{
    Scanner scanner;
    string input, token, temp;
    int currCharIndex = 0;

    while(getline(cin, temp)) 
    {
        if (temp.empty())
            break;
        input += temp;
        input += '\n';
    }
    
    // Scan and populate output file with tokens
    while(true)
    {
        token = scanner.nexttoken(input, currCharIndex);
        cout << token << endl;
        if (token == "EOF")
            break;
    }
    return 0;
}