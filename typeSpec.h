#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <vector>
#include <string>
#include "symTab.h"
#include "symTabEntry.h"

using namespace std;

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

class TypeSpec 
{
private:
    union ContInfo 
    {
        struct 
        {
            int arrLength;
            TypeSpec *indexType;
            TypeSpec *elementType;
        } ARRAY;

        struct 
        {
            int subrMin;
            int subrMax;
            TypeSpec *baseType;
        } SUBRANGE;
        
        struct 
        {
            string type;
            SymTab *symTab;
        } RECORD;

        struct 
        {
            vector <SymTabEntry*> *enums;
        } ENUMERATION;
        
    };
    Container CONT;
    SymTabEntry *ID;
    static ContInfo inf;

public:
    TypeSpec() : CONT((Container) -1), ID(nullptr) {}

    TypeSpec(Container Cont) : CONT(Cont), ID(nullptr)
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

    virtual ~TypeSpec(){}

    //GETTERS
    bool isArrRec() {return (CONT == Container::ARRAY)|| (CONT == Container::RECORD);}

    Container getCont() {return CONT;}

    int getArrLength() {return inf.ARRAY.arrLength;}

    TypeSpec *getArrElemType() {return inf.ARRAY.elementType;}
    
    TypeSpec *getArrIndexType() {return inf.ARRAY.indexType;}

    TypeSpec *getSubrBaseType() {return inf.SUBRANGE.baseType;}

    int getSubrMax() {return inf.SUBRANGE.subrMax;}

    int getSubrMin() {return inf.SUBRANGE.subrMin;}

    string getRecType() {return inf.RECORD.type;}

    SymTab *getRecSymTab() {return inf.RECORD.symTab;}

    vector <SymTabEntry*> *getEnums() {return inf.ENUMERATION.enums;}

    //SETTERS
    void setArrLength(int x) {inf.ARRAY.arrLength = x;}

    void setArrElemType(TypeSpec *x) {inf.ARRAY.elementType = x;}
    
    void setArrIndexType(TypeSpec *x) {inf.ARRAY.indexType = x;}

    void setSubrBaseType(TypeSpec *x) {inf.SUBRANGE.baseType = x;}

    void setSubrMax(int x) {inf.SUBRANGE.subrMax = x;}

    void setSubrMin(int x) {inf.SUBRANGE.subrMin = x;}

    void setRecType(string x) {inf.RECORD.type = x;}

    void setRecSymTab(SymTab *x) {inf.RECORD.symTab = x;}

    void setEnums(vector <SymTabEntry*> *x) {inf.ENUMERATION.enums = x;}
};

#endif // TYPESPEC_H_