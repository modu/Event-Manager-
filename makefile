
bbst : RedBlackTree.o 
	g++ -std=c++11 -o bbst RedBlackTree.o

RedBlackTree.o : RedBlackTree.cpp RedBlackTree.h
	g++ -c RedBlackTree.cpp

cl :
	rm *.o bbst
