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
	void search(int key);

private:
	vector<int> table1;
	vector<int> table2;
};

#endif /* CUCKOO_H */
