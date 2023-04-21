CXXFLAGS +=-std=c++11

main: main.o time.o
	g++ -o main main.o time.o

tests: tests.o time.o
	g++ -o tests tests.o time.o
	
main.o: main.cpp time.h

tests.o: tests.cpp doctest.h time.h

time.o: time.cpp time.h 
	g++ -g -c time.cpp

clean:
	rm -f main.o tests.o time.o
