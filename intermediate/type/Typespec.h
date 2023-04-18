#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <vector>
#include <string>
#include "../symtab/Symtab.h"
#include "../symtab/SymtabEntry.h"

namespace intermediate { namespace type {

using namespace std;
using namespace symtab;

class Symtab;
class SymtabEntry;
class Typespec;

enum class Container
{
    ARRAY, SUBRANGE, RECORD, SCALAR, ENUMERATION,
};

static const string ContStr[] = {"array", "subrange", "record", "scalar", "enumeration"};

constexpr Container ARRAY = Container::ARRAY;
constexpr Container SUBRANGE = Container::SUBRANGE;
constexpr Container RECORD = Container::RECORD;
constexpr Container SCALAR = Container::SCALAR;
constexpr Container ENUMERATION = Container::ENUMERATION;

class Typespec 
{
private:
    union ContInfo 
    {
        struct 
        {
            int arrLength;
            Typespec *indexType;
            Typespec *elementType;
        } ARRAY;

        struct 
        {
            int subrMin;
            int subrMax;
            Typespec *baseType;
        } SUBRANGE;
        
        struct 
        {
            string type;
            Symtab *symTab;
        } RECORD;

        struct 
        {
            vector <SymtabEntry*> *enums;
        } ENUMERATION;
        
    };
    Container CONT;
    SymtabEntry *ID;
    static ContInfo inf;

public:
    Typespec() : CONT((Container) -1), ID(nullptr) {}

    Typespec(Container Cont) : CONT(Cont), ID(nullptr)
    {
        switch(Cont)
        {
            case Container::ARRAY: 
                inf.ARRAY.arrLength = 0;
                inf.ARRAY.elementType = nullptr;
                inf.ARRAY.indexType = nullptr;
            break;

            case Container::SUBRANGE:
                inf.SUBRANGE.baseType = nullptr;
                inf.SUBRANGE.subrMax = 0;
                inf.SUBRANGE.subrMin = 0;
            break;

            case Container::RECORD:
                inf.RECORD.type = nullptr;
                inf.RECORD.symTab = nullptr;
            break;

            case Container::ENUMERATION:
                inf.ENUMERATION.enums = nullptr;
            break;
            default:break;
        }
    }

    virtual ~Typespec(){}

    //GETTERS
    bool isArrRec() {return (CONT == Container::ARRAY)|| (CONT == Container::RECORD);}

    Container getCont() {return CONT;}

    int getArrLength() {return inf.ARRAY.arrLength;}

    Typespec *getArrElemType() {return inf.ARRAY.elementType;}
    
    Typespec *getArrIndexType() {return inf.ARRAY.indexType;}

    Typespec *getSubrBaseType() {return inf.SUBRANGE.baseType;}

    int getSubrMax() {return inf.SUBRANGE.subrMax;}

    int getSubrMin() {return inf.SUBRANGE.subrMin;}

    string getRecType() {return inf.RECORD.type;}

    Symtab *getRecSymtab() {return inf.RECORD.symTab;}

    vector <SymtabEntry*> *getEnums() {return inf.ENUMERATION.enums;}

    //SETTERS
    void setArrLength(int x) {inf.ARRAY.arrLength = x;}

    void setArrElemType(Typespec *x) {inf.ARRAY.elementType = x;}
    
    void setArrIndexType(Typespec *x) {inf.ARRAY.indexType = x;}

    void setSubrBaseType(Typespec *x) {inf.SUBRANGE.baseType = x;}

    void setSubrMax(int x) {inf.SUBRANGE.subrMax = x;}

    void setSubrMin(int x) {inf.SUBRANGE.subrMin = x;}

    void setRecType(string x) {inf.RECORD.type = x;}

    void setRecSymtab(Symtab *x) {inf.RECORD.symTab = x;}

    void setEnums(vector <SymtabEntry*> *x) {inf.ENUMERATION.enums = x;}
};

}}

#endif // TYPESPEC_H_
