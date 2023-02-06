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

    public:
        Scanner()
        {
            this->CS = sNew;
        }

        token nexttoken(string inputstream)
        {
            char ch;
            int i = 0;
            while(true)
            {
                ch = inputstream[i];
                if (isupper(ch))
                    this->NS = NSTable[this->CS][iUprAlpha];
                else if (islower(ch))
                    this->NS = NSTable[this->CS][iLowAlpha];
                else if (isdigit(ch))
                    this->NS = NSTable[this->CS][iNum];
                else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
                    this->NS = NSTable[this->CS][iOp];
                else if (ch == ' ')
                    this->NS = NSTable[this->CS][iSpace];
                else
                    this->NS = sDone;
                
                if (this->NS == sDone)
                {
                    if (this->CS == sNew)
                        return tErr;
                    else if (this->CS == sOp)
                        return tOp;
                    else if (this->CS == sInt)
                        return tInt;
                    else if (this->CS == sSym)
                        return tSym;
                    else
                        return tErr;
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
    temp = myScanner.nexttoken("IF*");
    cout << temp;
    return 0;
}