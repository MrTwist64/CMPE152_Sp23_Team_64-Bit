#include <iostream>
#include <string>
#include "../../../intermediate/symtab/SymtabStack.h"
#include "../../../intermediate/symtab/SymtabEntry.h"

using namespace std;
using namespace intermediate::symtab;

int main()
{
    // Symtab myTable(0);
    // myTable.newEntry(Kind::VARIABLE, "alpha")->setValue(17);
    // myTable.newEntry(Kind::VARIABLE, "beta")->setValue(24);
    // myTable.newEntry(Kind::VARIABLE, "i")->setValue(0);
    // myTable.newEntry(Kind::VARIABLE, "foo")->setValue(19);
    // cout << myTable.toString();
    
    SymtabStack stack;
    stack.enterLocal("integer", Kind::TYPE);
    Symtab *myTable = new Symtab(1);
    stack.push(myTable);

    SymtabEntry *temp;
    temp = stack.enterLocal("alpha", Kind::VARIABLE);
    temp->setValue(17);
    temp = stack.enterLocal("beta", Kind::VARIABLE);
    temp->setValue(24);
    temp = stack.enterLocal("i", Kind::VARIABLE);
    temp->setValue(0);
    temp = stack.enterLocal("foo", Kind::VARIABLE);
    temp->setValue(19);

    // temp = stack.lookupLocal("integer");
    // if(temp)
    //     cout << static_cast<int>(temp->getValue()) << endl;
    // else
    //     cout << "Not found" << endl;

    //cout << &temp->getValue() << endl;
    return 0;
}