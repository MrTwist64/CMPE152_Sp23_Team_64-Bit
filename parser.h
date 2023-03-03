#ifndef PARSER_H_
#define PARSER_H_

#include "scanner.h"
#include "parseTreeNode.h"
#include "parseTree.h"
#include "symTab.h"

using namespace std;

class SymTab;

class Parser
{
private:
    ParseTree* parseTree;
    Scanner scn;
    string curr;
    SymTab* symbolTable;
    

public:
    Parser()
    {
        
    }

    ParseTree* getParseTree() {return parseTree;}
    SymTab* getSymbolTree() {return symbolTable;}

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
        //parseTree->setRoot(programNode);
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
        //symbolTable->newEntry(Kind::VARIABLE, IDName)->setValue(0);
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
            cout << "Error1!" << scn.getCurrText() << " " << scn.getNextText() << endl;
            while (scn.getCurrToken() != "SEMICOLON" || scn.getCurrToken() != "EOF" || scn.getCurrToken() != "END")
                scn.nextToken();
            if (scn.getCurrToken() != "EOF")
                return NULL;
        }
        
        parseTreeNode* compoundStatementNode = parseTree->createNode(NodeType::COMPOUND_STATEMENT);
        compoundStatementNode->adopt(statement);


        if (scn.getCurrToken() == "SEMICOLON")
            scn.nextToken();
        
        while(scn.getCurrToken() != "END")
        {
            parseTreeNode* statement = parseStatement();
            if(!statement)
            {
                cout << "Error3! " << scn.getCurrText() << " " << scn.getNextText() << endl;
                while (scn.getCurrToken() != "SEMICOLON" || scn.getCurrToken() != "EOF" || scn.getCurrToken() != "END")
                    scn.nextToken();
                if (scn.getCurrToken() != "EOF")
                    return NULL;
                continue;
            }
            
            compoundStatementNode->adopt(statement);

            if (scn.getCurrToken() == "SEMICOLON")
                scn.nextToken();
        }
        scn.nextToken();

        // if (scn.getCurrToken() == "SEMICOLON")
        //     scn.nextToken();

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

        return NULL;
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

        simpleExpression = parseSimpleExpression();
        if(!simpleExpression)
            return NULL;
        expressionNode->adopt(relationalOperator);
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
            parseTreeNode* addingOperator = parseAddingOperator();
            if(addingOperator)
            {
                parseTreeNode* simpleExpression = parseSimpleExpression();
                if(simpleExpression)
                {
                    parseTreeNode* simpleExpressionNode = parseTree->createNode(NodeType::SIMPLE_EXPRESSION);
                    simpleExpressionNode->adopt(term);
                    simpleExpressionNode->adopt(addingOperator);
                    simpleExpressionNode->adopt(simpleExpression);
                    return simpleExpressionNode;
                }

                return NULL;
            }

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
            parseTreeNode* multiplyingOperator = parseMultiplyingOperator();
            if(multiplyingOperator)
            {
                parseTreeNode* term = parseTerm();
                if(term)
                {
                    termNode->adopt(factor);
                    termNode->adopt(multiplyingOperator);
                    termNode->adopt(term);
                    return termNode;
                }
            }
            termNode->adopt(factor);
            return termNode;
        }

        return NULL;
        
        // parseTreeNode* term = parseTerm();
        // if(term)
        // {
        //     parseTreeNode* termNode = parseTree->createNode(NodeType::TERM);
        //     termNode->adopt(term);
        //     parseTreeNode* multiplyingOperator = parseMultiplyingOperator();
        //     if(multiplyingOperator)
        //     {
        //         termNode->adopt(multiplyingOperator);
        //         parseTreeNode* factor = parseFactor();
        //         if(factor)
        //         {
        //             termNode->adopt(factor);
        //             return termNode;
        //         }
        //     }
        // }
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
        
        parseTreeNode* string = parseString();
        if(string){
            parseTreeNode* unsignedConstantNode = parseTree->createNode(NodeType::UNSIGNED_CONSTANT);
            unsignedConstantNode->adopt(string);
            return unsignedConstantNode;
        }

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
        return NULL;
        // parseTreeNode* emptyNode = parseTree->createNode(NodeType::EMPTY);
        // return emptyNode;
    }

    parseTreeNode * parseStructuredStatement()
    {
        parseTreeNode* compoundStatement = parseCompoundStatement();
        if(compoundStatement)
        {
            parseTreeNode* StructuredStatementNode = parseTree->createNode(NodeType::STRUCTURED_STATEMENT);
            StructuredStatementNode->adopt(compoundStatement);
            return StructuredStatementNode;
        }
        
        parseTreeNode* conditionalStatement = parseConditionalStatement();
        if(conditionalStatement)
        {
            parseTreeNode* StructuredStatementNode = parseTree->createNode(NodeType::STRUCTURED_STATEMENT);
            StructuredStatementNode->adopt(conditionalStatement);
            return StructuredStatementNode;
        }

        parseTreeNode* repetitveStatement = parseRepetitiveStatement();
        if(repetitveStatement)
        {
            parseTreeNode* StructuredStatementNode = parseTree->createNode(NodeType::STRUCTURED_STATEMENT);
            StructuredStatementNode->adopt(repetitveStatement);
            return StructuredStatementNode;
        }

        parseTreeNode* withStatement = parseWithStatement();
        if(withStatement)
        {
            parseTreeNode* StructuredStatementNode = parseTree->createNode(NodeType::STRUCTURED_STATEMENT);
            StructuredStatementNode->adopt(withStatement);
            return StructuredStatementNode;
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
            scn.nextToken();
            parseTreeNode* expression = parseExpression();
            if(expression)
            {
                parseTreeNode* ifStatementNode = parseTree->createNode(NodeType::IF_STATEMENT);
                ifStatementNode->adopt(expression);
                if(scn.getCurrToken() == "THEN")
                {
                    scn.nextToken();
                    parseTreeNode* Statement = parseStatement();
                    if(Statement)
                    {
                        ifStatementNode->adopt(Statement);
                        if(scn.getCurrToken() == "ELSE")
                        {
                            scn.nextToken();
                            parseTreeNode* Statement = parseStatement();
                            if(Statement)
                            {
                                ifStatementNode->adopt(Statement);
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
        if (scn.getCurrToken() != "CASE")
            return NULL;
        scn.nextToken();

        parseTreeNode* expression = parseExpression();
        if(!expression)
            return NULL;

        if (scn.getCurrToken() != "OF")
            return NULL;
        scn.nextToken();

        parseTreeNode* caseListElement = parseCaseListElement();
        if(!caseListElement)
            return NULL;

        parseTreeNode* caseStatementNode = parseTree->createNode(NodeType::CASE_STATEMENT);
        caseStatementNode->adopt(expression);
        caseStatementNode->adopt(caseListElement);

        while(true)
        {
            if(scn.getCurrToken() != "SEMICOLON")
                break;
            scn.nextToken();

            caseListElement = parseCaseListElement();
            if(!caseListElement)
                return NULL;
              
            caseStatementNode->adopt(caseListElement);
        }

        if(scn.getCurrToken() != "END")
            return NULL;
        scn.nextToken();
        
        return caseStatementNode;
    }

    parseTreeNode * parseCaseListElement()
    {
        parseTreeNode* caseLabelList = parseCaseLabelList();
        if(caseLabelList)
        {
            if(scn.getCurrToken() != "COLON")
            {
                scn.nextToken();
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

        parseTreeNode* string = parseString();
        if(string)
        {
            parseTreeNode* constantNode = parseTree->createNode(NodeType::CONSTANT);
            constantNode->adopt(string);
            return constantNode;
        }

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

        return NULL;
    }

    parseTreeNode * parseUnsignedReal()
    {
        parseTreeNode* unsignedInteger = parseUnsignedInteger();
        if(unsignedInteger)
        {
            if(scn.getCurrToken() == "PERIOD")
            {
                scn.nextToken();
                parseTreeNode* unsignedRealNode = parseTree->createNode(NodeType::UNSIGNED_REAL);
                unsignedRealNode->adopt(unsignedInteger);
                unsignedInteger = parseUnsignedInteger();
                if(unsignedInteger)
                {
                    unsignedRealNode->adopt(unsignedInteger);
                    return unsignedRealNode;
                }
            }
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
    
    parseTreeNode * parseType()
    {
        parseTreeNode* simpleType = parseSimpleType();
        if(simpleType){
            parseTreeNode* typeNode = parseTree->createNode(NodeType::TYPE);
            typeNode->adopt(simpleType);
            return typeNode;
        }

        parseTreeNode* structuredType = parseStructuredType();
        if(structuredType){
            parseTreeNode* typeNode = parseTree->createNode(NodeType::TYPE);
            typeNode->adopt(structuredType);
            return typeNode;
        }

        parseTreeNode* pointerType = parsePointerType();
        if(pointerType){
            parseTreeNode* typeNode = parseTree->createNode(NodeType::TYPE);
            typeNode->adopt(pointerType);
            return typeNode;
        }

        return NULL;
    }

    parseTreeNode * parseSimpleType()
    {
        parseTreeNode* scalarType = parseScalarType();
        if(scalarType){
            parseTreeNode* simpleTypeNode = parseTree->createNode(NodeType::SIMPLE_TYPE);
            simpleTypeNode->adopt(scalarType);
            return simpleTypeNode;
        }

        parseTreeNode* subrangeType = parseSubrangeType();
        if(subrangeType){
            parseTreeNode* simpleTypeNode = parseTree->createNode(NodeType::SIMPLE_TYPE);
            simpleTypeNode->adopt(subrangeType);
            return simpleTypeNode;
        }

        parseTreeNode* typeIdentifier = parseTypeIdentifier();
        if(typeIdentifier){
            parseTreeNode* simpleTypeNode = parseTree->createNode(NodeType::SIMPLE_TYPE);
            simpleTypeNode->adopt(typeIdentifier);
            return simpleTypeNode;
        }

        return NULL;
    }

    parseTreeNode * parseScalarType() 
    {
        if(scn.getCurrToken() == "LPAREN")
        {
            scn.nextToken();
            parseTreeNode* identifier = parseIdentifier();
            if(identifier)
            {   
                parseTreeNode* scalarTypeNode = parseTree->createNode(NodeType::SCALAR_TYPE);
                scalarTypeNode->adopt(identifier);
                while(true)
                {
                    if(scn.getCurrToken() != "COMMA")
                        break;
                    scn.nextToken();

                    identifier = parseIdentifier();
                    if(!identifier)
                        break;
                    scalarTypeNode->adopt(identifier);
                }

                if(scn.getCurrToken() == "RPAREN")
                {
                    scn.nextToken();
                    return scalarTypeNode;
                }
            }
        }
        return NULL;
    }

    parseTreeNode * parseSubrangeType()
    {
        parseTreeNode* constant = parseConstant();
        if(constant)
        {
            if(scn.getCurrToken() == "..")
            {
                scn.nextToken();
                parseTreeNode* subrangeTypeNode = parseTree->createNode(NodeType::SUBRANGE_TYPE);
                subrangeTypeNode->adopt(constant);
                constant = parseConstant();
                if(constant)
                {
                    subrangeTypeNode->adopt(constant);
                    return subrangeTypeNode;
                }
            }
        }

        return NULL;
    }

    parseTreeNode * parseTypeIdentifier()
    {
        parseTreeNode* identifier = parseIdentifier();
        if(!identifier)
            return NULL;
        
        parseTreeNode* typeIdentifierNode = parseTree->createNode(NodeType::TYPE_IDENTIFIER);
        typeIdentifierNode->adopt(identifier);
        return typeIdentifierNode;
    }

    parseTreeNode * parseStructuredType()
    {
        parseTreeNode * arrayType = parseArrayType();
        if(arrayType)
        {
            parseTreeNode* structuredTypeNode = parseTree->createNode(NodeType::STRUCTURED_TYPE);
            structuredTypeNode->adopt(arrayType);
            return structuredTypeNode;
        }

        parseTreeNode * recordType = parseRecordType();
        if(recordType)
        {
            parseTreeNode* structuredTypeNode = parseTree->createNode(NodeType::STRUCTURED_TYPE);
            structuredTypeNode->adopt(recordType);
            return structuredTypeNode;
        }

        parseTreeNode * setType = parseSetType();
        if(setType)
        {
            parseTreeNode* structuredTypeNode = parseTree->createNode(NodeType::STRUCTURED_TYPE);
            structuredTypeNode->adopt(setType);
            return structuredTypeNode;
        }

        parseTreeNode * fileType = parseFileType();
        if(fileType)
        {
            parseTreeNode* structuredTypeNode = parseTree->createNode(NodeType::STRUCTURED_TYPE);
            structuredTypeNode->adopt(fileType);
            return structuredTypeNode;
        }

        return NULL;
    }

    parseTreeNode * parseIndexType()
    {
        parseTreeNode* simpleType = parseSimpleType();
        if(simpleType)
        {
            parseTreeNode* indexTypeNode = parseTree->createNode(NodeType::INDEX_TYPE);
            indexTypeNode->adopt(simpleType);
            return indexTypeNode;
        }
        
        return NULL;
    }

    parseTreeNode * parseComponentType()
    {
        parseTreeNode* type = parseType();
        if(type)
        {
            parseTreeNode* componentTypeNode = parseTree->createNode(NodeType::COMPONENT_TYPE);
            componentTypeNode->adopt(type);
            return componentTypeNode;
        }

        return NULL;
    }

    parseTreeNode * parseRecordType()
    {
        if(scn.getCurrToken() == "RECORD")
        {
            scn.nextToken();
            parseTreeNode* fieldList = parseFieldList();
            if(fieldList)
            {
                if(scn.getCurrToken() == "END")
                {
                    scn.nextToken();
                    parseTreeNode* recordTypeNode = parseTree->createNode(NodeType::RECORD_TYPE);
                    recordTypeNode->adopt(fieldList);
                    return recordTypeNode;
                }
            }
        }

        return NULL;
    }

    parseTreeNode * parseFieldList()
    {
        parseTreeNode* fixedPart = parseFixedPart();
        if(fixedPart)
        {
            if(scn.getCurrToken() == "SEMICOLON")
            {
                scn.nextToken();
                parseTreeNode* variantType = parseVariantType();
                if(variantType)
                {
                    parseTreeNode* fieldList = parseTree->createNode(NodeType::FIELD_LIST);
                    fieldList->adopt(fixedPart);
                    fieldList->adopt(variantType);
                    return fieldList;
                }
            }
            else 
            {
                parseTreeNode* fieldList = parseTree->createNode(NodeType::FIELD_LIST);
                fieldList->adopt(fixedPart);
                return fieldList;
            }
        }

        parseTreeNode* variantType = parseVariantType();
        if(variantType)
        {
            parseTreeNode* fieldList = parseTree->createNode(NodeType::FIELD_LIST);
            fieldList->adopt(variantType);
            return fieldList;
        }

        return NULL;
    }

    parseTreeNode * parseVariantType()
    {
        if (scn.getCurrToken() != "CASE")
            return NULL;
        scn.nextToken();

        parseTreeNode* tagField = parseTagField();
        if(!tagField)
            return NULL;

        parseTreeNode* typeIdentifier = parseTypeIdentifier();
        if(!typeIdentifier)
            return NULL;
        
        if (scn.getCurrToken() != "OF")
            return NULL;
        scn.nextToken();

        parseTreeNode* variant = parseVariant();
        if(!variant)
            return NULL;
        
        parseTreeNode* variantTypeNode = parseTree->createNode(NodeType::VARIANT_TYPE);
        variantTypeNode->adopt(tagField);
        variantTypeNode->adopt(typeIdentifier);
        variantTypeNode->adopt(variant);
        
        while(true)
        {
            if (scn.getCurrToken() != "SEMICOLON")
                break;
            scn.nextToken();
            
            variant = parseVariant();
            if(!variant)
                return NULL;
            
            variantTypeNode->adopt(variant);
        }
        
        return variantTypeNode;
    }

    parseTreeNode * parseFixedPart()
    {
        parseTreeNode* recordSection = parseRecordSection();
        if(!recordSection)
            return NULL;
        
        parseTreeNode* fixedPartNode = parseTree->createNode(NodeType::FIXED_PART);
        fixedPartNode->adopt(recordSection);
        
        while(true)
        {
            if (scn.getCurrToken() != "SEMICOLON")
                break;
            scn.nextToken();
            
            recordSection = parseRecordSection();
            if(!recordSection)
                return NULL;
            
            fixedPartNode->adopt(recordSection);
        }

        return fixedPartNode;
    }

    parseTreeNode * parseRecordSection()
    {
        parseTreeNode* fieldIdentifier = parseFieldIdentifier();
        if(!fieldIdentifier)
        {
            parseTreeNode* empty = parseEmpty();
            if(!empty)
                return NULL;
            
            parseTreeNode* recordSectionNode = parseTree->createNode(NodeType::RECORD_SECTION);
            recordSectionNode->adopt(empty);
            return recordSectionNode;
        }
        
        parseTreeNode* recordSectionNode = parseTree->createNode(NodeType::RECORD_SECTION);
        recordSectionNode->adopt(fieldIdentifier);

        while(true)
        {
            if (scn.getCurrToken() != "SEMICOLON")
                break;
            scn.nextToken();
            
            fieldIdentifier = parseFieldIdentifier();
            if(!fieldIdentifier)
                return NULL;
            
            recordSectionNode->adopt(fieldIdentifier);
        }

        if (scn.getCurrToken() != "COLON")
            return NULL;
        scn.nextToken();

        parseTreeNode* type = parseType();
        if(!type)
            return NULL;

        recordSectionNode->adopt(type);

        return recordSectionNode;
    }

    parseTreeNode * parseString()
    {
        if(scn.getCurrToken() != "STRING")
        {
            return NULL;
        }

        parseTreeNode* stringNode = parseTree->createNode(NodeType::STRING);
        stringNode->setName(scn.getCurrText());
        return stringNode;
    }

    parseTreeNode * parseArrayType() 
    {
        if(scn.getCurrToken() == "ARRAY")
        {    
            scn.nextToken();
            if(scn.getCurrToken() == "LBRACKET")
            {
                scn.nextToken();
                parseTreeNode* indexType = parseIndexType();
                if(indexType)
                {
                    parseTreeNode* arrayTypeNode = parseTree->createNode(NodeType::ARRAY_TYPE);
                    while(true)
                    {
                        arrayTypeNode->adopt(indexType);

                        if(scn.getCurrToken() != "COMMA")
                            break;
                        scn.nextToken();
                        
                        indexType = parseIndexType();
                        if(!indexType)
                            return NULL;
                    }

                    if(scn.getCurrToken() == "RBRACKET")
                        return arrayTypeNode;
                }
            }
        }
        
        return NULL;
    }

    parseTreeNode * parseTagField()
    {
        parseTreeNode* fieldIdentifier = parseFieldIdentifier();
        if(fieldIdentifier)
        {
            if(scn.getCurrToken() == "COLON") 
            {
                scn.nextToken();
                parseTreeNode* tagFieldNode = parseTree->createNode(NodeType::TAG_FIELD);
                tagFieldNode->adopt(fieldIdentifier);
                return tagFieldNode;
            }
            
        }

        parseTreeNode* empty = parseEmpty();
        if(empty)
        {
            parseTreeNode* tagFieldNode = parseTree->createNode(NodeType::TAG_FIELD);
            tagFieldNode->adopt(empty);
            return tagFieldNode;
        }

        return NULL;
    }

    parseTreeNode * parseVariant() 
    {
        parseTreeNode* caseLabelList = parseCaseLabelList();
        if(caseLabelList)
        {
            if(scn.getCurrToken() == "COLON") 
            {
                scn.nextToken();
                if(scn.getCurrToken() == "LPAREN")
                {
                    scn.nextToken();
                    parseTreeNode* fieldList = parseFieldList();
                    if(fieldList)
                    {
                        if(scn.getCurrToken() == "RPAREN")
                        {
                            scn.nextToken();
                            parseTreeNode* variantNode = parseTree->createNode(NodeType::VARIANT);
                            variantNode->adopt(caseLabelList);
                            variantNode->adopt(fieldList);
                            return variantNode;
                        }
                    }
                }
            }
        }

        parseTreeNode* empty = parseEmpty();
        if(empty)
        {
            parseTreeNode* tagFieldNode = parseTree->createNode(NodeType::TAG_FIELD);
            tagFieldNode->adopt(empty);
            return tagFieldNode;
        }

        return NULL;
    }

    parseTreeNode * parseSetType()
    {
        if(scn.getCurrToken() == "SET")
        {
            scn.nextToken();
            if(scn.getCurrToken() == "OF")
            {
                parseTreeNode* baseType = parseBaseType();
                if(baseType)
                {
                    parseTreeNode* setTypeNode = parseTree->createNode(NodeType::SET_TYPE);
                    setTypeNode->adopt(baseType);
                    return setTypeNode;
                }
            }
        }
        return NULL;
    }

    parseTreeNode * parseBaseType()
    {
        parseTreeNode* simpleType = parseSimpleType();
        if(simpleType) 
        {
            parseTreeNode* baseTypeNode = parseTree->createNode(NodeType::BASE_TYPE);
            baseTypeNode->adopt(simpleType);
            return baseTypeNode;
        }
        
        return NULL;
    }

    parseTreeNode * parseFileType()
    {
        if(scn.getCurrToken() == "FILE")
        {
            scn.nextToken();
            if(scn.getCurrToken() == "OF")
            {
                parseTreeNode* type = parseType();
                if(type)
                {
                    parseTreeNode* fileTypeNode = parseTree->createNode(NodeType::FILE_TYPE);
                    fileTypeNode->adopt(type);
                    return fileTypeNode;
                }
            }
        }
        return NULL;
    }

    parseTreeNode * parsePointerType()
    {
        parseTreeNode* typeIdentifier = parseTypeIdentifier();
        if(!typeIdentifier)
        {
            return NULL;
        }

        parseTreeNode* pointerTypeNode = parseTree->createNode(NodeType::POINTER_TYPE);
        pointerTypeNode->adopt(typeIdentifier);
        return pointerTypeNode;
    }

    parseTreeNode * parseResultType()
    {
        parseTreeNode* typeIdentifier = parseTypeIdentifier();
        if(!typeIdentifier)
        {
            return NULL;
        }

        parseTreeNode* resultTypeNode = parseTree->createNode(NodeType::RESULT_TYPE);
        resultTypeNode->adopt(typeIdentifier);
        return resultTypeNode;
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
        
        parseTreeNode* forStatement = parseForStatement();
        if(forStatement)
        {
            parseTreeNode* repetitiveStatement = parseTree->createNode(NodeType::REPETITIVE_STATEMENT);
            repetitiveStatement->adopt(forStatement);
            return repetitiveStatement;
        }

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

    parseTreeNode * parseForStatement()
    {
        if (scn.getCurrToken() == "FOR")
        {
            scn.nextToken();
            parseTreeNode* controlVariable = parseControlVariable();
            if (controlVariable)
            {
                if (scn.getCurrToken() == "ASSIGN")
                {
                    scn.nextToken();
                    parseTreeNode* forList = parseForList();
                    if(forList)
                    {
                        if(scn.getCurrToken() == "DO")
                        {
                            scn.nextToken();
                            parseTreeNode* statement = parseStatement();
                            if(statement)
                            {
                                parseTreeNode* forStatementNode = parseTree->createNode(NodeType::FOR_STATEMENT);
                                forStatementNode->adopt(controlVariable);
                                forStatementNode->adopt(forList);
                                forStatementNode->adopt(statement);
                                return forStatementNode;
                            }
                        }
                    }
                }
            }
        }
        return NULL;
            
    }

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
            scn.nextToken();
            parseTreeNode* expression = parseExpression();
            if (expression)
            {
                if (scn.getCurrToken() == "DO")
                {
                    scn.nextToken();
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
                scn.nextToken();
                parseTreeNode* finalValue = parseFinalValue();
                if(finalValue)
                {
                    parseTreeNode* forListNode = parseTree->createNode(NodeType::FOR_LIST);
                    forListNode->adopt(initialValue);
                    forListNode->adopt(finalValue);
                    return forListNode;
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