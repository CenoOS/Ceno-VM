CFLAGS = -std

all:Stack-VM

Stack-VM:StackVM.o

StackVM.o:/src/StackVM.cpp /include/StackVM.h
	$(CXX) $(CFLAGS) -o StackVM.o /src/StackVM.cpp /include/StackVM.h