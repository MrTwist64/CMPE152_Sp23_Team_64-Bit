#include <iostream>
#include <string>
#include "symTab.h"
#include "symTabEntry.h"
using namespace std;


int main()
{
    SymTab myTable;
    myTable.newEntry(Kind::variable, "alpha").setValue(17);
    myTable.newEntry(Kind::variable, "beta").setValue(24);
    myTable.newEntry(Kind::variable, "i").setValue(0);
    myTable.newEntry(Kind::variable, "foo").setValue(19);
    myTable.print();
    return 0;
}