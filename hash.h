#ifndef CUCKOO_H
#define CUCKOO_H

#include <vector>

enum class hashType{
	DIV, //division method
	MULT, //multiplication method
};

class hash{
public:
	hash(hashType type, std::vector<int> tableSizes, bool mode); //mode = true supports two tables of same size with DIV method	

	void insert(int key);
	void remove(int key);
	bool search(int key);

	void print();

private:
	int hashFunction0(int key);
	int hashFunction1(int key);
	int hashFunction2(int key);
	int hashFunction3(int key);
	int hashFunction4(int key);

	void rehash();	
	float nextMultParameter();

	std::vector<std::vector<int> > table;
	std::vector<float> parameters;	
	
	bool fiftyFifty; //Special flag for testing 2 DIV tables of the same size
	hashType type; //Specifies the method used to generate hash functions
};

#endif /* CUCKOO_H */
