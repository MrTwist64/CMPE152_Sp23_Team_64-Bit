#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>
#include <map>
#include <iostream>

#include "symTab.h"

using namespace std;

enum class Kind {program, constant, variable};

class SymTab;

class SymTabEntry // each entry of symbol table created here
{
private:
    string name;              // identifier name
    Kind kind;                // what kind of identifier
    int value;                // Assuming all identifiers are integers
    SymTab *symtab;           // parent symbol table

public:
    SymTabEntry(string name, Kind kind, SymTab *parentTab) : name(name), kind(kind), symtab(parentTab)
    {
        //this->name = name;
        //this->kind = kind;
        //this->symtab = parentTab;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName() 
    {
        return this->name;
    }

    void setKind(Kind kind)
    {
        this->kind = kind;
    }

    Kind getKind()
    {
        return this->kind;
    }

    void setValue(int value)
    {
        this->value = value;
    }
    
    int getValue(){
        return this->value;
    }

};

#endif