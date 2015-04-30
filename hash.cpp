#include "hash.h"

#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstdlib>

//includes nextPrime function and a giant array of primes
//algorithm can easy be optimized
//doesn't deal with cases where not stored in prime table, would be slightly difficult to do
//table size needed to cause problems could be tables > 5,000 elements with ease
//really only necessary to fret over table sizes when using division anyway
#include "helper.cpp"

hash::hash(hashType type, std::vector<int> tableSizes){
	srand(time(NULL));
	for(int i = 0; i < tableSizes.size(); i++){
		std::vector<int> row;

		for(int j = 0; j < tableSizes[i]; j++){
			row.push_back(-1);
		}
		table.push_back(row);
		if(type == hashType::MULT){
			parameters.push_back(nextMultParameter());
		}
	}
	this->type = type;
}

int hash::hashFunction0(int key){
	if(type == hashType::DIV){
		return key%table[0].size();
	} else if(type == hashType::MULT){
		return floor(table[0].size()*(key*parameters[0] - floor(key*parameters[0])));
	}
}
	
int hash::hashFunction1(int key){
	if(type == hashType::DIV){
		return key%table[1].size();
	} else if(type == hashType::MULT){
		return floor(table[1].size()*(key*parameters[1] - floor(key*parameters[1])));
	}
}

int hash::hashFunction2(int key){
	if(type == hashType::DIV){
		return key%table[2].size();
	} else if(type == hashType::MULT){
		return floor(table[2].size()*(key*parameters[2] - floor(key*parameters[2])));
	}
}

int hash::hashFunction3(int key){
	if(type == hashType::DIV){
		return key%table[3].size();
	} else if(type == hashType::MULT){
		return floor(table[3].size()*(key*parameters[3] - floor(key*parameters[3])));
	}
}

int hash::hashFunction4(int key){
	if(type == hashType::DIV){
		return key%table[4].size();
	} else if(type == hashType::MULT){
		return floor(table[4].size()*(key*parameters[4] - floor(key*parameters[4])));
	} 
}

void hash::insert(int key){
	int numMoves = 0;
	bool placed = false;

	if(search(key)){
		return; //Does not allow duplicate input
	}

	while(!placed && numMoves < 50/*<-- Have the user set maxLoop in a function. Default should be 50*/){
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

void hash::rehash(){
	std::vector<int> tempVals; //temporary storage for keys so none are lost
	int origSize; //Size of original table used for resizing

	/*Save values*/
	for(int x = 0; x < table.size(); x++){
		for(int y = 0; y < table[x].size(); y++){
			if(table[x][y] != -1){
				tempVals.push_back(table[x][y]);
			}
		} 
	}

	/*Resize tables and generate different hash functions*/
	for(int i = 0; i < table.size(); i++){
		origSize = table[i].size(); //Save original table size
		
		if(type == hashType::DIV){ //DIV - clear/resize table and re-insert values

			table[i].clear(); //clear the table for rehashing

			//Double size
			for(int n = 0; n < origSize * 2; n++){
				table[i].push_back(-1); //Mark every cell as vacant with -1
			}

			
		} else if(type == hashType::MULT){
			/* h(k) = floor(m(kA - floor(k*A)))...
				
				...so we have a few options for changing MULT hash function:
			
				a. pick a different constant A' where A'!=A and 0 < A' < 1
				b. resize the table, thus changing the m we multiply by
				c. both of the above

				HIJACKED COMMENT BELOW
		
				1)
						for creation of tables with MULT hashing the constructor
						needs 5 floats too so if you used the function below 
						'nextMultParameter' to pick a float then both should work
						it's not actually a sophisticated algorithm though
				2)
						the float vector to fill is called parameters, its size is the 
						same size as the table
			*/ 
					
			table[i].clear(); //clear the table for rehashing

			//Double size
			for(int n = 0; n < origSize * 2; n++){
				table[i].push_back(-1); //Mark every cell as vacant with -1
			}

			//Repick each table's A
			for(int k = 0; k < table.size(); k++){
				parameters[k] = nextMultParameter();
			}

		}
	
	}

	/*Insert old values into new tables*/
	for(int j = 0; j < tempVals.size(); j++){
		insert(tempVals[j]); //reinsert all of the values originally in the table				
	}

	

}

float hash::nextMultParameter(){
	float inRange = static_cast<float>(rand()) / static_cast<float>((RAND_MAX));
	while(inRange == 0.0f || inRange == 1.0f){
		inRange = static_cast<float>(rand()) / static_cast<float>((RAND_MAX));
	}
	return inRange; 
}

void hash::print(){
	for(int i = 0; i < table.size(); i++){
		for(int j = 0; j < table[i].size(); j++){
			printf("%5d",table[i][j]);
		}
		printf("\n");
	}
}
