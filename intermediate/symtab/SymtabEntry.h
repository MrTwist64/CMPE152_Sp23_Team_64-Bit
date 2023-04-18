#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "Symtab.h"
#include "../type/Typespec.h"

namespace intermediate { namespace type {
    class Typespec;
}};

namespace intermediate { namespace symtab {

using namespace std;
using intermediate::type::Typespec;

class Symtab;
class SymtabEntry;

enum class Kind {
    CONSTANT, ENUMERATION_CONSTANT, TYPE, VARIABLE, RECORD_FIELD, VALUE_PARAMETER, REFERENCE_PARAMETER, PROGRAM_PARAMETER, PROGRAM, PROCEDURE, FUNCTION, UNDEFINED
};

static const string KIND_STRINGS[] = {
    "constant", "enumeration constant", "type", "variable", "record field", "value parameter", "reference parameter", "program parameter", "PROGRAM", "PROCEDURE", "FUNCTION", "undefined"
};

constexpr Kind CONSTANT             = Kind::CONSTANT;
constexpr Kind ENUMERATION_CONSTANT = Kind::ENUMERATION_CONSTANT;
constexpr Kind TYPE                 = Kind::TYPE;
constexpr Kind VARIABLE             = Kind::VARIABLE;
constexpr Kind RECORD_FIELD         = Kind::RECORD_FIELD;
constexpr Kind VALUE_PARAMETER      = Kind::VALUE_PARAMETER;
constexpr Kind REFERENCE_PARAMETER  = Kind::REFERENCE_PARAMETER;
constexpr Kind PROGRAM_PARAMETER    = Kind::PROGRAM_PARAMETER;
constexpr Kind PROGRAM              = Kind::PROGRAM;
constexpr Kind PROCEDURE            = Kind::PROCEDURE;
constexpr Kind FUNCTION             = Kind::FUNCTION;
constexpr Kind UNDEFINED            = Kind::UNDEFINED;

class Symtab;

class SymtabEntry // each entry of symbol table created here
{
private:

    // union Info{
    //     struct{
    //         Object *val;
    //     }data;
    // }
    //Info info;                // entry information
    string name;              // identifier name
    Kind kind;                // what kind of identifier
    int value;                // Assuming all identifiers are integers
    Symtab *symtab;           // parent symbol table
    Typespec *typeSpec;       // type spec
    vector<int> line_nums;    // vector of line numbers
public:
    SymtabEntry()
    {

    }
    
    SymtabEntry(string name, Kind kind, Symtab *parentTab) : name(name), kind(kind), symtab(parentTab)
    {
        // switch(kind) {
        //     case Kind::PROGRAM:
        //         value = NULL;
        //     break;
        //     case Kind::CONSTANT:
        //         value = NULL;
        //     break;
        //     case Kind::VARIABLE:
        //         value = NULL;
        //     break;
            
        // }

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

    void setParent(Symtab *symtab)
    {
        this->symtab = symtab;
    }

    Symtab* getParent()
    {
        return symtab;
    }

    vector<int> *getLineNumbers()
    {
        return &line_nums;
    }

    void appendLineNumbers(const int num) 
    {
        line_nums.push_back(num);
    }

    Typespec *getType() const 
    { 
        return typeSpec; 
    }

    void setType(Typespec *typespec) 
    { 
        typeSpec = typespec; 
    }
};

}}
#endif // SYMTABENTRY_H_
