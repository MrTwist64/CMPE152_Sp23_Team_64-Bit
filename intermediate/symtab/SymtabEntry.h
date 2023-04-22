#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "Symtab.h"
#include "../type/Typespec.h"
#include "../../Object.h"

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
    "CONSTANT", "ENUMERATION_CONSTANT", "TYPE", "VARIABLE", "RECORD_FIELD", "VALUE_PARAMETER", "REFERENCE_PARAMETER", "PROGRAM_PARAMETER", "PROGRAM", "PROCEDURE", "FUNCTION", "UNDEFINED"
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

    union Info{
        struct{
            Object *value;
        }data;
    };

    Info info;                // entry information
    string name;              // identifier name
    Kind kind;                // what kind of identifier
    Symtab *symtab;           // parent symbol table
    Typespec *typeSpec;       // type spec
    vector<int> line_nums;    // vector of line numbers
public:
    SymtabEntry()
    {

    }
    
    SymtabEntry(string name, Kind kind, Symtab *parentTab) : name(name), kind(kind), symtab(parentTab)
    {
        info.data.value = nullptr;
        // switch(kind) {
        //     case Kind::CONSTANT: 
        //     case Kind::VARIABLE:
        //     case Kind::ENUMERATION_CONSTANT:
        //     case Kind::RECORD_FIELD: 
        //     case Kind::VALUE_PARAMETER:
        //         info.data.value = nullptr;
        //         break;

        //     default: break;
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

    void setValue(Object value)
    {
        info.data.value = new Object(value);
    }
    
    Object *getValue() {
        return *(info.data.value);
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
