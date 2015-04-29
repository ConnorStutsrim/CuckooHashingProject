#include "hash.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

bool debug = true;

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cout << "Error: incorrect syntax" << std::endl;
		std::cout << "cuckoo <input> <output> <hash-type>" << std::endl;
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

	hashType type;
	if(argv[3][0] == 'D'){
		type = hashType::DIV;
	} else if(argv[3][0] == 'M'){
		type = hashType::MULT;
	} else {
		std::cout << "Please enter only a valid hashing type" << std::endl;
		exit(0);
	}
	
	std::chrono::time_point<std::chrono::system_clock> startTime, endTime;
	startTime = std::chrono::system_clock::now();

	//Building the hash table
	std::vector<int> tableSizes;
	std::string tempString;
	input >> tempString;
	int tableNumber = std::stoi(tempString);
	for (int i = 0; i < tableNumber; i++) {
		input >> tempString;
		tableSizes.push_back(std::stoi(tempString));
	}
	hash cuckoo(type, tableSizes);
	if (debug) std::cout << "Hash table built" << std::endl;

	//Executing operations
	while(input >> tempString) {
		std::cout << tempString << std::endl;
		if(tempString == "insert") {
			input >> tempString;
			cuckoo.insert(std::stoi(tempString));
			if (debug) std::cout << "insert " << std::stoi(tempString) << std::endl;
		}
		else if (tempString == "search") {
			input >> tempString;
			cuckoo.search(std::stoi(tempString));
			if (debug) std::cout << "search " << std::stoi(tempString) << std::endl;
		}
		else if (tempString == "remove") {
			input >> tempString;
			cuckoo.remove(std::stoi(tempString));
			if (debug) std::cout << "remove " << std::stoi(tempString) << std::endl;
		}
		else if (tempString == "print") {
			cuckoo.print();
			if (debug) std::cout << "print" << std::endl;
		}
		else {
			std::cout << "Error: improper operation list" << std::endl;
			std::cout << "insert <value>" << std::endl;
			std::cout << "search <value>" << std::endl;
			std::cout << "remove <value>" << std::endl;
			std::cout << "print" << std::endl;
		}
	}
	endTime = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed = endTime - startTime;
	std::cout << "Finished all operation in " << elapsed.count() << " seconds" << std::endl;
	return 0;
}
