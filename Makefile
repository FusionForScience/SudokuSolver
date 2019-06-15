ssolver: main.o sudokusolver.o
	g++ main.o sudokusolver.o -o ssolver


debug: debug_main.o debug_sudokusolver.o
	g++ -g debug_main.o debug_sudokusolver.o -o ssolver


main.o: main.cpp sudokusolver.h
	g++ main.cpp -c -o main.o


sudokusolver.o: sudokusolver.cpp sudokusolver.h
	g++ sudokusolver.cpp -c -o sudokusolver.o


debug_main.o: main.cpp sudokusolver.h
	g++ main.cpp -g -c -o debug_main.o


debug_sudokusolver.o: sudokusolver.cpp sudokusolver.h
	g++ sudokusolver.cpp -g -c -o debug_sudokusolver.o

clean: 
	rm *.o
	rm ssolver