#include<iostream>
#include<string>
#include<vector>


using namespace std;


class parseTreeNode
{
private:
    vector<parseTreeNode*> children;
    parseTreeNode* parent;
    NodeType type;
    string name;
    int value;

public:
    parseTreeNode(NodeType type) : type(type)
    {
        
    }

    // Getters
    string getName(){return this->name;}
    int getValue(){return this->value;}
    NodeType getType(){return this->type;}
    vector<parseTreeNode*> getChildren() {return children;}
    parseTreeNode* getParent() {return this->parent;}

    // Setters
    void setName(string name) {this->name = name;}
    void setValue(int value){this->value = value;}
    void setType(NodeType type){this->type = type;}
    void setParent(parseTreeNode* parent){this->parent = parent;}
    void adopt(parseTreeNode *newChild) {this->children.push_back(newChild);}





};

enum class NodeType
{
    PROGRAM, IDENTIFIER, BLOCK
};