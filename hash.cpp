#include "hash.h"

#include <vector>

using namespace std;

hash::hash(vector<int> tableSizes){
	for(int i = 0; i < tableSizes.size(); i++){
		vector<int> row;
		for(int j = 0; j < tableSizes[i]; j++){
			row.push_back(-1);
		}
		table.push_back(row);
	}
}

int hash::hashFunction0(int key){
	return key%table[0].size();
}
	
int hash::hashFunction1(int key){
	return key%table[1].size();
}

int hash::hashFunction2(int key){
	return key%table[2].size();
}

int hash::hashFunction3(int key){
	return key%table[3].size();
}

int hash::hashFunction4(int key){
	return key%table[4].size();
}

void hash::insert(int key){
	int numMoves = 0;
	bool placed = false;
	while(!placed && numMoves < 50){
		int i = numMoves%table.size(); // specifies table column
		int index; //specifies a table cell
		switch(i){
		case 0:
			index = hashFunction0(key);
			break; 	
		case 1:	
			index = hashFunction1(key);
			break;
		case 2:
			index = hashFunction2(key);
			break;
		case 3:
			index = hashFunction3(key);
			break;
		case 4:
			index = hashFunction4(key);
			break;
		}
		if(table[i][index] == -1){ //spot 
			table[i][index] = key;
			placed = true;
		}
		else{ //spot to put it in has data -> evict a cuckoo
			int tempKey = key;
			key = table[i][index];
			table[i][index] = tempKey;
			numMoves++;
		}
	}
	if(!placed){
		//numMoves == 50 and we need to rehash table
	}
}
	
void hash::remove(int key){
	for(int i = 0; i < table.size(); i++){
		int index;
		switch(i){
		case 0:
			index = hashFunction0(key);
			break;
		case 1:	
			index = hashFunction1(key);
			break;
		case 2:
			index = hashFunction2(key);
			break;
		case 3:
			index = hashFunction3(key);
			break;
		case 4:
			index = hashFunction4(key);
			break;
		}
		if(table[i][index] == key){
			table[i][index] = -1;
		}
	}
}
	
bool hash::search(int key){
	for(int i = 0; i < table.size(); i++){
		int index;
		switch(i){
		case 0:
			index = hashFunction0(key);
			break;
		case 1:	
			index = hashFunction1(key);
			break;
		case 2:
			index = hashFunction2(key);
			break;
		case 3:
			index = hashFunction3(key);
			break;
		case 4:
			index = hashFunction4(key);
			break;
		}
		if(table[i][index] == key){
			return true;
		}
	}	return false;
}
