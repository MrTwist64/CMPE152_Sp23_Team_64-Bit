/**
 * <h1>SymtabStack</h1>
 *
 * <p>The symbol table stack.</p>
 *
 * <p>Copyright (c) 2020 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef SYMTABSTACK_H_
#define SYMTABSTACK_H_

#include <vector>

#include "Symtab.h"
#include "SymtabEntry.h"

namespace intermediate { namespace symtab {

using namespace std;
using namespace intermediate;

class SymtabStack
{
private:
    int current_nesting_level;  // current scope nesting level
    SymtabEntry *program_id;    // entry for the main program id

    vector<Symtab *> stack;

public:
    /**
     * Constructor.
     */
    SymtabStack() : current_nesting_level(0), program_id(nullptr)
    {
        stack.push_back(new Symtab(0));
    }

    /**
     * Destructor.
     */
    virtual ~SymtabStack()
    {
        for (Symtab *symtab : stack) if (symtab != nullptr) delete symtab;
    }

    /**
     * Getter.
     * @return the current nesting level.
     */
    int getCurrentNestingLevel() const { return current_nesting_level; }

    /**
     * Getter.
     * @return the symbol table entry for the main program identifier.
     */
    SymtabEntry *getProgramId() const { return program_id; }

    /**
     * Setter.
     * @param entry the symbol table entry for the main program identifier.
     */
    void setProgramId(SymtabEntry *id) { program_id = id; }

    /**
     * Return the local symbol table which is at the top of the stack.
     * @return the local symbol table.
     */
    Symtab *getLocalSymtab() const { return stack[current_nesting_level]; }

    /**
     * Push a new symbol table onto the stack.
     * @return the pushed symbol table.
     */
    Symtab *push()
    {
        Symtab *symtab = new Symtab(++current_nesting_level);
        stack.push_back(symtab);

        return symtab;
    }

    /**
     * Push a symbol table onto the stack.
     * @param symtab the symbol table to push.
     * @return the pushed symbol table.
     */
    Symtab *push(Symtab *symtab)
    {
        ++current_nesting_level;
        stack.push_back(symtab);

        return symtab;
    }

    /**
     * Pop a symbol table off the stack.
     * @return the popped symbol table.
     */
    Symtab *pop()
    {
        Symtab *symtab = stack[current_nesting_level];
        stack.erase(stack.begin() + current_nesting_level);
        current_nesting_level--;

        return symtab;
    }

    /**
     * Create and enter a new entry into the local symbol table.
     * @param name the name of the entry.
     * @param kind what kind of entry.
     * @return the new entry.
     */
    SymtabEntry *enterLocal(const string name, const Kind kind)
    {
        return stack[current_nesting_level]->enter(name, kind);
    }

    /**
     * Look up an existing symbol table entry in the local symbol table.
     * @param name the name of the entry.
     * @return the entry, or null if it does not exist.
     */
    SymtabEntry *lookupLocal(const string name) const
    {
        return stack[current_nesting_level]->lookup(name);
    }

    /**
     * Look up an existing symbol table entry throughout the stack.
     * @param name the name of the entry.
     * @return the entry, or null if it does not exist.
     */
    SymtabEntry *lookup(const string name) const
    {
        SymtabEntry *found_entry = nullptr;

        // Search the current and enclosing scopes.
        for (int i = current_nesting_level;
             (i >= 0) && (found_entry == nullptr); --i)
        {
            found_entry = stack[i]->lookup(name);
        }

        return found_entry;
    }
};

}}  // namespace intermediate::symtab

#endif /* SYMTABSTACK_H_ */
