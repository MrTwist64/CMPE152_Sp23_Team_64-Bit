grammar Expr;

program: statement+ ;  // at least one statement

statement : expr NEWLINE                
          | IDENTIFER '=' expr NEWLINE        
          | NEWLINE                   
          ;

expr: expr ('*'|'/') expr   
    | expr ('+'|'-') expr   
    | INTEGER                    
    | IDENTIFER                  
    | '(' expr ')'         
    ;

IDENTIFER : [a-zA-Z]+ ; 
INTEGER   : [0-9]+ ;
NEWLINE   : '\r'? '\n' ;

WS : [ \t]+ -> skip ; 