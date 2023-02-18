/**
 * <h1>Typespec</h1>
 *
 * <p>The type specification object for various datatypes.</p>
 *
 * <p>Copyright (c) 2020 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <string>
#include <vector>

#include "../../Object.h"
#include "intermediate/symtab/Symtab.h"

namespace intermediate { namespace type {

using namespace std;
using namespace intermediate::symtab;

/**
 * The form of the datatype.
 */
enum class Form
{
    SCALAR, ENUMERATION, SUBRANGE, ARRAY, RECORD,
};

static const string FORM_STRINGS[] =
{
    "scalar", "enumeration", "subrange", "array", "record"
};

constexpr Form SCALAR      = Form::SCALAR;
constexpr Form ENUMERATION = Form::ENUMERATION;
constexpr Form SUBRANGE    = Form::SUBRANGE;
constexpr Form ARRAY       = Form::ARRAY;
constexpr Form RECORD      = Form::RECORD;

class Typespec;  // forward

class Typespec
{
private:
    /**
     * Information for each type form.
     */
    union TypeInfo
    {
        struct
        {
            vector<SymtabEntry *> *constants;
        } enumeration;

        struct
        {
            Typespec *baseType;
            int minValue;
            int maxValue;
        } subrange;

        struct
        {
            Typespec *indexType;
            Typespec *elementType;
            int elementCount;
        } array;

        struct
        {
            string *typePath;
            Symtab *symtab;
        } record;
    };

    Form form;
    SymtabEntry *identifier;  // type identifier
    TypeInfo info;

public:
    /**
     * Constructor.
     * @param form the type form.
     */
    Typespec() : form((Form) -1), identifier(nullptr) {}

    /**
     * Constructor.
     * @param form the type form.
     */
    Typespec(Form form) : form(form), identifier(nullptr)
    {
        switch (form)
        {
            case Form::ENUMERATION:
                info.enumeration.constants = new vector<SymtabEntry *>();
                break;

            case Form::SUBRANGE:
                info.subrange.minValue = 0;
                info.subrange.maxValue = 0;
                info.subrange.baseType = nullptr;
                break;

            case Form::ARRAY:
                info.array.indexType = nullptr;
                info.array.elementType = nullptr;
                info.array.elementCount = 0;
                break;

            case Form::RECORD:
                info.record.typePath = nullptr;
                info.record.symtab = nullptr;
                break;

            default: break;
        }
    }

    /**
     * Destructor.
     */
    virtual ~Typespec() {}

    /**
     * Determine whether or not the type is structured (array or record).
     * @return true if structured, false if not.
     */
    bool isStructured() const
    {
        return (form == ARRAY) || (form == RECORD);
    }

    /**
     * Get the type form.
     * @return the form.
     */
    Form getForm() const { return form; }

    /**
     * Get the type identifier's symbol table entry.
     * @return the symbol table entry.
     */
    SymtabEntry *getIdentifier() const { return identifier; }

    /**
     * Set the type identifier's symbol table entry.
     * @param identifier the symbol table entry.
     */
    void setIdentifier(SymtabEntry *identifier) { this->identifier = identifier; }

    /**
     * Return the base type of this type.
     * @return the base type.
     */
    Typespec *baseType()
    {
        return form == Form::SUBRANGE ? info.subrange.baseType : this;
    }

    /**
     * Get the subrange base type.
     * @return the base type.
     */
    Typespec *getSubrangeBaseType()
    {
        return info.subrange.baseType;
    }

    /**
     * Set the subrange base type.
     * @param baseType the base type to set.
     */
    void setSubrangeBaseType(Typespec *baseType)
    {
        info.subrange.baseType = baseType;
    }

    /**
     * Get the subrange minimum value.
     * @return the value.
     */
    int getSubrangeMinValue() const { return info.subrange.minValue; }

    /**
     * Set the subrange minimum value.
     * @param min_value the value to set.
     */
    void setSubrangeMinValue(const int min_value)
    {
        info.subrange.minValue = min_value;
    }

    /**
     * Get the subrange maximum value.
     * @return the value.
     */
    int getSubrangeMaxValue() const { return info.subrange.maxValue; }

    /**
     * Set the subrange maximum value.
     * @param max_value the value to set.
     */
    void setSubrangeMaxValue(const int max_value)
    {
        info.subrange.maxValue = max_value;
    }

    /**
     * Get the vector of enumeration constants symbol table entries.
     * @return the vector.
     */
    vector<SymtabEntry *> *getEnumerationConstants() const
    {
        return info.enumeration.constants;
    }

    /**
     * Set the vector of enumeration constants symbol table entries.
     * @parm constants the vector to set.
     */
    void setEnumerationConstants(vector<SymtabEntry *> *constants)
    {
        info.enumeration.constants = constants;
    }

    /**
     * Get the array index data type.
     * @return the data type.
     */
    Typespec *getArrayIndexType() const { return info.array.indexType; }

    /**
     * Set the array index data type.
     * @parm index_type the data type to set.
     */
    void setArrayIndexType(Typespec *index_type)
    {
        info.array.indexType = index_type;
    }

    /**
     * Get the array element data type.
     * @return the data type.
     */
    Typespec *getArrayElementType() const { return info.array.elementType; }

    /**
     * Set the array element data type.
     * @return elmt_type the data type to set.
     */
    void setArrayElementType(Typespec *elmt_type)
    {
        info.array.elementType = elmt_type;
    }

    /**
     * Get the array element count.
     * @return the count.
     */
    int getArrayElementCount() const { return info.array.elementCount; }

    /**
     * Set the array element count.
     * @parm elmt_count the count to set.
     */
    void setArrayElementCount(const int elmt_count)
    {
        info.array.elementCount = elmt_count;
    }

    /**
     * Get the base type of an array.
     * @return the base type of its final dimension.
     */
    Typespec *getArrayBaseType()
    {
        Typespec*elmtType = this;

        while (elmtType->form == ARRAY)
        {
            elmtType = elmtType->getArrayElementType();
        }

        return elmtType->baseType();
    }

    /**
     * Get the record's symbol table.
     * @return the symbol table.
     */
    Symtab *getRecordSymtab() const { return info.record.symtab; }

    /**
     * Set the record's symbol table.
     * @parm symtab the symbol table to set.
     */
    void setRecordSymtab(Symtab *symtab)
    {
        info.record.symtab = symtab;
    }

    /**
     * Get a record type's fully qualified type path.
     * @return the path.
     */
    string getRecordTypePath() { return *(info.record.typePath); }

    /**
     * Set a record type's fully qualified type path.
     * @param typePath the path to set.
     */
    void setRecordTypePath(string typePath)
    {
        info.record.typePath = new string(typePath);
    }
};

}}  // namespace intermediate::type

#endif /* TYPESPEC_H_ */
