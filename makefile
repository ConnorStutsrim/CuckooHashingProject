all: driver.o hash.o
	g++ -std=c++11 -o hash driver.o hash.o
	rm *.o

hash.o: hash.cpp
	g++ -std=c++11 -c hash.cpp

driver.o: driver.cpp
	g++ -std=c++11 -c driver.cpp

clean:
	rm hash *.o
