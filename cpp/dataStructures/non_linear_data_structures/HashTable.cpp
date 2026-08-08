#include <iostream>
// WRITE YOUR CODE HERE
class HashTable {
private:
int* keys;
int* values;
int maxSize;
int hashFunction(int key){
  return key % maxSize;
}
public:
HashTable(int size){


  maxSize = size;
  keys = new int[maxSize];
  values = new int[maxSize];

  for(int i = 0 ; i < maxSize; ++i){
    keys[i] = -1;
    values[i] = 0;
  }
}

void put(int key , int value){
  int hashIndex = hashFunction(key);
  keys[hashIndex] = key;
  values[hashIndex] = value;
}
int get(int key){
  int hashIndex = hashFunction(key);
  return values[hashIndex];
}

void remove(int key){
  int hashIndex = hashFunction(key);
 keys[hashIndex] = -1;
 values[hashIndex] = 0;
}

};


int main() {
    HashTable myHashTable(10);
    
    myHashTable.put(1, 100);
    myHashTable.put(2, 200);
    myHashTable.put(3, 300);

    std::cout << "Get value for key 2: " << myHashTable.get(2) << std::endl;
    myHashTable.remove(2);
    std::cout << "Get value for key 2 after removal: " << myHashTable.get(2) << std::endl;

    return 0;
}
