#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <string>
#include <map>
#include <iostream>

#include "symTabEntry.h"

using namespace std;

class SymTabEntry;

class SymTab
{
private:
    static map<string, SymTabEntry> SymbolTable;

public:
    SymTab() // Empty Constructor
    {

    }

    SymTabEntry newEntry(Kind kind, string name) 
    {
        SymTabEntry temp = SymTabEntry(name, kind, this);
        SymbolTable[name] = temp;
    }

    SymTabEntry lookup(string name) 
    {
        return SymbolTable[name];
    }

    void print()
    {
        for (map<string, SymTabEntry>::iterator it=SymbolTable.begin(); it!=SymbolTable.end(); ++it){
            cout << it->first << endl;
        }
    }

    /* Not needed?
    SymTabEntry update(Kind kindNew, string nameOld, string nameNew)
    {
        SymTabEntry temp = SymTabEntry(nameNew, kindNew, this);
        SymbolTable[nameOld] = temp;
    }
    */
};

#endif