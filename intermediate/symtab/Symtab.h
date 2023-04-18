#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <string>
#include <map>
#include <iostream>

#include "SymtabEntry.h"

namespace intermediate { namespace symtab {

using namespace std;
using namespace intermediate;

class SymtabEntry;

class Symtab
{
private:
    int nesting_level;
    SymtabEntry *ownerID;
    map<string, SymtabEntry*> SymbolTable;

public:
    Symtab(const int nesting_level) // Empty Constructor
    {
        this->nesting_level = nesting_level;
        ownerID = nullptr;
    }

    SymtabEntry *getOwner() {
        return ownerID;
    }

    void setOwner(SymtabEntry *ID) {
        ownerID = ID;
    }

    int getCurrNestingLevel() 
    {
        return nesting_level;
    }

    SymtabEntry *newEntry(const Kind kind, const string name) 
    {
        SymtabEntry* temp = new SymtabEntry(name, kind, this);
        SymbolTable.emplace(name, temp);
        return temp;
    }

    SymtabEntry* lookup(string name) 
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
            temp += it->first + ": " + to_string(it->second->getValue()) + "\n";
        }
        return temp;
    }

    /* Not needed?
    SymtabEntry update(Kind kindNew, string nameOld, string nameNew)
    {
        SymtabEntry temp = SymtabEntry(nameNew, kindNew, this);
        SymbolTable[nameOld] = temp;
    }
    */

    virtual ~Symtab() {}

};

}}
#endif // SYMTAB_H_
