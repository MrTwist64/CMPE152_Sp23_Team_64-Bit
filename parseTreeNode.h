#ifndef PARSETREENODE_H_
#define PARSETREENODE_H_

#include<iostream>
#include<string>
#include<vector>
#include "symTab.h"
#include "symTabEntry.h"

class SymTab;
class SymTabEntry;

using namespace std;

enum class NodeType
{
    PROGRAM, IDENTIFIER, BLOCK, LABEL, UNSIGNED_INTEGER, STATEMENT_PART, COMPOUND_STATEMENT, STATEMENT,
    UNLABELED_STATEMENT, SIMPLE_STATEMENT, ASSIGNMENT_STATEMENT, VARIABLE, ENTIRE_VARIABLE,
    VARIABLE_IDENTIFIER, COMPONENT_VARIABLE, INDEXED_VARIABLE, ARRAY_VARIABLE, FIELD_DESIGNATOR, 
    EXPRESSION, RELATIONAL_OPERATOR, SIMPLE_EXPRESSION, FILE_BUFFER, FIELD_IDENTIFIER, FILE_VARIABLE, 
    POINTER_VARIABLE, REFERENCED_VARIABLE, GOTO_STATEMENT, TERM, FUNCTION_IDENTIFIER, FACTOR, UNSIGNED_CONSTANT,
    ADDING_OPERATOR, MULTIPLYING_OPERATOR, FUNCTION_DESIGNATOR, SET, ELEMENT_LIST, EMPTY_STATEMENT,
    EMPTY, ELEMENT, STRUCTURED_STATEMENT, WITH_STATEMENT, REPETITIVE_STATEMENT, RECORD_VARIABLE_TYPE,
    REPEAT_STATEMENT, CONDITIONAL_STATEMENT, IF_STATEMENT, WHILE_STATEMENT, CASE_LIST_ELEMENT, CASE_LABEL_LIST,
    CASE_LABEL, CONSTANT, UNSIGNED_NUMBER, UNSIGNED_REAL, SIGN, CONSTANT_IDENTIFIER,
    FOR_STATEMENT, CONTROL_VARIABLE, FOR_LIST, INITIAL_VALUE, FINAL_VALUE, TYPE, SIMPLE_TYPE, SCALAR_TYPE,
    SUBRANGE_TYPE, TYPE_IDENTIFIER, STRUCTURED_TYPE, INDEX_TYPE, COMPONENT_TYPE, RECORD_TYPE, FIELD_LIST, 
    TAG_FIELD, VARIANT, SET_TYPE, BASE_TYPE, FILE_TYPE, POINTER_TYPE, RESULT_TYPE, STRING, 
    VARIANT_TYPE, ARRAY_TYPE, FIXED_PART, RECORD_SECTION, CASE_STATEMENT
};

static const string KIND_STRINGS[] = {
    "PROGRAM", "IDENTIFIER", "BLOCK", "LABEL", "UNSIGNED_INTEGER", "STATEMENT_PART", "COMPOUND_STATEMENT", "STATEMENT",
    "UNLABELED_STATEMENT", "SIMPLE_STATEMENT", "ASSIGNMENT_STATEMENT", "VARIABLE", "ENTIRE_VARIABLE",
    "VARIABLE_IDENTIFIER", "COMPONENT_VARIABLE", "INDEXED_VARIABLE", "ARRAY_VARIABLE", "FIELD_DESIGNATOR",
    "EXPRESSION", "RELATIONAL_OPERATOR", "SIMPLE_EXPRESSION", "FILE_BUFFER", "FIELD_IDENTIFIER", "FILE_VARIABLE",
    "POINTER_VARIABLE", "REFERENCED_VARIABLE", "GOTO_STATEMENT", "TERM", "FUNCTION_IDENTIFIER", "FACTOR", "UNSIGNED_CONSTANT",
    "ADDING_OPERATOR", "MULTIPLYING_OPERATOR", "FUNCTION_DESIGNATOR", "SET", "ELEMENT_LIST", "EMPTY_STATEMENT",
    "EMPTY", "ELEMENT", "STRUCTURED_STATEMENT", "WITH_STATEMENT", "REPETITIVE_STATEMENT", "RECORD_VARIABLE_TYPE",
    "REPEAT_STATEMENT", "CONDITIONAL_STATEMENT", "IF_STATEMENT", "WHILE_STATEMENT", "CASE_LIST_ELEMENT", "CASE_LABEL_LIST",
    "CASE_LABEL", "CONSTANT", "UNSIGNED_NUMBER", "UNSIGNED_REAL", "SIGN", "CONSTANT_IDENTIFIER",
    "FOR_STATEMENT", "CONTROL_VARIABLE", "FOR_LIST", "INITIAL_VALUE", "FINAL_VALUE", "TYPE", "SIMPLE_TYPE", "SCALAR_TYPE", 
    "SUBRANGE_TYPE", "TYPE_IDENTIFIER", "STRUCTURED_TYPE", "INDEX_TYPE", "COMPONENT_TYPE", "RECORD_TYPE", "FIELD_LIST", 
    "TAG_FIELD", "VARIANT", "SET_TYPE", "BASE_TYPE", "FILE_TYPE", "POINTER_TYPE", "RESULT_TYPE", "STRING", 
    "VARIANT_TYPE", "ARRAY_TYPE", "FIXED_PART", "RECORD_SECTION", "CASE_STATEMENT"
};

class parseTreeNode
{
private:
    vector<parseTreeNode*> children;
    parseTreeNode* parent;
    NodeType type;
    string name;
    int value;
    bool nameSet, valueSet;

public:
    parseTreeNode(NodeType type) : type(type)
    {
        nameSet = false;
        valueSet = false;
    }

    bool isNameSet() {return nameSet;}
    bool isValueSet() {return valueSet;}

    // Getters
    string getName() {return this->name;}
    int getValue() {return this->value;}
    NodeType getType() {return this->type;}
    string getTypeStr() {return KIND_STRINGS[static_cast<int>(this->type)];}
    vector<parseTreeNode*> getChildren() {return children;}
    parseTreeNode* getParent() {return this->parent;}

    // Setters
    void setName(string name) {this->name = name; nameSet = true;}
    void setValue(int value) {this->value = value; valueSet = true;}
    void setType(NodeType type) {this->type = type;}
    void setParent(parseTreeNode* parent) {this->parent = parent;}
    void adopt(parseTreeNode *newChild) {this->children.push_back(newChild);}

    SymTabEntry searchSymTable(string variableName)
    {
        SymTab SymbolTable;
        
        //found
        SymTabEntry* findSymTabEntry = SymbolTable.lookup(variableName);
        if(findSymTabEntry != nullptr)
        {
            return *findSymTabEntry;
        }
        else
        {
            //SymTabEntry* newEntry = &SymbolTable.newEntry(Kind::VARIABLE, variableName);
            //return *newEntry;
        }
    }


};

/*
    ----- TEMPLATES -----

    parseTreeNode * parseFunction()
    {

    }

        if (scn.getCurrToken() != "RECONGNIZED_TOKEN")
            return NULL;
        scn.nextToken();

        parseTreeNode* x = parseX();
        if(!x)
            return NULL;
        
        parseTreeNode* yNode = parseTree->createNode(NodeType::Y);
        yNode->adopt(xNode);
        return yNode;
    */

#endif // PARSETREENODE_H_