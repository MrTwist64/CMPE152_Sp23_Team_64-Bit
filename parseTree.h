#include "parseTreeNode.h"

using namespace std;

class parseTree
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