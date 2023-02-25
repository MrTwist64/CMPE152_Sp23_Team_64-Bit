#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <string>
#include <map>
#include <iostream>

#include "symTabEntry.h"

using namespace std;

class SymTab
{
private:
    map<string, SymTabEntry> SymbolTable;

public:
    SymTab() // Empty Constructor
    {

    }

    SymTabEntry newEntry(Kind kind, string name) 
    {
        SymTabEntry temp = SymTabEntry(name, kind, this);
        SymbolTable[name] = temp;
        return SymbolTable[name];
    }

    SymTabEntry lookup(string name) 
    {
        return SymbolTable[name];
    }

    string toString()
    {
        string temp = "";
        for (map<string, SymTabEntry>::iterator it=SymbolTable.begin(); it!=SymbolTable.end(); ++it){
            temp += it->first + "\n";
        }
        return temp;
    }

    /* Not needed?
    SymTabEntry update(Kind kindNew, string nameOld, string nameNew)
    {
        SymTabEntry temp = SymTabEntry(nameNew, kindNew, this);
        SymbolTable[nameOld] = temp;
    }
    */
};

#endif // SYMTAB_H_