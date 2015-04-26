#ifndef CUCKOO_H
#define CUCKOO_H

#include <vector>

enum class hashType{
	DIV,
	MULT,
};

class hash{
public:
	hash(hashType type, std::vector<int> tableSizes);	

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
	std::vector<std::vector<int> > table;
	
	hashType type;
};

#endif /* CUCKOO_H */
