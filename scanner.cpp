#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

enum token {tOp, tInt, tSym, tErr};

class Scanner
{
    private:
        enum state {sNew, sOp, sInt, sSym, sDone};
        enum input {iUprAlpha, iLowAlpha, iNum, iOp, iSpace};
        state NSTable[4][5] = {{sSym, sSym, sInt, sOp, sNew}, // CS = sNew
                              {sDone, sDone, sDone, sOp, sDone}, // CS = sOp
                              {sDone, sDone, sInt, sDone, sDone}, // CS = sInt
                              {sSym, sSym, sDone, sDone, sDone}}; // CS = sSym
        state CS, NS; // Current State, Next State
        map<string,string> ReservedWords;
        void SearchMap(string temp)
        {
            auto itr = ReservedWords.find(temp);
            if (itr == ReservedWords.end())
            {
                cout << "END\n";
            }
            else
            {
                cout << itr->first << " " << itr->second << "\n";
            }
        }



    public:
        Scanner()
        {
            this->CS = sNew;

            ReservedWords.insert(pair<string,string>("IF","if"));
            ReservedWords.insert(pair<string,string>("ELSE","else"));
            ReservedWords.insert(pair<string,string>("(","LPAREN"));
        }

        token nexttoken(string inputstream)
        {
            char ch;
            int i = 0;
            string temp = "";
            while(true)
            {
                ch = inputstream[i];
                if(ch == '\0')
                {
                    return tErr;
                }
                if (isupper(ch) || ch == '(')
                {
                    this->NS = NSTable[this->CS][iUprAlpha];
                    temp+=ch;
                }
                else if (islower(ch))
                {
                    this->NS = NSTable[this->CS][iLowAlpha];
                    temp+=ch;
                }
                else if (isdigit(ch))
                {
                    this->NS = NSTable[this->CS][iNum];
                    temp+=ch;
                }
                else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
                {
                    this->NS = NSTable[this->CS][iOp];
                    temp+=ch;
                }
                else if (ch == ' ')
                {
                    this->NS = NSTable[this->CS][iSpace];
                }
                else
                {
                    this->NS = sDone;
                }
                
                if (this->NS == sDone)
                {
                    if (this->CS == sNew)
                    {
                        SearchMap(temp);
                        temp="";
                    }
                    else if (this->CS == sOp)
                    {
                        SearchMap(temp);
                        temp="";
                    }
                    else if (this->CS == sInt)
                    {
                        SearchMap(temp);
                        temp="";
                    }
                    else if (this->CS == sSym)
                    {
                        SearchMap(temp);
                        this->NS = sNew;
                        temp="";
                        
                    }
                    else //error
                    {
                        temp="";
                    }
                }

                this->CS = this->NS;
                i++;
            }
        }
};

int main()
{
    Scanner myScanner;
    token temp;
    myScanner.nexttoken("IF ( ELSE ");
  
    return 0;
}