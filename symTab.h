#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <string>
#include <map>
//#include "symTabType.h"
using namespace std;

class symTabType
{
private:
    enum kind {program, constant, variable;} 
    string name;
    kind Kind;
public:
    symTabType(string name, kind Kind) 
    {
        this->name = name;
        this->Kind = Kind;
    }
};

class symTab 
{
private:
    map<string, symTabType> symbolTable;
public:
    symTabType newSym(kind Kind, string name) 
    {
        symTabType temp = symTabType(name, Kind)
        symbolTable[name] = temp;
    }
    symbolTable lookup(string name) 
    {
        return symbolTable[name];
    }
    symTabType update(kind kindNew, string nameOld, string nameNew) 
    {
        symTabType temp = symTabType(nameNew, kindNew);
        symbolTable[nameOld] = temp;
    }
};

#endif