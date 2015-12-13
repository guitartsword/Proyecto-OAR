exe: main.o btree.o nodo.o key.o
	g++ main.o btree.o nodo.o key.o
main.o: main.cpp btree.o nodo.o key.o
	g++ -c main.cpp btree.o key.o
btree.o: btree.h btree.cpp nodo.o key.o
	g++ -c btree.cpp nodo.o key.o
nodo.o: nodo.h nodo.cpp key.o
	g++ -c nodo.cpp key.o
key.o: key.h key.cpp
	g++ -c key.cpp
rm:
	rm *.o
