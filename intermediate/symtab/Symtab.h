#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <string>
#include <map>
#include <iostream>

#include "SymtabEntry.h"
#include "../type/Typespec.h"

namespace intermediate { namespace symtab {

using namespace std;
using namespace intermediate;
using namespace intermediate::type;

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

    string toString(string indent = "")
    {
        Kind kind;
        Form form;
        string temp = "";

        for (auto it=SymbolTable.begin(); it!=SymbolTable.end(); ++it){
            kind = it->second->getKind();

            temp += indent + KIND_STRINGS[int(kind)];

            if (kind == Kind::VARIABLE)
            {   
                form = it->second->getType()->getForm();
                if (form == Form::SCALAR || form == Form::ENUMERATION)
                    temp += "(" + it->second->getType()->getIdentifier()->getName() + ")";
                if (form == Form::ARRAY)
                    temp += "(array)";
            } 
            else if (kind == Kind::TYPE)
            {
                form = it->second->getType()->getForm();
                temp += "(" + FORM_STRINGS[int(it->second->getType()->getForm())] + ")";
            }

            temp += ":" + it->first + "\n";
        }
        return temp;
    }

    // SymtabEntry update(Kind kindNew, string nameOld, string nameNew)
    // {
    //     SymtabEntry temp = SymtabEntry(nameNew, kindNew, this);
    //     SymbolTable[nameOld] = &temp;

    //     return temp;
    // }

    virtual ~Symtab() {}

};

}}
#endif // SYMTAB_H_
