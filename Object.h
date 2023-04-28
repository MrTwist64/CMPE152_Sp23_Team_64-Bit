#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <functional>

#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime.h"

typedef antlrcpp::Any Object;

using namespace std;

inline string toUpperCase(const string str)
{
    string upper(str);
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return upper;
}

inline string toLowerCase(const string str)
{
    string lower(str);
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

inline string convertString(const string pString, bool backslash)
{
    string unq = pString.substr(1, pString.length()-2);
    size_t pos = 0;

    while ((pos = unq.find("''", pos)) != string::npos)
    {
        unq.replace(pos, 2, "'");
        pos++;
    }

    pos = 0;
    while ((pos = unq.find("\"", pos)) != string::npos)
    {
        if (backslash) 
            unq.replace(pos, 1, "\\\"");
        else
            unq.replace(pos, 1, "\"");

        pos+=2;
    }

    return unq;
}

#endif /* OBJECT_H_ */
