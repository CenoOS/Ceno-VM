#ifndef __CENO_STACK_VM_H__
#define __CENO_STACK_VM_H__

#include <vector.h>


namespace vm{
    typedef int32_t i32;
    class StackVM{
            private:
                std::vector<i32> *memory;

                i32 typ; // type register
                i32 dat; // data register

                i32 pc = 0; // program counter
                // 0x00000000
                // 32k bytes code area 
                // 0x00002000
                
                i32 sp = 8192; // stack pointer, before are 32k bytes code area 
                // 0x00002000
                // 4k bytes stack area
                // 0x000023FA
                
                i32 ram = 9210; // ram 
                // 0x000023FA
                // others are all ram area, before are 32k bytes code area and 4k bytes stack area
                // ...

                i32 running = 0x0;

                i32 getType(i32 code);
                i32 getData(i32 code);
                void doPrimtive();

            public:
                StackVM();
                void loadProgram(std::vector<i32> program);

                void fetch();
                void decode();
                void execute();

                void run();
    };
};


#endif // ! __CENO_STACK_VM_H__
