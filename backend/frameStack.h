#ifndef FRAMESTACK_H_
#define FRAMESTACK_H_


#include "../intermediate/symtab/Symtab.h"
#include "frame.h"
#include <vector>

using namespace intermediate::symtab;

class FrameStack {
private:
    vector<Frame*> stack;
    string* out;

public:
    FrameStack()
    {
        
    }

    FrameStack(string* out) : out(out)
    {
        
    }

    void pop() 
    {
        stack.pop_back();
    }
    
    Frame* push(Symtab* symtab, int scope) 
    {
        Frame* frame = new Frame(symtab, scope);

        // *out += createLine("LDX", "stkidx");
        // *out += createLine("STL", "stk", "X");
        // *out += createLine("LDA", to_string(frame->getSize()));
        // *out += createLine("LDB", to_string(scope));
        // *out += createLine("JSUB","initFrame");

        stack.push_back(frame);
        return frame;
    }

    Frame* top() 
    {
        return stack.back();
    }
    
    // Will do later if needed?
    // Frame* find(int scope) {
    // 
    // }

    string createLine(string instruction)
    {
        string line = "            ";
        
        line += instruction;
        for(int i = 0; i < 8 - instruction.length(); i++)
            line += " ";
        
        line += "\n";

        return line;
    }

    string createLine(string instruction, string argument)
    {
        string line = "            ";
        
        line += instruction;
        for(int i = 0; i < 8 - instruction.length();i++)
            line += " ";
        
        line += argument;
        for(int i = 0; i < 8 - argument.length();i++)
            line += " ";
        
        line += "\n";

        return line;
    }

    string createLine(string instruction, string argument1, string argument2)
    {
        string line = "            ";
        
        line += instruction;
        for(int i = 0; i < 8 - instruction.length(); i++)
            line += " ";
        
        string arguments = argument1 + "," + argument2;
        line += arguments;
        for(int i = 0; i < 12 - arguments.length(); i++)
            line += " ";
        
        line += "\n";

        return line;
    }

    string createLineLabel(string label, string instruction)
    {
        string line = "";
        
        line += label;
        for(int i = 0; i < 12 - label.length();i++)
            line += " ";
        
        line += instruction;
        for(int i = 0; i < 8 - instruction.length();i++)
            line += " ";
        
        line += "\n";

        return line;
    }

    string createLineLabel(string label, string instruction, string argument)
    {
        string line = "";

        line += label;
        for(int i = 0; i < 12 - label.length();i++)
            line += " ";
        
        line += instruction;
        for(int i = 0; i < 8 - instruction.length();i++)
            line += " ";
        
        line += argument;
        for(int i = 0; i < 8 - argument.length();i++)
            line += " ";
        
        line += "\n";

        return line;
    }

    string createLineLabel(string label, string instruction, string argument1, string argument2)
    {
        string line = "";

        line += label;
        for(int i = 0; i < 12 - label.length();i++)
            line += " ";
        
        line += instruction;
        for(int i = 0; i < 8 - instruction.length(); i++)
            line += " ";
        
        string arguments = argument1 + "," + argument2;
        line += arguments;
        for(int i = 0; i < 12 - arguments.length(); i++)
            line += " ";
        
        line += "\n";

        return line;
    }
};

#endif //FRAMESTACK_H_