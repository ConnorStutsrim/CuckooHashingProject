all: driver.o hash.o
	g++ -o hash driver.o hash.o
	rm *.o

hash.o: hash.cpp
	g++ -c hash.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm hash *.o
