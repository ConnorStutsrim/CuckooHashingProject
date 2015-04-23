#include "hash.h"

#include <vector>

hash::hash(vector<int> tableSizes){
	for(int i = 0; i < tableSizes.size(); i++){
		vector<int> row;
		for(int j = 0; j < tableSizes[i]; j++){
			row.push_back(-1);
		}
		table.push_back(row);
	}
}

int hash::hashFunction1(int key){

}
	
int hash::hashFunction2(int key){

}

void insert(int key){

}
	
void hash::remove(int key){
	for(int i = 0; i < table.size(); i++){
		switch(i){
		case 0:
			int index = hashFunction1(key);
			if(table[i][index] == key){
				table[i][index] = -1;	
			}
			break;
		case 1:	
			int index = hashFunction2(key);
			if(table[i][index] == key){
				table[i][index] = -1;
			}	
			break;
		if(table[i][index] == key){
			table[i][index] = -1;		
		}	
	}
	int index1 = hashFunction1(key);
	int index2 = hashFunction2(key);
	if(table1[index1] == key){
		table1[index1] = -1;
	} else if(table2[index] == key){
		table2[index2] = -1;
	}
}
	
bool hash::search(int key){
	int index1 = hashFunction1(key);
	int index2 = hashFunction2(key);
	if(table1[index1] == key){
		return true;
	} 
	if(table2[index2] == key){
		return true;
	}
	return false;
}
