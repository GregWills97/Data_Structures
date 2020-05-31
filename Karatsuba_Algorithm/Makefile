
output: karatsuba.o karatsuba_test.o
	g++ karatsuba.o karatsuba_test.o -o output

karatsuba.o: karatsuba.cpp
	g++ -c karatsuba.cpp

karatsuba_test.o: karatsuba_test.cpp
	g++ -c karatsuba_test.cpp

clean:
	rm *.o output
