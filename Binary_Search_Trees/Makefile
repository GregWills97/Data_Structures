
output: bst.o bst_test.o
	g++ bst.cpp bst_test.cpp -o output

bst.o: bst.cpp
	g++ -c bst.h bst.cpp

bst_test.o: bst_test.cpp
	g++ -c bst_test.cpp

clean:
	rm *.o output
