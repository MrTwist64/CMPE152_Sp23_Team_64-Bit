#include "scanner.h"
#include "symTabEntry.h"
#include "parseTreeNode.h"
#include "parseTree.h"

using namespace std;

class Parser
{
private:
    parseTree parseTree;
    Scanner scn;
    string curr;

public:
    Parser()
    {
        
    }

    parseTreeNode* parseProgram()
    {
        if (scn.getCurrToken() != "PROGRAM")
            return NULL;
        scn.nextToken();

        parseTreeNode* identifier = parseIdentifier();
        if(!identifier)
            return NULL;

        if (scn.getCurrToken() != "SEMICOLON")
            return NULL;
        scn.nextToken();

        parseTreeNode* block = parseBlock();
        if(!block)
            return NULL;

        if (scn.getCurrToken() != "PERIOD")
            return NULL;
        scn.nextToken();
        
        parseTreeNode* programNode = parseTree.createNode(NodeType::PROGRAM);
        programNode->adopt(identifier);
        programNode->adopt(block);
        return programNode;
    }

    parseTreeNode * parseIdentifier()
    {
        if (scn.getCurrToken() != "IDENTIFIER")
            return NULL;
        string IDName = scn.getCurrText();
        scn.nextToken();

        parseTreeNode * identifier = parseTree.createNode(NodeType::IDENTIFIER);
        parseTree.setName(identifier, IDName);
        return identifier;
    }

    parseTreeNode * parseBlock()
    {
        // parseTreeNode* labelDeclarationPart = parseLabelDeclarationPart();
        // if(!labelDeclarationPart)
        //     return NULL;
        
        // parseTreeNode* constantDefinitionPart = parseConstantDefinitionPart();
        // if(!constantDefinitionPart)
        //     return NULL;

        // parseTreeNode* typeDefinitionPart = parsetypeDefinitionPart();
        // if(!typeDefinitionPart)
        //     return NULL;
        
        // parseTreeNode* variableDeclarationPart = parseVariableDeclarationPart();
        // if(!variableDeclarationPart)
        //     return NULL;

        // parseTreeNode* procedureAndFunctionDeclarationPart = parseProcedureAndFunctionDeclarationPart();
        // if(!procedureAndFunctionDeclarationPart)
        //     return NULL;
        
        parseTreeNode* statementPart = parseStatementPart();
        if(!statementPart)
            return NULL;

        parseTreeNode* blockNode = parseTree.createNode(NodeType::BLOCK);
        // blockNode->adopt(labelDeclarationPart);
        // blockNode->adopt(constantDefinitionPart);
        // blockNode->adopt(typeDefinitionPart);
        // blockNode->adopt(variableDeclarationPart);
        // blockNode->adopt(procedureAndFunctionDeclarationPart);
        blockNode->adopt(statementPart);
        return blockNode;
    }

    parseTreeNode * parseStatementPart()
    {
        parseTreeNode* compoundStatement = parseCompoundStatement();
        if(!compoundStatement)
            return NULL;

        parseTreeNode* statementPartNode = parseTree.createNode(NodeType::STATEMENT_PART);
        statementPartNode->adopt(compoundStatement);
        return statementPartNode;
    }

    parseTreeNode * parseCompoundStatement() 
    {
        if (scn.getCurrToken() != "BEGIN")
            return NULL;
        scn.nextToken();

        parseTreeNode* statement = parseStatement();
        if(!statement)
        {
            cout << "Error!" << endl;
            while (scn.getCurrToken() != "SEMICOLON" || scn.getCurrToken() != "EOF" || scn.getCurrToken() != "END")
                scn.nextToken();
            if (scn.getCurrToken() != "EOF")
                return NULL;
        }
        
        parseTreeNode* compoundStatementNode = parseTree.createNode(NodeType::COMPOUND_STATEMENT);
        compoundStatementNode->adopt(statement);
        
        while(scn.getCurrToken() != "END")
        {
            if (scn.getCurrToken() != "SEMICOLON")
            {
                cout << "Error! Expected ';' not '" << scn.getCurrToken() << "'" << endl;
                while (scn.getCurrToken() != "SEMICOLON" || scn.getCurrToken() != "EOF" || scn.getCurrToken() != "END")
                    scn.nextToken();
                if (scn.getCurrToken() != "EOF")
                    return NULL;
                continue;
            }
            scn.nextToken();

            parseTreeNode* statement = parseStatement();
            if(!statement)
            {
                cout << "Error!" << endl;
                while (scn.getCurrToken() != "SEMICOLON" || scn.getCurrToken() != "EOF" || scn.getCurrToken() != "END")
                    scn.nextToken();
                if (scn.getCurrToken() != "EOF")
                    return NULL;
                continue;
            }
            
            compoundStatementNode->adopt(statement);
        }

        return compoundStatementNode;
    }

