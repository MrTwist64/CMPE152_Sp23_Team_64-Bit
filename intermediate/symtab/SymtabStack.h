#ifndef SYMTABSTACK_H_
#define SYMTABSTACK_H_

#include <vector>
#include "Symtab.h"
#include "SymtabEntry.h"

namespace intermediate { namespace symtab {
    
class SymtabEntry;
class Symtab;

class SymtabStack 
{
private:
    int nesting_level;
    SymtabEntry *programID;
    vector<Symtab*> stack;

 public:
    SymtabStack(): nesting_level(0), programID(nullptr)
    {   
        stack.push_back(new Symtab(0));
    }

    int getCurrNestingLevel() 
    {
        return nesting_level;
    }

    SymtabEntry *getProgID() 
    {
        return programID;
    }
    
    void setProgID(SymtabEntry *ID) 
    {
        programID = ID;
    }
    
    Symtab *getLocalSymtab() 
    {
        return stack[nesting_level];
    }
    
    Symtab *push () 
    {
        Symtab *symtab = new Symtab(++nesting_level);
        stack.push_back(symtab);
        return symtab;
    }
    
    Symtab *push(Symtab *symtab) 
    {
        nesting_level++;
        stack.push_back(symtab);
        return symtab;
    }

    Symtab *pop() {
        Symtab *symtab = stack[nesting_level];
        stack.erase(stack.begin() + nesting_level);
        nesting_level--;
        return symtab;
    }

    SymtabEntry *enterLocal(const string name, const Kind kind) {
        return stack[nesting_level]->newEntry(kind, name);
    }

    SymtabEntry *lookupLocal(const string name) const {
        return stack[nesting_level]->lookup(name);
    }

    SymtabEntry *lookup(const string name) const {
        SymtabEntry *found = nullptr;

        for (int i = nesting_level; i >=0 && found == nullptr; i--) {
            found = stack[i]->lookup(name);
        }

        return found;
    }

    string toString() {
        string temp = "";
        for (int i = nesting_level; i >= 0; i--)
        {
            temp += "Level " + to_string(i);
            if (i != 0)
                temp += ", Owner " + stack[i]->getOwner()->getName();
            temp += "\n";
            temp += stack[i]->toString("  ");
        }
        return temp;
    }
};

}}

#endif // SYMTABSTACK_H_