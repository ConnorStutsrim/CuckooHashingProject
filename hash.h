#ifndef CUCKOO_H
#define CUCKOO_H

#include <vector>

class hash{
public:
	hash();	
	int hashFunction1(int key);
	int hashFunction2(int key);

	void insert(int key);
	void remove(int key);
	bool search(int key);

private:
	std::vector<std::vector<int> > table1;
};

#endif /* CUCKOO_H */
