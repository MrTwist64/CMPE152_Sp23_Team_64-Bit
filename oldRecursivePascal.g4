grammar pascal;

options { caseInsensitive = true; }

program : 'program' identifier ';' block '.' ;

identifier : LETTER letterOrDigit* ;

letterOrDigit : LETTER 
              | DIGIT 
              ;

block : labelDeclarationPart constantDefinitionPart typeDefinitionPart variableDeclarationPart procedureAndFunctionDeclarationPart statementPart ;

labelDeclarationPart : empty 
                     | 'label' label (',' label)* 
                     ;
                        

label : unsignedInteger ;

constantDefinitionPart : empty
                       | 'const' constantDefinition (';' constantDefinition)* 
                       ;

constantDefinition : identifier '=' constant ;

constant : unsignedNumber
         | sign unsignedNumber
         | constantIdentifier
         | sign constantIdentifier
         | string 
         ;

unsignedNumber : unsignedInteger 
               | unsignedReal 
               ;

unsignedInteger : DIGIT+ ;

unsignedReal : unsignedInteger '.' unsignedInteger 
             | unsignedInteger '.' unsignedInteger 'E' scaleFactor
             | unsignedInteger 'E' scaleFactor
             ;

scaleFactor : unsignedInteger 
            | sign unsignedInteger
            ;

sign : '+'
     | '-'
     ;

constantIdentifier : identifier ;

string : STRING_LITERAL ;

typeDefinitionPart : empty 
                   | 'type' typeDefinition (';' typeDefinition)*
                   ;

typeDefinition : identifier '=' type ;

type : simpleType 
     | structuredType
     | pointerType
     ;

similarType : scalarType
            | subrangeType
            | typeIdentifier
            ;

simpleType : scalarType
           | subrangeType
           | typeIdentifier
           ;

scalarType : '(' identifier (',' identifier)* ')' ;

subrangeType : constant '..' constant ;

typeIdentifier : identifier ;

structuredType : arrayType 
               | recordType
               | setType
               | fileType
               ;


arrayType : 'array' '[' indexType (',' indexType)* ']' 'of' componentType ;

indexType : simpleType ;

componentType : type ;

recordType : 'record' fieldList 'end' ;

fieldList : fixedPart
          | fixedPart ';' variantType 
          | variantType 
          ;

fixedPart : recordSection (';' recordSection)* ;

recordSection : fieldIdentifier (',' fieldIdentifier)* ':' type 
              | empty
              ;

variantType : 'case' tagField typeIdentifier 'of' variant (';' variant)* ;

tagField : fieldIdentifier ':'
         | empty
         ;

variant : caseLabelList ':' fieldList*
        | empty
        ;

caseLabelList : caseLabel (',' caseLabel)* ;

caseLabel : constant ;

setType : 'set of' baseType ;

baseType : simpleType;

fileType : 'file of' type;

pointerType : typeIdentifier ;

variableDeclarationPart : empty
                        | 'var' variableDeclaration (';' variableDeclaration)*
                        ;

variableDeclaration : identifier (',' identifier)* ':' type ;

procedureAndFunctionDeclarationPart : (procedureOrFunctionDeclaration ';')* ;

procedureOrFunctionDeclaration: procedureDeclaration 
                              | functionDeclaration 
                              ;

procedureDeclaration: procedureHeading block ;

procedureHeading : 'procedure' identifier ';'
                 | 'procedure' identifier '(' formalParameterSection (';' formalParameterSection)* ')'
                 ;

formalParameterSection : parameterGroup
                       | 'var' parameterGroup
                       | 'function' parameterGroup
                       | 'procedure' identifier (',' identifier)*
                       ;

parameterGroup : identifier (',' identifier)* ':' typeIdentifier;

functionDeclaration : functionHeading block ;

functionHeading : 'function' identifier ':' resultType ';'
                | 'function' identifier '(' formalParameterSection (';' formalParameterSection)* ')' ':' resultType ';'
                ;

