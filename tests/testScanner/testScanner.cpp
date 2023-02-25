#include <iostream>
#include <string>
#include "../../scanner.h"

using namespace std;

int main()
{
    Scanner scanner;
    string token;

    // Scan and populate output file with tokens
    while(true)
    {
        token = scanner.getCurrentToken();
        cout << token;
        if (token == "EOF")
            break;
        cout << " : " << scanner.getCurrText() << endl;
        scanner.nextToken();
    }
    return 0;
}