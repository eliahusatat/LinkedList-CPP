#!make -f

demo: LinkedListDemo.o LinkedList.o
	clang++-5.0 -std=c++17 $^ -o demo

test: LinkedListTest.o LinkedList.o
	clang++-5.0 -std=c++17 $^ -o test

%.o: %.cpp
	clang++-5.0 -std=c++17 --compile $< -o $@

TreeTest.o: badkan.hpp LinkedList.hpp

TreeDemo.o: LinkedList.hpp

clean:
	rm -f *.o demo test
