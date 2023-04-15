/**
 * <h1>SymtabEntry</h1>
 *
 * <p>The symbol table entry for various kinds of identifiers.</p>
 *
 * <p>Copyright (c) 2020 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>
#include <vector>

#include "antlr4-runtime.h"

#include "../../Object.h"

// Forward declaration of class Typespec in namespace intermediate::type.
namespace intermediate { namespace type {
    class Typespec;
}};

namespace intermediate { namespace symtab {

using namespace std;
using intermediate::type::Typespec;

// More forward class declarations but in the same namespace.
class Symtab;
class SymtabEntry;

/**
 * What kind of identifier.
 */
enum class Kind
{
    CONSTANT, ENUMERATION_CONSTANT, TYPE, VARIABLE, RECORD_FIELD,
    VALUE_PARAMETER, REFERENCE_PARAMETER, PROGRAM_PARAMETER,
    PROGRAM, PROCEDURE, FUNCTION,
    UNDEFINED
};

static const string KIND_STRINGS[] =
{
    "constant", "enumeration constant", "type", "variable", "record field",
    "value parameter", "reference parameter", "program parameter",
    "PROGRAM", "PROCEDURE", "FUNCTION",
    "undefined"
};

constexpr Kind CONSTANT             = Kind::CONSTANT;
constexpr Kind ENUMERATION_CONSTANT = Kind::ENUMERATION_CONSTANT;
constexpr Kind TYPE                 = Kind::TYPE;
constexpr Kind VARIABLE             = Kind::VARIABLE;
constexpr Kind RECORD_FIELD         = Kind::RECORD_FIELD;
constexpr Kind VALUE_PARAMETER      = Kind::VALUE_PARAMETER;
constexpr Kind REFERENCE_PARAMETER  = Kind::REFERENCE_PARAMETER;
constexpr Kind PROGRAM_PARAMETER    = Kind::PROGRAM_PARAMETER;
constexpr Kind PROGRAM              = Kind::PROGRAM;
constexpr Kind PROCEDURE            = Kind::PROCEDURE;
constexpr Kind FUNCTION             = Kind::FUNCTION;
constexpr Kind UNDEFINED            = Kind::UNDEFINED;

class SymtabEntry
{
private:
    /**
     * Information for each kind of identifier.
     */
    union EntryInfo
    {
        struct
        {
            Object *value;
        } data;
    };

    string name;              // identifier name
    Kind kind;                // what kind of identifier
    Symtab   *symtab;         // parent symbol table
    Typespec *typespec;       // type specification
    vector<int> lineNumbers;  // source line numbers
    EntryInfo info;           // entry information

public:
    /**
     * Constructor.
     * @param name the name of the entry.
     * @param kind the kind of entry.
     * @param symTab the symbol table that contains this entry.
     */
    SymtabEntry(const string name, const Kind kind, Symtab *symtab)
        : name(name), kind(kind), symtab(symtab), typespec(nullptr)
    {
        switch (kind)
        {
            case Kind::CONSTANT:
            case Kind::ENUMERATION_CONSTANT:
            case Kind::VARIABLE:
            case Kind::RECORD_FIELD:
            case Kind::VALUE_PARAMETER:
                info.data.value = nullptr;
                break;

            default: break;
        }
    }

    /**
     * Destructor.
     */
    virtual ~SymtabEntry() {}

    /**
     * Get the name of the entry.
     * @return the name.
     */
    string getName() const { return name; }

    /**
     * Get the kind of entry.
     * @return the kind.
     */
    Kind getKind() const { return kind; }

    /**
     * Set the kind of entry.
     * @param kind the kind to set.
     */
    void setKind(Kind kind) { this->kind = kind; }

    /**
     * Getter.
     * @return the symbol table that contains this entry.
     */
    Symtab *getSymtab() const { return symtab; }

    /**
     * Getter.
     * @return the type specification.
     */
    Typespec *getType() const { return typespec; }

    /**
     * Setter.
     * @param typespec the type specification to set.
     */
    void setType(Typespec *typespec) { this->typespec = typespec; }

    /**
     * Getter.
     * @return the list of source line numbers.
     */
    vector<int> *getLineNumbers() { return &lineNumbers; }

    /**
     * Append a source line number to the entry.
     * @param _number the line number to append.
     */
    void appendLineNumber(const int _number)
    {
        lineNumbers.push_back(_number);
    }

    /**
     * Get the data value stored with this entry.
     * @return the data value.
     */
    Object getValue() const { return *(info.data.value); }

    /**
     * Set the data value into this entry.
     * @parm value the value to set.
     */
    void setValue(Object value) { info.data.value = new Object(value); }
};

}}  // namespace intermediate::symtab

#endif /* SYMTABENTRY_H_ */
