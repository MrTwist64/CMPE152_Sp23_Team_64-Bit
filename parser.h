#ifndef PARSER_H_
#define PARSER_H_

#include "scanner.h"
//#include "symTabEntry.h"
#include "parseTreeNode.h"
#include "parseTree.h"

using namespace std;

class Parser
{
private:
    ParseTree* parseTree;
    Scanner scn;
    string curr;

public:
    Parser()
    {
        
    }

    ParseTree* getParseTree() {return parseTree;}

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
        
        parseTreeNode* programNode = parseTree->createNode(NodeType::PROGRAM);
        programNode->adopt(identifier);
        programNode->adopt(block);
        parseTree->setRoot(programNode);
        return programNode;
    }

    parseTreeNode * parseIdentifier()
    {
        if (scn.getCurrToken() != "IDENTIFIER")
            return NULL;
        string IDName = scn.getCurrText();
        scn.nextToken();

        parseTreeNode * identifier = parseTree->createNode(NodeType::IDENTIFIER);
        parseTree->setName(identifier, IDName);
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

        parseTreeNode* blockNode = parseTree->createNode(NodeType::BLOCK);
        // blockNode->adopt(labelDeclarationPart);
        // blockNode->adopt(constantDefinitionPart);
        // blockNode->adopt(typeDefinitionPart);
        // blockNode->adopt(variableDeclarationPart);
        // blockNode->adopt(procedureAndFunctionDeclarationPart);
        blockNode->adopt(statementPart);
        return blockNode;
    }

    parseTreeNode * parseLabel()
    {
        parseTreeNode* unsignedInteger = parseUnsignedInteger();
        if(!unsignedInteger)
            return NULL;
        
        parseTreeNode* labelNode = parseTree->createNode(NodeType::LABEL);
        labelNode->adopt(unsignedInteger);
        return labelNode;
    }

    parseTreeNode * parseUnsignedInteger()
    {
        if (scn.getCurrToken() != "INTEGER")
            return NULL;
        int intNum = stoi(scn.getCurrText()); // stoi converts string to integer
        scn.nextToken();

        parseTreeNode* unsignedIntegerNode = parseTree->createNode(NodeType::UNSIGNED_INTEGER);
        unsignedIntegerNode->setValue(intNum);
        return unsignedIntegerNode;
    }

    parseTreeNode * parseStatementPart()
    {
        parseTreeNode* compoundStatement = parseCompoundStatement();
        if(!compoundStatement)
            return NULL;

        parseTreeNode* statementPartNode = parseTree->createNode(NodeType::STATEMENT_PART);
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
        
        parseTreeNode* compoundStatementNode = parseTree->createNode(NodeType::COMPOUND_STATEMENT);
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

        if (scn.getCurrToken() != "SEMICOLON")
            return NULL;
        scn.nextToken();

        return compoundStatementNode;
    }

    parseTreeNode * parseStatement()
    {
        parseTreeNode* unlabelledStatement = parseUnlabelledStatement();
        if(unlabelledStatement)
        {
            parseTreeNode* statementNode = parseTree->createNode(NodeType::STATEMENT);
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

        parseTreeNode* statementNode = parseTree->createNode(NodeType::STATEMENT);
        statementNode->adopt(label);
        statementNode->adopt(unlabelledStatement);
        return statementNode;
    }

    parseTreeNode * parseUnlabelledStatement()
    {
        parseTreeNode* simpleStatement = parseSimpleStatement();
        if(simpleStatement)
        {
            parseTreeNode* unlabelledStatementNode = parseTree->createNode(NodeType::UNLABELED_STATEMENT);
            unlabelledStatementNode->adopt(simpleStatement);
            return unlabelledStatementNode;
        }
        
        parseTreeNode* structuredStatement = parseStructuredStatement();
        if(structuredStatement)
        {
            parseTreeNode* unlabelledStatementNode = parseTree->createNode(NodeType::UNLABELED_STATEMENT);
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
            parseTreeNode* simpleStatementNode = parseTree->createNode(NodeType::SIMPLE_STATEMENT);
            simpleStatementNode->adopt(assignmentStatement);
            return simpleStatementNode;
        }

        // parseTreeNode* procedureStatement = parseProcedureStatement();
        // if(procedureStatement)
        // {
        //     parseTreeNode* procedureStatementNode = parseTree->createNode(NodeType::PROCEDURE_STATEMENT);
        //     procedureStatementNode->adopt(procedureStatement);
        //     return procedureStatementNode;
        // }

        parseTreeNode* gotoStatement = parseGotoStatement();
        if(gotoStatement)
        {
            parseTreeNode* simpleStatementNode = parseTree->createNode(NodeType::SIMPLE_STATEMENT);
            simpleStatementNode->adopt(gotoStatement);
            return simpleStatementNode;
        }

        parseTreeNode* emptyStatement = parseEmptyStatement();
        if(emptyStatement)
        {
            parseTreeNode* simpleStatementNode = parseTree->createNode(NodeType::SIMPLE_STATEMENT);
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
            
            parseTreeNode* assignmentStatementNode = parseTree->createNode(NodeType::ASSIGNMENT_STATEMENT);
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
            
        //     parseTreeNode* assignmentStatementNode = parseTree->createNode(NodeType::ASSIGNMENT_STATEMENT);
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
            parseTreeNode* variableNode = parseTree->createNode(NodeType::VARIABLE);
            variableNode->adopt(entireVariable);
            return variableNode;
        }

        // parseTreeNode* componentVariable = parseComponentVariable();
        // if(componentVariable)
        // {
        //     parseTreeNode* variableNode = parseTree->createNode(NodeType::VARIABLE);
        //     variableNode->adopt(componentVariable);
        //     return variableNode;
        // }

        // parseTreeNode* referencedVariable = parseReferencedVariable();
        // if(referencedVariable)
        // {
        //     parseTreeNode* variableNode = parseTree->createNode(NodeType::VARIABLE);
        //     variableNode->adopt(referencedVariable);
        //     return variableNode;
        // }

        return NULL;
    }

    parseTreeNode * parseEntireVariable()
    {
        parseTreeNode* variableIdentifier = parseVariableIdentifier();
        if(!variableIdentifier)
            return NULL;
        
        parseTreeNode* entireVariableNode = parseTree->createNode(NodeType::ENTIRE_VARIABLE);
        entireVariableNode->adopt(variableIdentifier);
        return entireVariableNode;
    }

    parseTreeNode * parseVariableIdentifier()
    {
        parseTreeNode* identifier = parseIdentifier();
        if(!identifier)
            return NULL;
        
        parseTreeNode* variableIdentifierNode = parseTree->createNode(NodeType::VARIABLE_IDENTIFIER);
        variableIdentifierNode->adopt(identifier);
        return variableIdentifierNode;
    }

    parseTreeNode * parseComponentVariable()
    {
        parseTreeNode* indexedVariable = parseIndexedVariable();
        if(indexedVariable)
        {
            parseTreeNode* componentVariableNode = parseTree->createNode(NodeType::COMPONENT_VARIABLE);
            componentVariableNode->adopt(indexedVariable);
            return componentVariableNode;
        }

        parseTreeNode* fieldDesignator = parseFieldDesignator();
        if(fieldDesignator)
        {
            parseTreeNode* componentVariableNode = parseTree->createNode(NodeType::COMPONENT_VARIABLE);
            componentVariableNode->adopt(fieldDesignator);
            return componentVariableNode;
        }

        parseTreeNode* fileBuffer = parseFileBuffer();
        if(fileBuffer)
        {
            parseTreeNode* componentVariableNode = parseTree->createNode(NodeType::COMPONENT_VARIABLE);
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
        
        parseTreeNode* indexedVariableNode = parseTree->createNode(NodeType::INDEXED_VARIABLE);
        indexedVariableNode->adopt(arrayVariable);

        parseTreeNode* expression = parseExpression();
        if(expression)
        {
            while(true)
            {
                indexedVariableNode->adopt(expression);

                if (scn.getCurrToken() != "COMMA")
                    break;
                scn.nextToken();

                expression = parseExpression();
                if(!expression)
                    break;
            }
        }

        return indexedVariableNode;
    }

    parseTreeNode * parseArrayVariable()
    {
        parseTreeNode* variable = parseVariable();
        if(!variable)
            return NULL;
        
        parseTreeNode* arrayVariableNode = parseTree->createNode(NodeType::ARRAY_VARIABLE);
        arrayVariableNode->adopt(variable);
        return arrayVariableNode;        
    }

    parseTreeNode * parseFieldDesignator()
    {
        parseTreeNode* recordVariable = parseRecordVariable();
        if(!recordVariable)
            return NULL;
        
        if (scn.getCurrToken() != "PERIOD")
            return NULL;
        scn.nextToken();

        parseTreeNode* fieldIdentifier = parseFieldIdentifier();
        if(!fieldIdentifier)
            return NULL;
        
        parseTreeNode* fieldDesignatorNode = parseTree->createNode(NodeType::FIELD_DESIGNATOR);
        fieldDesignatorNode->adopt(recordVariable);
        fieldDesignatorNode->adopt(fieldIdentifier);
        return fieldDesignatorNode;
    }

    parseTreeNode * parseRecordVariable()
    {
        parseTreeNode* variable = parseVariable();
        if(!variable)
            return NULL;

        parseTreeNode* recordVariableNode = parseTree->createNode(NodeType::ARRAY_VARIABLE);
        recordVariableNode->adopt(variable);
        return recordVariableNode;
    }

    parseTreeNode * parseFieldIdentifier()
    {
        parseTreeNode* identifier = parseIdentifier();
        if(!identifier)
            return NULL;
        
        parseTreeNode* fieldIdentifierNode = parseTree->createNode(NodeType::FIELD_IDENTIFIER);
        fieldIdentifierNode->adopt(identifier);
        return fieldIdentifierNode;
    }

    parseTreeNode * parseFileVariable()
    {
        parseTreeNode* variable = parseVariable();
        if(!variable)
            return NULL;

        parseTreeNode* fileVariableNode = parseTree->createNode(NodeType::FILE_VARIABLE);
        fileVariableNode->adopt(variable);
        return fileVariableNode;
    }

    parseTreeNode * parsePointerVariable()
    {
        parseTreeNode* variable = parseVariable();
        if(!variable)
            return NULL;

        parseTreeNode* pointerVariableNode = parseTree->createNode(NodeType::POINTER_VARIABLE);
        pointerVariableNode->adopt(variable);
        return pointerVariableNode;
    }

    parseTreeNode * parseFileBuffer()
    {
        parseTreeNode* fileVariable = parseFileVariable();
        if(!fileVariable)
            return NULL;
        
        parseTreeNode* fileBufferNode = parseTree->createNode(NodeType::FILE_BUFFER);
        fileBufferNode->adopt(fileVariable);
        return fileBufferNode;
    }

    parseTreeNode * parseReferencedVariable()
    {
        parseTreeNode* pointerVariable = parsePointerVariable();
        if(!pointerVariable)
            return NULL;
        
        parseTreeNode* ReferencedVariableNode = parseTree->createNode(NodeType::REFERENCED_VARIABLE);
        ReferencedVariableNode->adopt(pointerVariable);
        return ReferencedVariableNode;
    }
    
    parseTreeNode * parseExpression()
    {
        parseTreeNode* simpleExpression = parseSimpleExpression();
        if(!simpleExpression)
            return NULL;

        parseTreeNode* expressionNode = parseTree->createNode(NodeType::EXPRESSION);
        expressionNode->adopt(simpleExpression);
        
        parseTreeNode* relationalOperator = parseRelationalOperator();
        if(!relationalOperator)
            return expressionNode;
        expressionNode->adopt(relationalOperator);

        simpleExpression = parseSimpleExpression();
        expressionNode->adopt(simpleExpression);
        return expressionNode;
    }

    parseTreeNode * parseRelationalOperator()
    {
        string relationalOperator = scn.getCurrToken();

        if(relationalOperator == "EQUAL"
            || relationalOperator == "NE"
            || relationalOperator == "LT"
            || relationalOperator == "LTEQ"
            || relationalOperator == "GTEQ"
            || relationalOperator == "GT"
            || relationalOperator == "IN")
            scn.nextToken();
        else
            return NULL;

        parseTreeNode* relationalOperatorNode = parseTree->createNode(NodeType::RELATIONAL_OPERATOR);
        relationalOperatorNode->setName(relationalOperator);
        return relationalOperatorNode;
    }

    parseTreeNode * parseSimpleExpression()
    {
        parseTreeNode* term = parseTerm();
        if(term)
        {
            parseTreeNode* simpleExpressionNode = parseTree->createNode(NodeType::SIMPLE_EXPRESSION);
            simpleExpressionNode->adopt(term);
            return simpleExpressionNode;
        }
        
        parseTreeNode* sign = parseSign();
        if(sign)
        {
            parseTreeNode* simpleExpressionNode = parseTree->createNode(NodeType::SIMPLE_EXPRESSION);
            simpleExpressionNode->adopt(sign);
            parseTreeNode* term = parseTerm();
            if(term)
            {
                simpleExpressionNode->adopt(term);
                return simpleExpressionNode;
            }
        }

        parseTreeNode* simpleExpression = parseSimpleExpression();
        if(simpleExpression)
        {
            parseTreeNode* simpleExpressionNode = parseTree->createNode(NodeType::SIMPLE_EXPRESSION);
            simpleExpressionNode->adopt(simpleExpression);
            parseTreeNode* addingOperator = parseAddingOperator();
            if(addingOperator)
            {
                simpleExpressionNode->adopt(addingOperator);
                parseTreeNode* term = parseTerm();
                if(term)
                {
                    simpleExpressionNode->adopt(term);
                    return simpleExpressionNode;
                }
            }
        }

        return NULL;
    }
    
    parseTreeNode * parseAddingOperator() 
    {
        string AddingOperator = scn.getCurrToken();
        if (AddingOperator == "PLUSOP" || AddingOperator == "MINUSOP" || AddingOperator == "OR")
            scn.nextToken();
        else
            return NULL;
        parseTreeNode* addingOperatorNode = parseTree->createNode(NodeType::ADDING_OPERATOR);
        addingOperatorNode->setName(AddingOperator);
        return addingOperatorNode;
    }

    parseTreeNode * parseTerm()
    {
        parseTreeNode* factor = parseFactor();
        if(factor)
        {
            parseTreeNode* termNode = parseTree->createNode(NodeType::TERM);
            termNode->adopt(factor);
            return termNode;
        }
        
        parseTreeNode* term = parseTerm();
        if(term)
        {
            parseTreeNode* termNode = parseTree->createNode(NodeType::TERM);
            termNode->adopt(term);
            parseTreeNode* multiplyingOperator = parseMultiplyingOperator();
            if(multiplyingOperator)
            {
                termNode->adopt(multiplyingOperator);
                parseTreeNode* factor = parseFactor();
                if(factor)
                {
                    termNode->adopt(factor);
                    return termNode;
                }
            }
        }
        
        return NULL;
    }

    parseTreeNode * parseMultiplyingOperator() 
    {
        string multiplyingOperator = scn.getCurrToken();
        if(multiplyingOperator == "MULTOP" || multiplyingOperator == "DIVOP" || multiplyingOperator == "DIV" || multiplyingOperator == "MOD" || multiplyingOperator == "AND")
            scn.nextToken();
        else
            return NULL;
        parseTreeNode* multiplyingOperatorNode = parseTree->createNode(NodeType::MULTIPLYING_OPERATOR);
        multiplyingOperatorNode->setName(multiplyingOperator);
        return multiplyingOperatorNode;
    }

    parseTreeNode * parseFactor()
    {
        parseTreeNode* variable = parseVariable();
        if(variable)
        {
            parseTreeNode* termNode = parseTree->createNode(NodeType::FACTOR);
            termNode->adopt(variable);
            return termNode;
        }

        parseTreeNode* unsignedConstant = parseUnsignedConstant();
        if(unsignedConstant)
        {
            parseTreeNode* termNode = parseTree->createNode(NodeType::FACTOR);
            termNode->adopt(unsignedConstant);
            return termNode;
        }

        if(scn.getCurrToken() == "LPAREN")
        {
            scn.nextToken();
            parseTreeNode* expression = parseExpression();
            if(expression)
            {
                if(scn.getCurrToken() == "RPAREN")
                {
                    scn.nextToken();
                    parseTreeNode* termNode = parseTree->createNode(NodeType::FACTOR);
                    termNode->adopt(expression);
                    return termNode;
                }
            }
        }
        
        parseTreeNode* set = parseSet();
        if(set)
        {
            parseTreeNode* termNode = parseTree->createNode(NodeType::FACTOR);
            termNode->adopt(set);
            return termNode;
        }
        
        if(scn.getCurrToken() == "NOT")
        {
            scn.nextToken();
            parseTreeNode* factor = parseFactor();
            if(factor)
            {
                parseTreeNode* termNode = parseTree->createNode(NodeType::FACTOR);
                termNode->adopt(factor);
                return termNode;
            }
        }

        return NULL;
    }

    parseTreeNode * parseUnsignedConstant()
    {
        parseTreeNode* unsignedNumber = parseUnsignedNumber();
        if(unsignedNumber)
        {
            parseTreeNode* unsignedConstantNode = parseTree->createNode(NodeType::UNSIGNED_CONSTANT);
            unsignedConstantNode->adopt(unsignedNumber);
            return unsignedConstantNode;
        }
        
        // parseTreeNode* string = parseString();
        // if(string){
        //     parseTreeNode* unsignedConstantNode = parseTree->createNode(NodeType::UNSIGNED_CONSTANT);
        //     unsignedConstantNode->adopt(string);
        //     return unsignedConstantNode;
        // }

        parseTreeNode* constantIdentifier = parseConstantIdentifier();
        if(!constantIdentifier)
            return NULL;

        if(scn.getCurrToken() == "NIL")
        {
            parseTreeNode* unsignedConstantNode = parseTree->createNode(NodeType::UNSIGNED_CONSTANT);
            unsignedConstantNode->adopt(constantIdentifier);
            scn.nextToken();
            return unsignedConstantNode;
        }

        return NULL;
    }

    parseTreeNode * parseSet()
    {
        if(scn.getCurrToken() == "LBRACKET")
            scn.nextToken();
            parseTreeNode* elementList = parseElementList();
            if(elementList)
            {
                parseTreeNode* setNode = parseTree->createNode(NodeType::SET);
                setNode->adopt(elementList);
                if(scn.getCurrToken() == "RBRACKET")
                {
                    scn.nextToken();
                    return setNode;
                }
            }
        return NULL;
    }

    parseTreeNode * parseElementList()
    {
        parseTreeNode* elementList = parseTree->createNode(NodeType::ELEMENT_LIST);
        parseTreeNode* element = parseElement();
        if(!element)
            return NULL;
        else
        {
            while(true)
            {
                elementList->adopt(element);

                if (scn.getCurrToken() != "COMMA")
                    break;
                scn.nextToken();

                element = parseElement();
                if(!element)
                    break;
            }
            return elementList;
        }
        
        parseTreeNode* empty = parseEmpty();
        if(!empty)
            return NULL;
        elementList->adopt(empty);
        return elementList;
    }

    parseTreeNode * parseElement()
    {
        parseTreeNode* expression = parseExpression();
        if(expression)
        {
            if(scn.getCurrToken() == "..")
            {
                scn.nextToken();
                parseTreeNode* elementNode = parseTree->createNode(NodeType::ELEMENT);
                elementNode->adopt(expression);
                expression = parseExpression();
                if(expression)
                {
                    elementNode->adopt(expression);
                    return elementNode;
                }
            }
            else
            {
                parseTreeNode* elementNode = parseTree->createNode(NodeType::ELEMENT);
                elementNode->adopt(expression);
                return elementNode;
            }
        }

        return NULL;
    }

    parseTreeNode * parseGotoStatement()
    {
        if (scn.getCurrToken() != "GOTO")
            return NULL;
        scn.nextToken();

        parseTreeNode* label = parseLabel();
        if(!label)
            return NULL;
        
        parseTreeNode* gotoStatementNode = parseTree->createNode(NodeType::GOTO_STATEMENT);
        gotoStatementNode->adopt(label);
        return gotoStatementNode;
    }

    parseTreeNode * parseEmptyStatement()
    {
        parseTreeNode* empty = parseEmpty();
        if(!empty)
            return NULL;
        
        parseTreeNode* emptyStatementNode = parseTree->createNode(NodeType::EMPTY_STATEMENT);
        emptyStatementNode->adopt(empty);
        return emptyStatementNode;
    }

    parseTreeNode * parseEmpty()
    {
        parseTreeNode* emptyNode = parseTree->createNode(NodeType::EMPTY);
        return emptyNode;
    }

    parseTreeNode * parseStructuredStatement()
    {
        parseTreeNode* compoundStatement = parseCompoundStatement();
        if(compoundStatement)
        {
            parseTreeNode* parseStructuredStatement = parseTree->createNode(NodeType::STRUCTURED_STATEMENT);
            parseStructuredStatement->adopt(compoundStatement);
            return parseStructuredStatement;
        }

        parseTreeNode* conditionalStatement = parseConditionalStatement();
        if(conditionalStatement)
        {
            parseTreeNode* parseStructuredStatement = parseTree->createNode(NodeType::STRUCTURED_STATEMENT);
            parseStructuredStatement->adopt(conditionalStatement);
            return parseStructuredStatement;
        }

        // parseTreeNode* repetitveStatement = parseRepetitveStatement();
        // if(repetitveStatement)
        // {
        //     parseTreeNode* parseStructuredStatement = parseTree->createNode(NodeType::STRUCTURED_STATEMENT);
        //     parseStructuredStatement->adopt(repetitveStatement);
        //     return parseStructuredStatement;
        // }

        parseTreeNode* withStatement = parseWithStatement();
        if(withStatement)
        {
            parseTreeNode* parseStructuredStatement = parseTree->createNode(NodeType::STRUCTURED_STATEMENT);
            parseStructuredStatement->adopt(withStatement);
            return parseStructuredStatement;
        }

        return NULL;
    }

    parseTreeNode * parseConditionalStatement()
    {
        parseTreeNode* ifStatement = parseIfStatement();
        if(ifStatement)
        {
            parseTreeNode* conditionalStatementNode = parseTree->createNode(NodeType::CONDITIONAL_STATEMENT);
            conditionalStatementNode->adopt(ifStatement);
            return conditionalStatementNode;
        }
        
        parseTreeNode* caseStatement = parseCaseStatement();
        if(caseStatement)
        {
            parseTreeNode* conditionalStatementNode = parseTree->createNode(NodeType::CONDITIONAL_STATEMENT);
            conditionalStatementNode->adopt(caseStatement);
            return conditionalStatementNode;
        }

        return NULL;
    }

    parseTreeNode * parseIfStatement()
    {
        if(scn.getCurrToken() == "IF")
        {
            scn.getNextToken();
            parseTreeNode* expression = parseExpression();
            if(expression)
            {
                parseTreeNode* ifStatementNode = parseTree->createNode(NodeType::IF_STATEMENT);
                ifStatementNode->adopt(expression);
                if(scn.getCurrToken() == "THEN")
                {
                    scn.getNextToken();
                    parseTreeNode* statement = parseStatement();
                    if(statement)
                    {
                        ifStatementNode->adopt(statement);
                        if(scn.getCurrToken() == "ELSE")
                        {
                            scn.getNextToken();
                            parseTreeNode* statement = parseStatement();
                            if(statement)
                            {
                                ifStatementNode->adopt(statement);
                                return ifStatementNode;
                            }
                        }
                        return ifStatementNode;
                    }
                }
            }
        }
        
        return NULL;
    }

    parseTreeNode * parseCaseStatement()
    {
        if (scn.getCurrToken() != "BEGIN")
            return NULL;
        scn.nextToken();

        parseTreeNode* expression = parseExpression();
        if(!expression)
        {
            cout << "Error!" << endl;
            while (scn.getCurrToken() != "SEMICOLON" || scn.getCurrToken() != "EOF" || scn.getCurrToken() != "END")
                scn.nextToken();
            if (scn.getCurrToken() != "EOF")
                return NULL;
        }
        
        parseTreeNode* caseStatementNode = parseTree->createNode(NodeType::COMPOUND_STATEMENT);
        caseStatementNode->adopt(expression);

        if (scn.getCurrToken() != "OF")
            return NULL;
        scn.nextToken();
        parseTreeNode* caseListElement = parseCaseListElement();
        if(!caseListElement)
        {
            cout << "Error!" << endl;
            while (scn.getCurrToken() != "SEMICOLON" || scn.getCurrToken() != "EOF" || scn.getCurrToken() != "END")
                scn.nextToken();
            if (scn.getCurrToken() != "EOF")
                return NULL;
        }
        caseStatementNode->adopt(caseListElement);
        
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

            parseTreeNode* caseListElement = parseCaseListElement();
            if(!caseListElement)
            {
                cout << "Error!" << endl;
                while (scn.getCurrToken() != "SEMICOLON" || scn.getCurrToken() != "EOF" || scn.getCurrToken() != "END")
                    scn.nextToken();
                if (scn.getCurrToken() != "EOF")
                    return NULL;
                continue;
            }
            
            caseStatementNode->adopt(caseListElement);
        }

        return caseStatementNode;
    }

    parseTreeNode * parseCaseListElement()
    {
        parseTreeNode* caseLabelList = parseCaseLabelList();
        if(caseLabelList)
        {
            if(scn.getCurrToken() != "COLON")
            {
                parseTreeNode* statement = parseStatement();
                if(statement) 
                {
                    parseTreeNode* caseListElementNode = parseTree->createNode(NodeType::CASE_LIST_ELEMENT);
                    caseListElementNode->adopt(caseLabelList);
                    caseListElementNode->adopt(statement);
                    return caseListElementNode;
                }
            }
        }

        parseTreeNode* empty = parseEmpty();
        if(empty)
        {
            parseTreeNode* caseListElementNode = parseTree->createNode(NodeType::CASE_LIST_ELEMENT);
            caseListElementNode->adopt(empty);
            return caseListElementNode;
        }
        return NULL;
    }
    
    parseTreeNode * parseCaseLabelList()
    {
        parseTreeNode* caseLabel = parseCaseLabel();
        if(caseLabel)
        {   
            parseTreeNode* caseLabelListNode = parseTree->createNode(NodeType::CASE_LABEL_LIST);
            caseLabelListNode->adopt(caseLabel);
            while(true)
            {
                if(scn.getCurrToken() != "COMMA")
                    break;
                scn.nextToken();

                caseLabel = parseCaseLabel();
                if(!caseLabel)
                    break;
                caseLabelListNode->adopt(caseLabel);
            }
            return caseLabelListNode;
        }
        return NULL;
    }

    parseTreeNode * parseCaseLabel()
    {
        parseTreeNode* constant = parseConstant();
        if(!constant)
            return NULL;
        parseTreeNode* caseLabelNode = parseTree->createNode(NodeType::CASE_LABEL);
        caseLabelNode->adopt(constant);
        return caseLabelNode;
    }

    parseTreeNode * parseConstant()
    {
        parseTreeNode* unsignedNumber = parseUnsignedNumber();
        if(unsignedNumber)
        {
            parseTreeNode* constantNode = parseTree->createNode(NodeType::CONSTANT);
            constantNode->adopt(unsignedNumber);
            return constantNode;
        }

        parseTreeNode* sign = parseSign();
        if(sign)
        {
            parseTreeNode* unsignedNumber = parseUnsignedNumber();
            if(unsignedNumber)
            {
                parseTreeNode* constantNode = parseTree->createNode(NodeType::CONSTANT);
                constantNode->adopt(unsignedNumber);
                return constantNode;
            } 
        }

        parseTreeNode* constantIdentifier = parseConstantIdentifier();
        if(constantIdentifier)
        {
            parseTreeNode* constantNode = parseTree->createNode(NodeType::CONSTANT);
            constantNode->adopt(constantIdentifier);
            return constantNode;
        }

        sign = parseSign();
        if(sign)
        {
            parseTreeNode* constantIdentifier = parseConstantIdentifier();
            if(constantIdentifier)
            {
                parseTreeNode* constantNode = parseTree->createNode(NodeType::CONSTANT);
                constantNode->adopt(constantIdentifier);
                return constantNode;
            } 
        }

        // parseTreeNode* string = parseString();
        // if(string)
        // {
        //     parseTreeNode* constantNode = parseTree->createNode(NodeType::CONSTANT);
        //     constantNode->adopt(string);
        //     return constantNode;
        // }

        return NULL;
    }

    parseTreeNode * parseUnsignedNumber()
    {
        parseTreeNode* unsignedInteger = parseUnsignedInteger();
        if(unsignedInteger)
        {
            parseTreeNode* unsignedNumberNode = parseTree->createNode(NodeType::UNSIGNED_NUMBER);
            unsignedNumberNode->adopt(unsignedInteger);
            return unsignedNumberNode;
        }

        parseTreeNode* unsignedReal = parseUnsignedReal();
        if(unsignedReal)
        {
            parseTreeNode* unsignedNumberNode = parseTree->createNode(NodeType::UNSIGNED_NUMBER);
            unsignedNumberNode->adopt(unsignedReal);
            return unsignedNumberNode;
        }
    }

    parseTreeNode * parseUnsignedReal()
    {
        parseTreeNode* unsignedInteger = parseUnsignedInteger();
        if(unsignedInteger)
        {
            if(scn.getCurrToken() == "PERIOD")
            {
                scn.getNextToken();
                parseTreeNode* unsignedRealNode = parseTree->createNode(NodeType::UNSIGNED_REAL);
                unsignedRealNode->adopt(unsignedInteger);
                unsignedInteger = parseUnsignedInteger();
                if(unsignedInteger)
                {
                    unsignedRealNode->adopt(unsignedInteger);
                    return unsignedRealNode;
                }
            }
            // if(scn.getCurrToken() == "E")
            // {
                
            // }
        }

        return NULL;
    }

    parseTreeNode * parseSign()
    {
        string signOperator = scn.getCurrToken();
        if(signOperator == "PLUSOP" || signOperator == "MINUSOP")
            scn.nextToken();
        else
            return NULL;
        
        parseTreeNode* signOperatorNode = parseTree->createNode(NodeType::SIGN);
        signOperatorNode->setName(signOperator);
        return signOperatorNode;
    }

    parseTreeNode * parseConstantIdentifier()
    {
        parseTreeNode* identifier = parseIdentifier();
        if(!identifier)
        {
            return NULL;
        }
        parseTreeNode* constantIdentifierNode = parseTree->createNode(NodeType::CONSTANT_IDENTIFIER);
        constantIdentifierNode->adopt(identifier);
        return constantIdentifierNode;
    }
    
    

    parseTreeNode * parseRepetitiveStatement()
    {
        parseTreeNode* whileStatement = parseWhileStatement();
        if(whileStatement)
        {
            parseTreeNode* repetitiveStatement = parseTree->createNode(NodeType::REPETITIVE_STATEMENT);
            repetitiveStatement->adopt(whileStatement);
            return repetitiveStatement;
        }
        
        parseTreeNode* repeatStatement = parseRepeatStatement();
        if(repeatStatement)
        {
            parseTreeNode* repetitiveStatement = parseTree->createNode(NodeType::REPETITIVE_STATEMENT);
            repetitiveStatement->adopt(repeatStatement);
            return repetitiveStatement;
        }
        
        // parseTreeNode* forStatement = parseForStatement();
        // if(forStatement)
        // {
        //     parseTreeNode* repetitiveStatement = parseTree->createNode(NodeType::REPETITIVE_STATEMENT);
        //     repetitiveStatement->adopt(repeatStatement);
        //     return repetitiveStatement;
        // }

    return NULL;
    }

    parseTreeNode * parseRepeatStatement()
    {
        if (scn.getCurrToken() == "REPEAT")
        {
            scn.nextToken();
            parseTreeNode* statement = parseStatement();
            if (statement)
            {
                parseTreeNode* repeatStatementNode = parseTree->createNode(NodeType::REPEAT_STATEMENT);
                while(true)
                {
                    repeatStatementNode->adopt(statement);
                    if(scn.getCurrToken() != "SEMICOLON")
                        break;
                    scn.nextToken();
                    
                    statement = parseStatement();
                    if(!statement)
                        break;
                }
                
                if (scn.getCurrToken() == "UNTIL")
                {
                    scn.nextToken();
                    
                    parseTreeNode* expression = parseExpression();
                    if(expression)
                    {
                        repeatStatementNode->adopt(expression);
                        return repeatStatementNode;
                    }
                }
            }
        }
        return NULL;
    }

    // parseTreeNode * parseForStatement()
    // {
    //     if (scn.getCurrToken() == "FOR")
    //     {
    //         scn.nextToken();
    //         parseTreeNode* controlVariable = parseControlVariable();
    //         if (controlVariable)
    //         {
    //             if (scn.getCurrToken() == "ASSIGN")
    //             {
    //                 scn.nextToken();
    //                 parseTreeNode* forList = parseForList();
    //                 if(forList)
    //                     {
    //                         if(scn.getCurrText() == "DO")
    //                         {
    //                             parseTreeNode statement = parseStatement();
    //                             parseTreeNode forStatementNode = parseTree->createNode(NodeType::FOR_STATEMENT);
    //                             forStatementNode->adopt(controlVariable);
    //                             forStatementNode->adopt(forList);
    //                             forStatementNode->adopt(statement);
    //                         }
    //                     }
    //             }
    //         }
    //     }
    //     return NULL;
            
    // }

    parseTreeNode * parseControlVariable()
    {
        parseTreeNode* identifier = parseIdentifier();
        if(!identifier)
            return NULL;
        
        parseTreeNode* controlVariableNode = parseTree->createNode(NodeType::CONTROL_VARIABLE);
        controlVariableNode->adopt(identifier);
        return controlVariableNode;
    }

    parseTreeNode * parseWhileStatement()
    {
        if (scn.getCurrToken() == "WHILE")
        {
            parseTreeNode* expression = parseExpression();
            if (expression)
                {
                    if (scn.getCurrToken() == "DO")
                    {
                        parseTreeNode* statement = parseStatement();
                        if (statement)
                        {
                            parseTreeNode* whileStatement = parseTree->createNode(NodeType::WHILE_STATEMENT);
                            whileStatement->adopt(expression);
                            whileStatement->adopt(statement);
                            return whileStatement;
                        }
                    }
                }
        }
        return NULL;
    }

    parseTreeNode * parseWithStatement()
    {
        if (scn.getCurrToken() != "WITH")
            return NULL;
        scn.nextToken();

        parseTreeNode* recordVariableList = parseRecordVariableList();
        if(!recordVariableList)
            return NULL;
        
        if (scn.getCurrToken() != "DO")
            return NULL;
        scn.nextToken();

        parseTreeNode* statement = parseStatement();
        if(!statement)
            return NULL;

        parseTreeNode* withStatementNode = parseTree->createNode(NodeType::WITH_STATEMENT);
        withStatementNode->adopt(recordVariableList);
        withStatementNode->adopt(statement);
        return withStatementNode;
    }

    parseTreeNode * parseRecordVariableList()
    {
        parseTreeNode* recordVariable = parseRecordVariable();
        if(!recordVariable)
            return NULL;
        
        parseTreeNode* recordVariableListNode = parseTree->createNode(NodeType::RECORD_VARIABLE_TYPE);
        
        while(true)
        {
            recordVariableListNode->adopt(recordVariable);

            if (scn.getCurrToken() != "COMMA")
                break;
            scn.nextToken();

            recordVariable = parseRecordVariable();
            if(!recordVariable)
                return NULL;
        }
        
        return recordVariableListNode;
    }

    parseTreeNode* parseForList()
    {
        parseTreeNode* initialValue = parseInitialValue();
        if(initialValue)
        {
            if(scn.getCurrToken() == "TO")
            {
                parseTreeNode* finalValue = parseFinalValue();
                if(finalValue)
                {
                    parseTreeNode* forListNode = parseTree->createNode(NodeType::FOR_LIST);
                    forListNode->adopt(initialValue);
                    forListNode->adopt(finalValue);
                }
            }
        }

        return NULL;
    }

    parseTreeNode* parseInitialValue() {
        parseTreeNode* expression = parseExpression();
        if(!expression)
            return NULL;
        parseTreeNode* initialValueNode = parseTree->createNode(NodeType::INITIAL_VALUE);
        initialValueNode->adopt(expression);
        return initialValueNode;
    }

    parseTreeNode* parseFinalValue() {
        parseTreeNode* expression = parseExpression();
        if(!expression)
            return NULL;
        parseTreeNode* finalValueNode = parseTree->createNode(NodeType::FINAL_VALUE);
        finalValueNode->adopt(expression);
        return finalValueNode;
    }

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
 
};

#endif // PARSER_H_