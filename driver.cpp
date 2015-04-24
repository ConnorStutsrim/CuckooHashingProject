#include "hash.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cout << "Error: incorrect syntax" << std::endl;
		std::cout << "cuckoo <input> <output>" << std::endl;
		exit(0);
	}
	
	//Setting up file I/O
	std::ifstream input;
	input.open(argv[1]);
	std::ofstream output;
	output.open(argv[2]);
	if (!input || !output) {
		std::cout << "Error: One of the specified files does not exist" << std::endl;
		exit(0);
	}
	
	//Building the hash table
	std::vector<int> tableSizes;
	std::string tempString;
	input >> tempString;
	int tableNumber = std::stoi(tempString);
	for (int i = 0; i < tableNumber; i++) {
		input >> tempString;
		int size = std::stoi(tempString);
		tableSizes.push_back(size);
	}
	hash cuckoo(tableSizes);
	std::cout << "Hash table built" << std::endl;

	//Executing operations
	while(input >> tempString) {
		std::cout << tempString << std::endl;
		if(tempString == "insert") {
			input >> tempString;
			cuckoo.insert(std::stoi(tempString));
		}
		else if (tempString == "search") {
			input >> tempString;
			cuckoo.search(std::stoi(tempString));
		}
		else if (tempString == "remove") {
			input >> tempString;
			cuckoo.remove(std::stoi(tempString));
		}
		else if (tempString == "print") {
			cuckoo.print();
		}
		else {
			std::cout << "Error: improper operation list" << std::endl;
			std::cout << "insert <value>" << std::endl;
			std::cout << "search <value>" << std::endl;
			std::cout << "remove <value>" << std::endl;
			std::cout << "print" << std::endl;
		}
	}
return 0;
}
