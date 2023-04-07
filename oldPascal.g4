grammar pascal;

AND: 'and';
ARRAY: 'array';
ASM: 'asm';
BEGIN: 'begin';
BREAK: 'break';
CASE: 'case';
CONST: 'const';
CONSTRUCTOR: 'constructor';
CONTINUE: 'continue';
DESTRUCTOR: 'destructor';
DIV: 'div';
DO: 'do';
DOWNTO: 'downto';
ELSE: 'else';
END: 'end';
FALSE: 'FALSE';
FILE: 'file';
FOR: 'for';
FUNCTION: 'function';
GOTO: 'goto';
IF: 'if';
IMPLEMENTATION: 'implementation';
IN: 'in';
INLINE: 'inline';
INTERFACE: 'interface';
LABEL: 'label';
MOD: 'mod';
NIL: 'nil';
NOT: 'not';
OBJECT: 'object';
OF: 'of';
ON: 'on';
OPERATOR: 'operator';
OR: 'or';
PACKED: 'packed';
PROCEDURE: 'procedure';
PROGRAM: 'program';
RECORD: 'record';
REPEAT: 'repeat';
SET: 'set';
SHL: 'shl';
SHR: 'shr';
STRING: 'string';
THEN: 'then';
TO: 'to';
TRUE: 'TRUE';
TYPE: 'type';
UNIT: 'unit';
UNTIL: 'until';
USES: 'uses';
VAR: 'var';
WHILE: 'while';
WITH: 'with';
XOR: 'xor';
PLUSOP: '+';
MINUSOP: '-';
MULTOP: '*';
DIVOP: '/';
ASSIGN: ':=';
EQUAL: '=';
NE: '<>';
LTEQ: '<=';
GTEQ: '>=';
LT: '<';
GT: '>';
PLUSEQUAL: '+=';
MINUSEQUAL: '-=';
MULTEQUAL: '*=';
DIVEQUAL: '/=';
CARAT: '^';
SEMICOLON: ';';
COMMA: ',';
LPAREN: '(';
RPAREN: ')';
LBRACKET: '[';
RBRACKET: ']';
LBRACE: '{';
RBRACE: '}';
LCOMMENT: '(*';
RCOMMENT: '*)';

INTEGER: [0-9]+;
REAL: INTEGER '.' INTEGER;
IDENTIFIER: [a-zA-Z]+;
WS : [ \t\r\n]+ -> skip; 