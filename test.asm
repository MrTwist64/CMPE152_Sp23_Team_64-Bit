.Testing
        LDA #33
        ADD #55
        JSUB func
ex      SUB #10

.subroutine stack
stk         RESB    10000   .stack
stkidx      WORD    0       .index to top stack frame
frmsz       WORD    0       .currant frame size
tos         WORD    0       .Top-Of-StacK (stkidx + frmsz)
stkmax      WORD    10000   .maximum stack index

.Space for function return Value
retval      RESB    500     .space for function return value
retmax      WORD    500     .maximum size of return value