    parseTreeNode * parseStatement()
    {
        parseTreeNode* unlabelledStatement = parseUnlabelledStatement();
        if(unlabelledStatement)
        {
            parseTreeNode* statementNode = parseTree.createNode(NodeType::STATEMENT);
            statementNode->adopt(unlabelledStatement);
            return statementNode;
        }

        parseTreeNode* label = parseLabel();
        if(!label)
            return NULL;
        
        if (scn.getCurrToken() != "COLON")
            return NULL;
        scn.nextToken();
        
        unlabelledStatement = parseUnlabelledStatement();
        if(!unlabelledStatement)
            return NULL;

        parseTreeNode* statementNode = parseTree.createNode(NodeType::STATEMENT);
        statementNode->adopt(label);
        statementNode->adopt(unlabelledStatement);
        return statementNode;
    }

    parseTreeNode * parseUnlabelledStatement()
    {
        parseTreeNode* simpleStatement = parseSimpleStatement();
        if(simpleStatement)
        {
            parseTreeNode* unlabelledStatementNode = parseTree.createNode(NodeType::UNLABELED_STATEMENT);
            unlabelledStatementNode->adopt(simpleStatement);
            return unlabelledStatementNode;
        }
        
        parseTreeNode* structuredStatement = parseStructuredStatement();
        if(structuredStatement)
        {
            parseTreeNode* unlabelledStatementNode = parseTree.createNode(NodeType::UNLABELED_STATEMENT);
            unlabelledStatementNode->adopt(structuredStatement);
            return unlabelledStatementNode;
        }
        
        return NULL;
    }

    parseTreeNode * parseSimpleStatement()
    {
        parseTreeNode* assignmentStatement = parseAssignmentStatement();
        if(assignmentStatement)
        {
            parseTreeNode* simpleStatementNode = parseTree.createNode(NodeType::SIMPLE_STATEMENT);
            simpleStatementNode->adopt(assignmentStatement);
            return simpleStatementNode;
        }

        // parseTreeNode* procedureStatement = parseProcedureStatement();
        // if(procedureStatement)
        // {
        //     parseTreeNode* procedureStatementNode = parseTree.createNode(NodeType::PROCEDURE_STATEMENT);
        //     procedureStatementNode->adopt(procedureStatement);
        //     return procedureStatementNode;
        // }

        parseTreeNode* gotoStatement = parseGotoStatement();
        if(gotoStatement)
        {
            parseTreeNode* simpleStatementNode = parseTree.createNode(NodeType::SIMPLE_STATEMENT);
            simpleStatementNode->adopt(gotoStatement);
            return simpleStatementNode;
        }

        parseTreeNode* emptyStatement = parseEmptyStatement();
        if(emptyStatement)
        {
            parseTreeNode* simpleStatementNode = parseTree.createNode(NodeType::SIMPLE_STATEMENT);
            simpleStatementNode->adopt(emptyStatement);
            return simpleStatementNode;
        }
    }

