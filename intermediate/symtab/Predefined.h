#ifndef PREDEFINED_H_
#define PREDEFINED_H_

#include <vector>

#include "../../Object.h"
#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"

namespace intermediate { namespace symtab {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class Predefined
{
public:
    static Typespec *integerType;
    static Typespec *realType;
    static Typespec *booleanType;
    static Typespec *charType;
    static Typespec *stringType;
    static Typespec *undefinedType;

    static SymtabEntry *integerID;
    static SymtabEntry *realID;
    static SymtabEntry *booleanID;
    static SymtabEntry *charID;
    static SymtabEntry *stringID;
    static SymtabEntry *falseID;
    static SymtabEntry *trueID;

    static void Predefined::initialize(SymtabStack *symtabStack) {
        initializeConstants(symtabStack);
        initializeTypes(symtabStack);
    }

private:
    static void initializeConstants(SymtabStack *symtabStack) {
        trueID = symtabStack->enterLocal("true", ENUMERATION_CONSTANT);
        trueID->setValue(1);
        trueID->setType(booleanType);

        falseID = symtabStack->enterLocal("false", ENUMERATION_CONSTANT);
        falseID->setValue(0);
        falseID->setType(booleanType);

        vector<SymtabEntry *> *constants = new vector<SymtabEntry *>;
        constants->push_back(trueID);
        constants->push_back(falseID);
        booleanType->setEnumerationConstants(constants);
    }

    static void initializeTypes(SymtabStack *symtabStack) {
        integerID = symtabStack->enterLocal("integer", TYPE);
        integerType = new Typespec(SCALAR);
        integerType->setIdentifier(integerID);
        integerID->setType(integerType);

        realID = symtabStack->enterLocal("real", TYPE);
        realType = new Typespec(SCALAR);
        realType->setIdentifier(realID);
        realID->setType(realType);

        booleanID = symtabStack->enterLocal("boolean", TYPE);
        booleanType = new Typespec(ENUMERATION);
        booleanType->setIdentifier(booleanID);
        booleanID->setType(booleanType);

        charID = symtabStack->enterLocal("char", TYPE);
        charType = new Typespec(SCALAR);
        charType->setIdentifier(charID);
        charID->setType(charType);

        stringID = symtabStack->enterLocal("string", TYPE);
        stringType = new Typespec(SCALAR);
        stringType->setIdentifier(stringID);
        stringID->setType(stringType);

        undefinedType = new Typespec(SCALAR);
    }
};

}}

#endif /* PREDEFINED_H_ */
