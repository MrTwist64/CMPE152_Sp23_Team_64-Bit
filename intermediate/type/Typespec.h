#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <vector>
#include <string>
#include "../symtab/Symtab.h"
#include "../symtab/SymtabEntry.h"
#include "../../Object.h" 

namespace intermediate { namespace symtab {
class Symtab;
class SymtabEntry;
}}

namespace intermediate { namespace type {

using namespace std;
using namespace symtab;

class Typespec;

enum class Form
{
    ARRAY, SUBRANGE, RECORD, SCALAR, ENUMERATION,
};

static const string FORM_STRINGS[] = {"array", "subrange", "record", "scalar", "enumeration"};

constexpr Form ARRAY = Form::ARRAY;
constexpr Form SUBRANGE = Form::SUBRANGE;
constexpr Form RECORD = Form::RECORD;
constexpr Form SCALAR = Form::SCALAR;
constexpr Form ENUMERATION = Form::ENUMERATION;

class Typespec 
{
private:
    union TypeInfo 
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
            string *type;
            Symtab *symTab;
        } RECORD;

        struct 
        {
            vector <SymtabEntry*> *enums;
        } ENUMERATION;
        
    };
    Form form;
    SymtabEntry *identifier;
    TypeInfo info; 

public:
    Typespec() : form((Form) -1), identifier(nullptr) {}

    Typespec(Form form) : form(form), identifier(nullptr)
    {
        switch(form)
        {
            case Form::ARRAY: 
                info.ARRAY.arrLength = 0;
                info.ARRAY.elementType = nullptr;
                info.ARRAY.indexType = nullptr;
            break;

            case Form::SUBRANGE:
                info.SUBRANGE.baseType = nullptr;
                info.SUBRANGE.subrMax = 0;
                info.SUBRANGE.subrMin = 0;
            break;

            case Form::RECORD:
                info.RECORD.type = nullptr;
                info.RECORD.symTab = nullptr;
            break;

            case Form::ENUMERATION:
                info.ENUMERATION.enums = new vector<SymtabEntry *>();
            break;
            default:break;
        }
    }

    virtual ~Typespec() {}

    //GETTERS
    Typespec *baseType(){return this->form == Form::SUBRANGE ? info.SUBRANGE.baseType : this;}

    bool isArrRec() {return (this->form == Form::ARRAY) || (this->form == Form::RECORD);}

    Form getForm() {return form;}

    int getArrLength() {return info.ARRAY.arrLength;}

    Typespec *getArrElemType() {return info.ARRAY.elementType;}
    
    Typespec *getArrIndexType() {return info.ARRAY.indexType;}

    Typespec *getSubrBaseType() {return info.SUBRANGE.baseType;}

    int getSubrMax() {return info.SUBRANGE.subrMax;}

    int getSubrMin() {return info.SUBRANGE.subrMin;}

    string *getRecType() {return info.RECORD.type;}

    Symtab *getRecSymtab() {return info.RECORD.symTab;}

    vector <SymtabEntry*> *getEnums() {return info.ENUMERATION.enums;}

    SymtabEntry *getIdentifier() const {return identifier; }

    //SETTERS
    void setArrLength(int x) {info.ARRAY.arrLength = x;}

    void setArrElemType(Typespec *x) {info.ARRAY.elementType = x;}
    
    void setArrIndexType(Typespec *x) {info.ARRAY.indexType = x;}

    void setSubrBaseType(Typespec *x) {info.SUBRANGE.baseType = x;}

    void setSubrMax(int x) {info.SUBRANGE.subrMax = x;}

    void setSubrMin(int x) {info.SUBRANGE.subrMin = x;}

    void setRecType(string *x) {info.RECORD.type = x;}

    void setRecSymtab(Symtab *x) {info.RECORD.symTab = x;}

    void setEnumerationConstants(vector <SymtabEntry*> *x) {info.ENUMERATION.enums = x;}

    void setIdentifier(SymtabEntry *ID) {identifier = ID;}
};

}}

#endif // TYPESPEC_H_
