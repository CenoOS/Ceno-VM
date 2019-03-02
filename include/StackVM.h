#ifndef __CENO_STACK_VM_H__
#define __CENO_STACK_VM_H__

#include <vector.h>


namespace vm{
    typedef uint32_t u32;
    class StackVM{
            private:
                std::vector<u32> *bin;
            public:
                StackVM(std::vector<u32> bin);
                void fetch();
                void decode();
                void execute();
    };
};


#endif // ! __CENO_STACK_VM_H__
