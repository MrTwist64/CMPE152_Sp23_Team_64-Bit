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
    map<string, SymTabEntry*> SymbolTable;

public:
    SymTab() // Empty Constructor
    {

    }

    SymTabEntry *newEntry(const Kind kind, const string name) 
    {
        SymTabEntry* temp = new SymTabEntry(name, kind, this);
        SymbolTable.emplace(name, temp);
        return temp;
    }

    SymTabEntry* lookup(string name) 
    {
        auto it = SymbolTable.find(name);
        if (it != SymbolTable.end())
        {
            return it->second;
        }
        else
        {
            return nullptr;
        }
        
    }

    string toString()
    {
        string temp = "";
        for (auto it=SymbolTable.begin(); it!=SymbolTable.end(); ++it){
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