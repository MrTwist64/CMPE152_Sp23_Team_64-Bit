#include <iostream>
#include <string>
#include "../../symTab.h"
#include "../../symTabEntry.h"
using namespace std;


int main()
{
    SymTab myTable;
    myTable.newEntry(Kind::VARIABLE, "alpha")->setValue(17);
    myTable.newEntry(Kind::VARIABLE, "beta")->setValue(24);
    myTable.newEntry(Kind::VARIABLE, "i")->setValue(0);
    myTable.newEntry(Kind::VARIABLE, "foo")->setValue(19);
    cout << myTable.lookup("alpha")->getName() << ": " << myTable.lookup("alpha")->getValue() << endl;
    cout << myTable.lookup("beta")->getName() << ": " << myTable.lookup("beta")->getValue() << endl;
    cout << myTable.lookup("i")->getName() << ": " << myTable.lookup("i")->getValue() << endl;
    cout << myTable.lookup("foo")->getName() << ": " << myTable.lookup("foo")->getValue() << endl;
    return 0;
}