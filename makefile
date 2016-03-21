
bbst : RedBlackTree.o bbst.o 
	g++ -std=c++11 -o bbst RedBlackTree.o bbst.o

RedBlackTree.o : RedBlackTree.cpp RedBlackTree.h
	g++ -c RedBlackTree.cpp

bbst.o : bbst.cpp
	g++ -c bbst.cpp

cl :
	rm *.o bbst
