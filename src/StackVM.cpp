#include "../include/StackVM.h"

using namespace vm;

StackVM::StackVM(std::vector<u32> bin){

}


/**
 * DEFINATION OF INSTRACTION:
 *  
 *  32 BIT INSTRACTION
 *  FIRST 2 BITS ARE TYPICAL
 *  OTHER 30 BITS ARE DATA
 * 
 *  EG. 0b0100 0000 0000 0000 0000 0000 0000 0000
 *       TYPICAL IS 0b01 
 *       DATA IS   Ob00 0000 0000 0000 0000 0000 0000 0000
 * 
 * DEFINATION OF TYPICAL:
 *  0b00    :   UNDEFINED
 *  0b01    :   MEANS DATA IS NONE-NEGATIVE INTEGER
 *  0b10    :   MEANS DATA IS NEGATIVE INTEGER
 *  0b11    :   MEANS DATA IS INSTRACTION
 */
i32 StackVM::getType(i32 code){
    i32 mask = 0xC0000000;  // 0b1100 0000 0000 0000 0000 0000 0000 0000
    i32 type = code & mask;
    type = type >> 30;  // right shift 30 bits
    return type;
}

i32 StackVM::getData(i32 code){
    i32 mask = 0x03FFFFFFF; // 0b0011 1111 1111 1111 1111 1111 1111 1111
    i32 data = code & mask;
    return data;
}


/**
 * DEINATION OF INSTRACTION
 *  ADD :   0X30000000
 *  SUB :   0X30000001
 *  MUL :   0X30000002
 *  DIV :   0X30000003
 */
void StackVM::doPrimtive(){

}

void StackVM::loadProgram(std::vector<i32> program){
    for(int i = 0;i<program.size();i++){
        memory[pc+i] = program[i];
    }
}

void StackVM::fetch(){
    pc++;
}

void StackVM::decode(){
    i32 code = memory[pc];
    this->typ = getType(code);
    this->dat = getData(code);
}

void StackVM::execute(){
    switch (this->typ)
    {
        case :
            /* code */
            break;
    
        default:
            break;
    }
}


void StackVM::run(){

}