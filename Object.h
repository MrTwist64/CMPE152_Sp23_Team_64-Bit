/**
 * <h1>Object</h1>
 *
 * <p>Typedef Object as Object</p>
 *
 * <p>Copyright (c) 2020 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <functional>

#include "antlr4-runtime.h"

typedef antlrcpp::Any Object;

using namespace std;

/**
 * Return a copy of a string with all the letters shifted to upper case.
 * @param str the original string.
 * @return a copy of the string with shifted letters.
 */
inline string toUpperCase(const string str)
{
    string upperCase(str);
    transform(upperCase.begin(), upperCase.end(),
              upperCase.begin(), ::toupper);
    return upperCase;
}

/**
 * Return a copy of a string with all the letters shifted to lower case.
 * @param str the original string.
 * @return a copy of the string with shifted letters.
 */
inline string toLowerCase(const string str)
{
    string lowerCase(str);
    transform(lowerCase.begin(), lowerCase.end(),
              lowerCase.begin(), ::tolower);
    return lowerCase;
}

/**
 * Convert a Pascal string to an equivalent C++ string.
 * @parm pascalString the Pascal string.
 * @parm needBackslash true if need to backslash-quote double-quotes
 * @return the C++ string.
 */
inline string convertString(const string pascalString, bool needBackslash)
{
    string unquoted = pascalString.substr(1, pascalString.length()-2);
    size_t pos = 0;

    while ((pos = unquoted.find("''", pos)) != string::npos)
    {
        unquoted.replace(pos, 2, "'");
        pos++;
    }

    pos = 0;
    while ((pos = unquoted.find("\"", pos)) != string::npos)
    {
        if (needBackslash) unquoted.replace(pos, 1, "\\\"");
        else               unquoted.replace(pos, 1, "\"");

        pos+=2;
    }

    return unquoted;
}

#endif /* OBJECT_H_ */
