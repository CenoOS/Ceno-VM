#include "include/StackVM.h"
#include <iostream>
#include <fstream>


int main(int argc, char *argv[]){
    if(argc <=1){
        std::cout<<"no file input."<<std::endl;
        return 0;
    }

    std::ifstream binFile;
    binFile.open(argv[1], std::ios::binary | std::ios::in);
    if(!binFile){
        std::cout<<"can not open file "<<argv[1]<<std::endl;
    }

    std::vector<vm::i32> prog;
    vm::i32 code;
    while(binFile.read((char*)&code, sizeof(code))) { 
        int readedBytes = binFile.gcount();
        prog.push_back(code);
    }
    binFile.close();

    vm::StackVM vm;

    // std::vector<vm::i32> prog;

    // prog.push_back(0b01000000000000000000000000000111); // push 7
    // prog.push_back(0b01000000000000000000000000000011); // push 3
    // prog.push_back(0b11000000000000000000000000000111); // add
    // prog.push_back(0b01000000000000000000000000000100); // push 4
    // prog.push_back(0b11000000000000000000000000000011); // mul
    // prog.push_back(0b11000000000000000000000000000000); // halt

    vm.loadProgram(prog);
    vm.run();

    return 0;
}