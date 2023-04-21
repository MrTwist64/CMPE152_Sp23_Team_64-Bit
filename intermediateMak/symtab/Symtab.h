/**
 * <h1>Symtab</h1>
 *
 * <p>The symbol table.</p>
 *
 * <p>Copyright (c) 2020 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef SYMTABIMPL_H_
#define SYMTABIMPL_H_

#include <string>
#include <map>

#include "SymtabEntry.h"

namespace intermediate { namespace symtab {

using namespace std;
using namespace intermediate;

#define UNNAMED_PREFIX string("_unnamed_")
#define UNNAMED_PREFIX_LENGTH UNNAMED_PREFIX.length()

class Symtab
{
private:
    int nestingLevel;                     // scope nesting level
    SymtabEntry *ownerId;                 // symbol table entry of the owner
    map<string, SymtabEntry *> contents;  // entries

    static int unnamedIndex;              // index for unnamed type names

public:
    /**
     * Constructor.
     * @param nesting_level the scope nesting level of this table
     */
    Symtab(const int nestingLevel)
        : nestingLevel(nestingLevel), ownerId(nullptr) {}

    /**
     * Destructor.
     */
    virtual ~Symtab() {}

    /**
     * Getter.
     * @return the scope nesting level of this entry.
     */
    int getNestingLevel() const { return nestingLevel; }

    /**
     * Generate a name for an unnamed type.
     * @return the name;
     */
    static string generateUnnamedName()
    {
        unnamedIndex++;
        return UNNAMED_PREFIX + to_string(unnamedIndex);
    }

    /**
     * Getter.
     * @return the owner of this symbol table.
     */
    SymtabEntry *getOwner() { return ownerId; }

    /**
     * Set the owner of this symbol table.
     * @param ownerId the symbol table entry of the owner.
     */
	void setOwner(SymtabEntry *ownerId) { this->ownerId = ownerId; }
	
    /**
     * Create and enter a new entry into the symbol table.
     * @param name the name of the entry.
     * @param kind the kind of entry.
     * @return the new entry.
     */
    SymtabEntry *enter(const string name, const Kind kind)
    {
        SymtabEntry *entry = new SymtabEntry(name, kind, this);
        contents[name] = entry;

        return entry;
    }

    /**
     * Look up an existing symbol table entry.
     * @param name the name of the entry.
     * @return the entry, or null if it does not exist.
     */
    SymtabEntry *lookup(const string name)
    {
        return (contents.find(name) != contents.end()) ? contents[name]
                                                       : nullptr;
    }

    /**
     * Return a vector of entries sorted by name.
     * @return the sorted vector.
     */
    vector<SymtabEntry *> sortedEntries()
    {
        vector<SymtabEntry *> list;
        map<string, SymtabEntry *>::iterator it;

        // Iterate over the sorted entries and append them to the list.
        for (it = contents.begin(); it != contents.end(); it++)
        {
            list.push_back(it->second);
        }

        return list;  // sorted list of entries
    }

    /**
     * Reset all the variable entries to a kind.
     * @param kind the kind to set.
     */
    void resetVariables(Kind kind)
    {
        vector<SymtabEntry *> list;
        map<string, SymtabEntry *>::iterator it;

        // Iterate over the entries and reset their kind.
        for (it = contents.begin(); it != contents.end(); it++)
        {
            SymtabEntry *entry = it->second;
            if (entry->getKind() == VARIABLE) entry->setKind(kind);
        }
    }
};

}}  // namespace intermediate::symtab

#endif /* SYMTABIMPL_H_ */
