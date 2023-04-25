#include <string>

#include "Typespec.h"

namespace intermediate { namespace type {

using namespace std;
using namespace intermediate::type;

class ErrStr
{
private:
    // Get lineNum using ctx->getStart()->getLine()
    string errorStart(int lineNum)
    {
        string temp = "";
        temp += "Error [";
        temp += to_string(lineNum);
        temp += "]: ";
        return temp;
    }

public:
    string incompatibleAssignment(Typespec* type1, Typespec* type2, int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Incompatible assignment between ";
        temp += type1->getIdentifier()->getName();
        temp += " and ";
        temp += type2->getIdentifier()->getName();
        temp += ".";
        return temp;
    }

    string incompatibleComparison(Typespec* type1, Typespec* type2, int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Incompatible comparison between ";
        temp += type1->getIdentifier()->getName();
        temp += " and ";
        temp += type2->getIdentifier()->getName();
        temp += ".";
        return temp;
    }

    string incompatibleCaseConstant(Typespec* wrongType, Typespec* correctType, int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Type ";
        cout << "errStr1" << endl;
        temp += wrongType->getIdentifier()->getName();
        cout << "errStr2" << endl;
        temp += " cannot be compared with type ";
        temp += correctType->getIdentifier()->getName();
        cout << "errStr3" << endl;
        temp += ".";
        return temp;
    }

    string duplicateCaseConstant(int constant, int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Case constant ";
        temp += to_string(constant);
        temp += " already exists.";
        return temp;
    }
    
    string duplicateTypeDef(string name, int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Type definition " + name + " already exists.";
        return temp;
    }

    string constantNotFound(string name, int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Constant ";
        temp += name;
        temp += " not found.";
        return temp;
    }

    string variableNotFound(string name, int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Variable ";
        temp += name;
        temp += " not found.";
        return temp;
    }

    string typeNotCorrect(Typespec* wrongType, string correctType, int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Type must be " + correctType + ", not ";
        temp += wrongType->getIdentifier()->getName();
        temp += ".";
        return temp;
    }

    string typeNotCorrect(int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Type is incorrect.";
        return temp;
    }

    string kindNotCorrect(string wrongKind, string correctKind, int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Kind must be " + correctKind + ", not " + wrongKind + ".";
        return temp;
    }
    
    string countNotEqual(int lineNum)
    {
        string temp = "";
        temp += errorStart(lineNum);
        temp += "Argument count mismatch.";
        return temp;
    }

};

}}