all: eight_queens_test.cpp   eight_queens.cpp eight_queens.hpp eight_queens.o
	g++ -std=c++11 -Wall eight_queens.o eight_queens_test.cpp -o eight_queens_test
	./eight_queens_test

compile: eight_queens_test.cpp   eight_queens.cpp eight_queens.hpp eight_queens.o
	g++ -std=c++11 -Wall eight_queens.o eight_queens_test.cpp -o eight_queens_test
	
test: eight_queens_test
	./eight_queens_test
	
cpplint: eight_queens_test.cpp   eight_queens.cpp eight_queens.hpp
	cpplint   --exclude=catch.hpp  *.*
	
gcov: eight_queens_test.cpp   eight_queens.cpp eight_queens.hpp
	g++ -std=c++11 -Wall -Wall -fprofile-arcs -ftest-coverage -c romanos.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage romanos.o testa_romanos.cpp -o testa_romanos
	./testa_romanos
	gcov *.cpp	
	
debug: eight_queens_test.cpp   eight_queens.cpp eight_queens.hpp
	g++ -std=c++11 -Wall -Wall -g -c eight_queens.cpp
	g++ -std=c++11 -Wall  -g eight_queens.o eight_queens_test.cpp -o eight_queens_test
	gdb eight_queens_test
	
	
cppcheck: eight_queens_test.cpp   eight_queens.cpp eight_queens.hpp
	cppcheck  --enable=warning . 

valgrind: eight_queens_test
	valgrind --leak-check=yes --log-file=valgrind.rpt eight_queens_test

eight_queens.o: eight_queens.cpp eight_queens.hpp
	g++ -std=c++11 -Wall -Wall -c eight_queens.cpp
	
eight_queens_test: 	eight_queens_test.cpp   eight_queens.cpp eight_queens.hpp eight_queens.o
	g++ -std=c++11 -Wall eight_queens.o eight_queens_test.cpp -o eight_queens_test

clean:
	rm -rf *.o *.exe *.gc* 
	
	
