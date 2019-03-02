#include "include/StackVM.h"

int main(){
    vm::StackVM vm;

    std::vector<vm::i32> prog;

    prog.push_back(0b01000000000000000000000000000111); // push 7
    prog.push_back(0b01000000000000000000000000000011); // push 3
    prog.push_back(0b11000000000000000000000000000111); // add
    prog.push_back(0b01000000000000000000000000000100); // push 4
    prog.push_back(0b11000000000000000000000000000011); // mul
    prog.push_back(0b11000000000000000000000000000000); // halt

    vm.loadProgram(prog);
    vm.run();

    return 0;
}