#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>
#include <map>
#include <iostream>

#include "symTab.h"
#include "typeSpec.h"

using namespace std;

enum class Kind {PROGRAM, CONSTANT, VARIABLE,};

class SymTab;

class SymTabEntry // each entry of symbol table created here
{
private:
    string name;              // identifier name
    Kind kind;                // what kind of identifier
    int *value;               // Assuming all identifiers are integers
    SymTab *symtab;           // parent symbol table
    TypeSpec *typeSpec;       // type spec

public:
    SymTabEntry()
    {

    }
    
    SymTabEntry(string name, Kind kind, SymTab *parentTab) : name(name), kind(kind), symtab(parentTab)
    {
        switch(kind) {
            case Kind::PROGRAM:
                value = nullptr;
            break;
            case Kind::CONSTANT:
                value = nullptr;
            break;
            case Kind::VARIABLE:
                value = nullptr;
            break;
            
        }

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

    void setValue(int *value)
    {
        this->value = value;
    }
    
    int *getValue(){
        return this->value;
    }
};

#endif // SYMTABENTRY_H_