resultType : typeIdentifier ;

statementPart : compoundStatement ;


statement : unlabelledStatement
          | label ':' unlabelledStatement
          ;

unlabelledStatement : simpleStatement
                    | structuredStatement
                    ;

simpleStatement : assignmentStatement
                | procedureStatement
                | goToStatement
                | emptyStatement
                ;

assignmentStatement : variable ':=' expression 
                    | functionIdentifier ':=' expression
                    ;

variable : entireVariable
         | componentVariable
         | referencedVariable
         ;

entireVariable : variableIdentifier ;

variableIdentifier : identifier ;

componentVariable : indexedVariable
                  | fieldDesignator
                  | fileBuffer
                  ;

indexedVariable : arrayVariable '[' expression (',' expression)* ']' ;

arrayVariable : variable ;

fieldDesignator : recordVariable '.' fieldIdentifier ;

recordVariable : variable ;

fieldIdentifier : identifier ;

fileBuffer : fileVariable ;

fileVariable : variable ;

referencedVariable : pointerVariable ;

pointerVariable : variable ;

expression : simpleExpression
           | simpleExpression relationalOperator simpleExpression
           ;

relationalOperator : '='
                   | '<>'
                   | '<'
                   | '<='
                   | '>='
                   | '>'
                   | 'in'
                   ;


simpleExpression : term
                 | sign
                 | term
                 | simpleExpression addingOperator term
                 ;

addingOperator : '+'
               | '-'
               | 'or'
               ;

term : factor
     | term multiplyingOperator factor
     ;

multiplyingOperator : '*'
                    | '/'
                    | 'div'
                    | 'mod'
                    | 'and'
                    ;

factor : variable 
       | unsignedConstant
       | '(' expression ')' 
       | functionDesignator
       | set
       | 'not' factor
       ;

unsignedConstant : unsignedNumber 
                 | string
                 | constantIdentifier 'nil'
                 ;

functionDesignator : functionIdentifier 
                   | functionIdentifier '(' actualParameter  (',' actualParameter)* ')'
                   ;

functionIdentifier : identifier ;

set : '[' elementList ']' ;

elementList : element (',' element)
            | empty
            ;

element : expression 
        | expression '..' expression
        ;

procedureStatement : procedureIdentifier
                   | procedureIdentifier '(' actualParameter (',' actualParameter)* ')'
                   ;

procedureIdentifier : identifier ;

actualParameter : expression
                | variable
                | procedureIdentifier
                | functionIdentifier
                ;

goToStatement : 'goto' label ;

emptyStatement : empty ;

empty : ;

structuredStatement : compoundStatement 
                    | conditionalStatement
                    | repetitiveStatement
                    | withStatement 
                    ;

compoundStatement : 'begin' statement (';' statement)* 'end' ;

conditionalStatement : ifStatement 
                     | caseStatement
                     ;           

ifStatement : 'if' expression 'then' statement 
            | 'if' expression 'then' statement
            | 'else' statement
            ;

caseStatement : 'case' expression 'of' caseListElement (';' caseListElement)* 'end' ;

caseListElement : caseLabelList ':' statement 
                | empty
                ;

repetitiveStatement : whileStatement
                    | repeatStatement
                    | forStatement 
                    ;

whileStatement : 'while' expression 'do' statement;

repeatStatement : 'repeat' statement (';' statement)* 'until' expression ;

forStatement : 'for' controlVariable ':=' forList 'do' statement ; 

controlVariable : identifier ;

forList : initialValue 'to' finalValue 'downto' finalValue ;

initialValue : expression ; 

finalValue: expression ;

withStatement : 'with' recordVariableList 'do' statement ; 

recordVariableList : recordVariable(',' recordVariable)* ;

LETTER : [a-zA-Z] ;

DIGIT : [0-9] ;

STRING_LITERAL : '\'' ('\'\'' | ~('\''))* '\'' ;