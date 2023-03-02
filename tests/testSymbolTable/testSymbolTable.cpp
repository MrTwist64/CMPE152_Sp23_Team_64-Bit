#include <iostream>
#include <string>
#include "../../symTab.h"
#include "../../symTabEntry.h"
using namespace std;


int main()
{
    SymTab myTable;
    myTable.newEntry(Kind::VARIABLE, "alpha").setValue(17);
    myTable.newEntry(Kind::VARIABLE, "beta").setValue(24);
    myTable.newEntry(Kind::VARIABLE, "i").setValue(0);
    myTable.newEntry(Kind::VARIABLE, "foo").setValue(19);
    cout << myTable.toString() << endl;
    return 0;
}