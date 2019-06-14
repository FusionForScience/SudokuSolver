ssolver: main.o sudokusolver.o
	g++ main.o sudokusolver.o -o ssolver


main.o: main.cpp sudokusolver.h
	g++ main.cpp -c -o main.o


sudokusolver.o: sudokusolver.cpp sudokusolver.h
	g++ sudokusolver.cpp -c -o sudokusolver.o


clean: 
	rm *.o
	rm ssolver