    parseTreeNode * parseAssignmentStatement()
    {
        parseTreeNode* variable = parseVariable();
        if(variable)
        {
            if (scn.getCurrToken() != "ASSIGN")
                return NULL;
            scn.nextToken();

            parseTreeNode* expression = parseExpression();
            if(!expression)
                return NULL;
            
            parseTreeNode* assignmentStatementNode = parseTree.createNode(NodeType::ASSIGNMENT_STATEMENT);
            assignmentStatementNode->adopt(variable);
            assignmentStatementNode->adopt(expression);
            return assignmentStatementNode;
        }

        // parseTreeNode* functionIdentifier = parseFunctionIdentifier();
        // if(functionIdentifier)
        // {
        //     if (scn.getCurrToken() != "ASSIGN")
        //         return NULL;
        //     scn.nextToken();

        //     parseTreeNode* expression = parseExpression();
        //     if(!expression)
        //         return NULL;
            
        //     parseTreeNode* assignmentStatementNode = parseTree.createNode(NodeType::ASSIGNMENT_STATEMENT);
        //     assignmentStatementNode->adopt(functionIdentifier);
        //     assignmentStatementNode->adopt(expression);
        //     return assignmentStatementNode;
        // }

        return NULL;
    }

    parseTreeNode * parseVariable()
    {
        parseTreeNode* entireVariable = parseEntireVariable();
        if(entireVariable)
        {
            parseTreeNode* variableNode = parseTree.createNode(NodeType::VARIABLE);
            variableNode->adopt(entireVariable);
            return variableNode;
        }

        parseTreeNode* componentVariable = parseComponentVariable();
        if(componentVariable)
        {
            parseTreeNode* variableNode = parseTree.createNode(NodeType::VARIABLE);
            variableNode->adopt(componentVariable);
            return variableNode;
        }

        parseTreeNode* referencedVariable = parseReferencedVariable();
        if(referencedVariable)
        {
            parseTreeNode* variableNode = parseTree.createNode(NodeType::VARIABLE);
            variableNode->adopt(referencedVariable);
            return variableNode;
        }

        return NULL;
    }

    parseTreeNode * parseEntireVariable()
    {
        parseTreeNode* variableIdentifier = parseVariableIdentifier();
        if(!variableIdentifier)
            return NULL;
        
        parseTreeNode* entireVariableNode = parseTree.createNode(NodeType::ENTIRE_VARIABLE);
        entireVariableNode->adopt(variableIdentifier);
        return entireVariableNode;
    }

    parseTreeNode * parseVariableIdentifier()
    {
        parseTreeNode* identifier = parseIdentifier();
        if(!identifier)
            return NULL;
        
        parseTreeNode* variableIdentifierNode = parseTree.createNode(NodeType::VARIABLE_IDENTIFIER);
        variableIdentifierNode->adopt(identifier);
        return variableIdentifierNode;
    }

    parseTreeNode * parseComponentVariable()
    {
        parseTreeNode* indexedVariable = parseIndexedVariable();
        if(indexedVariable)
        {
            parseTreeNode* componentVariableNode = parseTree.createNode(NodeType::COMPONENT_VARIABLE);
            componentVariableNode->adopt(indexedVariable);
            return componentVariableNode;
        }

        parseTreeNode* fieldDesignator = parseFieldDesignator();
        if(fieldDesignator)
        {
            parseTreeNode* componentVariableNode = parseTree.createNode(NodeType::COMPONENT_VARIABLE);
            componentVariableNode->adopt(fieldDesignator);
            return componentVariableNode;
        }

        parseTreeNode* fileBuffer = parseFileBuffer();
        if(fileBuffer)
        {
            parseTreeNode* componentVariableNode = parseTree.createNode(NodeType::COMPONENT_VARIABLE);
            componentVariableNode->adopt(fileBuffer);
            return componentVariableNode;
        }

        return NULL;
    }

    parseTreeNode * parseIndexedVariable()
    {
        parseTreeNode* arrayVariable = parseArrayVariable();
        if(!arrayVariable)
            return NULL;

        // Parse optional expressions here. Not sure how.
        
        parseTreeNode* indexedVariableNode = parseTree.createNode(NodeType::INDEXED_VARIABLE);
        indexedVariableNode->adopt(label);
        return indexedVariableNode;
    }
    /*
    ----- TEMPLATES -----

    parseTreeNode * parseFunction()
    {

    }

        if (scn.getCurrToken() != "RECONGNIZED_TOKEN")
            return NULL;
        scn.nextToken();

        parseTreeNode* X = parseX();
        if(!X)
            return NULL;
        
        parseTreeNode* xNode = parseTree.createNode(NodeType::X);
        xNode->adopt(label);
        return xNode;
    */
 
};