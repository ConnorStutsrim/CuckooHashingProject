#include "cuckoo.h"

#include <cstdio>

cuckoo::cuckoo(hashType type, std::vector<int> tableSizes){
	for(int i = 0; i < tableSizes.size(); i++){
		std::vector<int> row;
		for(int j = 0; j < tableSizes[i]; j++){
			row.push_back(-1);
		}
		table.push_back(row);
	}
	this->type = type;
}

int cuckoo::hashFunction0(int key){
	if(type == hashType::DIV){
		return key%table[0].size();
	} else if(type == hashType::MULT){

	}
}
	
int cuckoo::hashFunction1(int key){
	if(type == hashType::DIV){
		return key%table[1].size();
	} else if(type == hashType::MULT){

	}
}

int cuckoo::hashFunction2(int key){
	if(type == hashType::DIV){
		return key%table[2].size();
	} else if(type == hashType::MULT){

	}
}

int cuckoo::hashFunction3(int key){
	if(type == hashType::DIV){
		return key%table[3].size();
	} else if(type == hashType::MULT){

	}
}

int cuckoo::hashFunction4(int key){
	if(type == hashType::DIV){
		return key%table[4].size();
	} else if(type == hashType::MULT){

	} 
}

void cuckoo::insert(int key){
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
		//need to resize -> could premeditatingly do this
		rehash(); //Resize and rehash the table
		insert(key); //Try inserting key again
	}
}
	
void cuckoo::remove(int key){
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
	
bool cuckoo::search(int key){
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

void cuckoo::rehash(){
	std::vector<int> tempVals; //temporary storage for keys so none are lost
	int origSize; //Size of original table used for resizing

	for(int i = 0; i < table.size(); i++){
		tempVals = table[i]; //Save values of original table
		origSize = table[i].size(); //Save original table size
		
		if(type == hashType::DIV){ //DIV - clear/resize table and re-insert values

			table[i].clear(); //clear the table for rehashing

			//Double size
			for(int n = 0; n < origSize * 2; n++){
				table[i].push_back(-1); //Mark every cell as vacant with -1
			}

			for(int j = 0; j < tempVals.size(); j++){
				insert(tempVals[j]); //reinsert all of the values originally in the table				
			}
			
		} else if(type == hashType::MULT){
			/* h(k) = floor(m(kA - floor(k*A)))...
				
				...so we have a few options for changing MULT hash function:
			
				a. pick a different constant A' where A'!=A and 0 < A' < 1
				b. resize the table, thus changing the m we multiply by
				c. both of the above
			*/ 
		}
	
	}

	

}

void cuckoo::print(){
	for(int i = 0; i < table.size(); i++){
		for(int j = 0; j < table[i].size(); j++){
			printf("%5d",table[i][j]);
		}
		printf("\n");
	}
}
