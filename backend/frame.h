#ifndef FRAME_H_
#define FRAME_H_

#include "../intermediate/symtab/Symtab.h"
#include "../intermediate/symtab/SymtabEntry.h"
#include <map>

using namespace intermediate::symtab;

class Frame 
{
private:
    Symtab* symtab;
    int scope;
    int size; // Also can be returnAddressOffset
    int scopeOffset;
    int addr;
    
    map<string, int> scalarSize = {
        {"integer", 3},
        {"boolean", 1},
        {"char", 1},
        {"real", 6},
    };
    map<string, int> offsets;

public:
    Frame(Symtab* symtab, int scope) : symtab(symtab), scope(scope)
    {
        size = 0;
        for(auto it = symtab->getSymtab()->begin(); it != symtab->getSymtab()->end(); ++it)
        {
            Typespec* type = it->second->getType();
            string typeName = type->getIdentifier()->getName();

            // TODO: CHECK IF SCALAR ONCE FUNCTIONS/ARRAYS/ETC ARE ADDED
            int entrySize = scalarSize[typeName];
            size += entrySize;

            offsets.emplace(it->first, size);

            cout << it->first << ":" << size << ":" << entrySize << endl;
        }

        size += 3; // For scope = integer = 3 bytes
        scopeOffset = size;
        size += 3; // For return address = 3 bytes
    }

    //getters n setters
    void setScope(int x) {scope = x;}
    int getScope() {return scope;}
    
    void setScopeOffset(int offset) {scopeOffset = offset;}
    int getScopeOffset() {return scopeOffset;}

    void setSize(int size){ this->size = size; }
    int getSize() {return size;}
    
    int getOffset(string name) {return offsets[name];}

    void setAddr(int addr) {this->addr = addr;}
    int getAddr() {return addr;}
};

#endif // FRAME_H_