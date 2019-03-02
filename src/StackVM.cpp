#include "../include/StackVM.h"

using namespace vm;

StackVM::StackVM(){
    // code + stack + ram = 41984
    this->memory.reserve(65536); // init 256k bytes memory 
}

/**
 * DEFINATION OF INSTRACTION:
 *  
 *  32 BIT INSTRACTION
 *  FIRST 2 BITS ARE TYPICAL
 *  OTHER 30 BITS ARE DATA
 * 
 *  EG.                 0b0100 0000 0000 0000 0000 0000 0000 000F
 *       TYPICAL IS   0b0000 0000 0000 0000 0000 0000 0000 0001
 *       DATA     IS   Ob0000 0000 0000 0000 0000 0000 0000 000F
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
 *  HALT :   0x30000000
 *  ADD  :   0X30000001
 *  SUB  :   0X30000002
 *  MUL  :   0X30000003
 *  DIV  :   0X30000004
 */
void StackVM::doPrimtive(){
    switch (this->dat)
    {
        case 0x30000001: // ADD
            this->memory[this->sp] = this->memory[this->sp-1] + this->memory[this->sp];
            break;
        case 0x30000002: // SUB
            this->memory[this->sp] = this->memory[this->sp-1] - this->memory[this->sp];
            break;
        case 0x30000003: // MUL
            this->memory[this->sp] = this->memory[this->sp-1] * this->memory[this->sp];
            break;
        case 0x30000004: // DIV
            this->memory[this->sp] = this->memory[this->sp-1] / this->memory[this->sp];
            break;

        case 0x30000000: // HALT
            this->running = 0x0;
            break;
        default:
            break;
    }
}

void StackVM::loadProgram(std::vector<i32> program){
    for(int i = 0;i<program.size();i++){
        this->memory[this->pc+i] = program[i];
    }
}

void StackVM::fetch(){
    this->pc++;
}

void StackVM::decode(){
    i32 code = this->memory[this->pc];
    this->typ = getType(code);
    this->dat = getData(code);
}

void StackVM::execute(){
    switch (this->typ)
    {
        case 0x0: // undefined
            break;
        case 0x1: // none-negative integer
            this->memory[this->sp] = this->dat;
            this->sp++;
            break;
        case 0x2: // negative integer
            this->memory[this->sp] = this->dat;
            this->sp++;
            break;
        case 0x3: // instraction
            this->doPrimtive();
            break;
        default:
            break;
    }
}

void StackVM::run(){
    this->running = 0x1;
    while(this->running){
        this->fetch();
        this->decode();
        this->execute();
    }
}


i32 StackVM::stackPop(){
    this->sp--;
    return this->memory[this->sp];
}

i32 StackVM::stackPush(i32 value){
    this->memory[this->sp] = value;
    this->sp++;
}

i32 StackVM::stackTop(){
    return this->memory[this->sp-1];
}

i32 StackVM::stackIsEmpty(){
    if(this->sp==this->flashSize){
        return 0x00000001;
    }
    return 0x00000000;
}

i32 StackVM::stackReset(){
    this->sp = this->flashSize;
}

