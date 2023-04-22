#ifndef PREDEFINED_H_
#define PREDEFINED_H_

#include <vector>

#include "../../Object.h"
#include "SymtabStack.h"
#include "SymtabEntry.h"
#include "../type/Typespec.h"

namespace intermediate { namespace symtab {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class Predefined
{
public:
    Typespec *integerType;
    Typespec *realType;
    Typespec *booleanType;
    Typespec *charType;
    Typespec *stringType;
    Typespec *undefinedType;

    SymtabEntry *integerID;
    SymtabEntry *realID;
    SymtabEntry *booleanID;
    SymtabEntry *charID;
    SymtabEntry *stringID;
    SymtabEntry *falseID;
    SymtabEntry *trueID;

    void initialize(SymtabStack *symtabStack) {
        initializeTypes(symtabStack);
        initializeConstants(symtabStack);
    }

private:
    void initializeConstants(SymtabStack *symtabStack) {
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

    void initializeTypes(SymtabStack *symtabStack) {
        integerID = symtabStack->enterLocal("integer", Kind::TYPE);
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
