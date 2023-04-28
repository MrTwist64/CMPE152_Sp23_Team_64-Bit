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

    string toString(int scope, string indent = "")
    {
        Kind kind;
        Form form;
        string temp = "";
        vector<SymtabEntry*> hasChild;
        Typespec *type;

        temp += "Scope " + to_string(scope);
        if (scope != 0)
            temp += ", Owner " + ownerID->getName();
        temp += "\n";

        for (auto it=SymbolTable.begin(); it!=SymbolTable.end(); ++it){
            kind = it->second->getKind();

            temp += indent + KIND_STRINGS[int(kind)];

            if (kind == Kind::VARIABLE || kind == Kind::REFERENCE_PARAMETER
                || kind == Kind::VALUE_PARAMETER || kind == Kind::FUNCTION
                || kind == Kind::CONSTANT)
            {   
                form = it->second->getType()->getForm();
                if (form == Form::SCALAR || form == Form::ENUMERATION)
                    temp += "(" + it->second->getType()->getIdentifier()->getName() + ")";
                
                if (form == Form::ARRAY)
                {
                    type = it->second->getType();
                    form = type->getArrElemType()->getForm();
                    temp += "(array[" + to_string(type->getArrLength()) + ", ";
                    temp += type->getArrIndexType()->baseType()->getIdentifier()->getName() + "] ";
                    type = type->getArrElemType();
                    while (form == Form::ARRAY)
                    {
                        temp += "of array[" + to_string(type->getArrLength()) + ", ";
                        temp += type->getArrIndexType()->baseType()->getIdentifier()->getName() + "] ";
                        type = type->getArrElemType();
                        form = type->getForm();
                    }
                    temp += "of " + type->getIdentifier()->getName() + ")";
                }
            } 
            else if (kind == Kind::TYPE)
            {
                temp += "(" + FORM_STRINGS[int(it->second->getType()->getForm())] + ")";
            }

            temp += ":" + it->first;

            temp += "\n";

            if (kind == Kind::FUNCTION || kind == Kind::PROCEDURE || kind == Kind::PROGRAM)
                hasChild.push_back(it->second);
        }

        // For child symbol tables
        for (SymtabEntry* entry : hasChild)
            temp += entry->getChild()->toString(scope + 1, indent);

        return temp;
    }

    vector<SymtabEntry *> getRoutineParameters()
    {
        vector<SymtabEntry *> list;
        map<string, SymtabEntry *>::iterator it;

        // Iterate over the sorted entries and append them to the list.
        for (it = SymbolTable.begin(); it != SymbolTable.end(); it++)
        {
            list.push_back(it->second);
        }

        return list;  // sorted list of entries
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
