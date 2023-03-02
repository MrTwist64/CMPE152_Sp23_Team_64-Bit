#ifndef PARSETREE_H_
#define PARSETREE_H_

#include "parseTreeNode.h"

using namespace std;

class ParseTree
{
private:
    parseTreeNode* root;

public:
    parseTreeNode* createNode(NodeType type)
    {
        parseTreeNode *node = new parseTreeNode(type);
        return node;
    }

    parseTreeNode *createNodeCopy(parseTreeNode *node)
    {
        parseTreeNode *newNode = new parseTreeNode(node->getType());
        newNode->setName(node->getName());
        newNode->setParent(node->getParent());
        newNode->setValue(node->getValue());
        return newNode;
    }

    void printTreeWalker() {printTreeWalker(0, root);}

    void printTreeWalker(parseTreeNode* node) {printTreeWalker(0, node);}

    void printTreeWalker(int level, parseTreeNode* node)
    {
        for(int i = 0; i < level; i++)
            cout << "    ";
        cout << "<" << node->getTypeStr();
        if(node->isNameSet())
            cout << " name=\"" << node->getName() << "\"";
        if(node->isValueSet())
            cout << " value=\"" << node->getValue() << "\"";
        
        vector<parseTreeNode*> children = node->getChildren();
        if(children.size() == 0)
        {
            cout << "/>" << endl;
            return;
        }
        cout << ">" << endl;

        for(auto & child : children)
        {
            printTreeWalker(level + 1, child);
        }
        
        for(int i = 0; i < level; i++)
            cout << "    ";
        cout << "<" << node->getTypeStr() << "/>" << endl;
    }

    // Local Getters
    parseTreeNode* getRoot() {return this->root;}

    // Local Setters
    void setRoot(parseTreeNode* newRoot) {this->root = newRoot;}

    // Pass Through Getters
    string getName(parseTreeNode *node) {return node->getName();}
    int getValue(parseTreeNode *node) {return node->getValue();}
    NodeType getType(parseTreeNode *node) {return node->getType();}
    vector<parseTreeNode*> getChildren(parseTreeNode *node) {return node->getChildren();}
    parseTreeNode* getParent(parseTreeNode *node) {return node->getParent();}

    // Pass Through Setters
    void setName(parseTreeNode *node, string name) {node->setName(name);}
    void setValue(parseTreeNode *node, int value) {node->setValue(value);}
    void setType(parseTreeNode *node, NodeType type) {node->setType(type);}
    void setParent(parseTreeNode *node, parseTreeNode* newParent){node->setParent(newParent);}
    void adopt(parseTreeNode *node, parseTreeNode *newChild) {node->adopt(newChild);}
};

#endif // PARSETREE_H_