exe: main.o btree.o node.o key.o
	g++ main.o btree.o node.o key.o
main.o: main.cpp btree.o node.o key.o
	g++ -c main.cpp btree.o key.o
btree.o: btree.h btree.cpp node.o key.o
	g++ -c btree.cpp node.o key.o
node.o: node.h node.cpp key.o
	g++ -c node.cpp key.o
key.o: key.h key.cpp
	g++ -c key.cpp
rm:
	rm *.o