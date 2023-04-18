#include <iostream>

#include "../intermediate/symtab/SymtabStack.h"
#include "antlr4-runtime.h"
#include "../PascalBaseVisitor.h"

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class PassTwo : public pascalBaseVisitor
{
private:
    SymtabStack* symtabStack;

public:
    PassTwo()
    {
        symtabStack = new SymtabStack();
        symtabStack->enterLocal("integer", TYPE);
        symtabStack->enterLocal("real", TYPE);
        symtabStack->enterLocal("boolean", TYPE);
        symtabStack->enterLocal("char", TYPE);
        symtabStack->enterLocal("string", TYPE);
    }

    virtual antlrcpp::Any visitProgram(pascalParser::ProgramContext *ctx) override 
    {
        visitProgramHeader(ctx->programHeader());
        //visit(ctx->block());
        cout << "Test1" << endl;
        // Other stuff
        return 0;
    }

    virtual antlrcpp::Any visitProgramHeader(pascalParser::ProgramHeaderContext *ctx) override 
    {
        cout << "Test2" << endl;
        return nullptr;
    }

};

} // namespace frontend