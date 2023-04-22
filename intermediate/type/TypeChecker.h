#ifndef TYPECHECKER_H_
#define TYPECHECKER_H_

#include "../symtab/Symtab.h"
#include "../symtab/Predefined.h"

namespace intermediate { namespace type {

using namespace std;
using namespace symtab;

class TypeChecker
{
private:
    Predefined *pred;

public:
    TypeChecker(Predefined *pred) 
    {
        this->pred = pred;
    }

    bool isInteger(Typespec *typespec) 
    {
        return (typespec != nullptr) 
            && (typespec->baseType() == pred->integerType);
    }

    bool areBothInteger(Typespec *typespec1, Typespec *typespec2) 
    {
        return isInteger(typespec1) 
            && isInteger(typespec2);
    }

    bool areBothString(Typespec *typespec1, Typespec *typespec2) 
    {
        return isString(typespec1) && isString(typespec2);
    }

    bool isReal(Typespec *typespec) 
    {
        return (typespec != nullptr) && (typespec->baseType() == pred->realType);
    }

    bool isIntegerOrReal(Typespec *typespec) 
    {
        return isInteger(typespec) || isReal(typespec);
    }

    bool isAtLeastOneReal(Typespec *typespec1, Typespec *typespec2) 
    {
        return (isReal(typespec1) && isReal(typespec2)) 
            || (isReal(typespec1) && isInteger(typespec2)) 
            || (isInteger(typespec1) && isReal(typespec2));
    }

    bool isBoolean(Typespec *typespec) 
    {
        return (typespec != nullptr)
            && (typespec->baseType() == pred->booleanType);
    }

    bool areBothBoolean(Typespec *typespec1, Typespec *typespec2) 
    {
        return isBoolean(typespec1) && isBoolean(typespec2);
    }

    bool isChar(Typespec *typespec) 
    {
        return (typespec != nullptr)
            && (typespec->baseType() == pred->charType);
    }

    bool isString(Typespec *typespec) 
    {
        return (typespec != nullptr)
            && (typespec->baseType() == pred->stringType);
    }

    bool areAssignmentCompatible(Typespec *targetType, Typespec *valueType) 
    {
        if ((targetType == nullptr) || (valueType == nullptr))
        {
            if (targetType == nullptr)
                cout << "lhs is null" << endl;
            if (valueType == nullptr)
                cout << "rhs is null" << endl;
            return false; 
        } 
            

        targetType = targetType->baseType();
        valueType  = valueType->baseType();

        bool compatible = false;

        if (targetType == valueType) 
            compatible = true;
        else if (isReal(targetType) && isInteger(valueType)) 
            compatible = true;

        return compatible;
    }

    bool areComparisonCompatible(Typespec *type1, Typespec *type2) 
    {
        if ((type1 == nullptr) || (type2 == nullptr))
            return false;

        type1 = type1->baseType();
        type2 = type2->baseType();
        Form form = type1->getForm();

        bool compatible = false;

        if ((type1 == type2) && ((form == SCALAR) || (form == ENUMERATION)))
            compatible = true;
        else if (isAtLeastOneReal(type1, type2)) 
            compatible = true;

        return compatible;
    }
};

}}

#endif // TYPECHECKER_H_