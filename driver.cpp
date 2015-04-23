#include "hash.h"

#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> tableSizes;
	tableSizes.push_back(10);
	tableSizes.push_back(12);
	tableSizes.push_back(14);
	hash h(tableSizes);
	h.insert(120);
	h.insert(240);
	h.insert(360);
	cout << h.search(120);
	cout << h.search(240);
	cout << h.search(360);
	h.remove(120);
	cout << h.search(120);
	cout << endl;
	h.print();
	return 0;
}
