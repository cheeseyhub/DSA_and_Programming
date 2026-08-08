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
  int numberOfProbes = 0;
  while(keys[hashIndex] != -1 && keys[hashIndex] != key)
  {
    hashIndex = (hashIndex + 1) % maxSize; numberOfProbes++;


    if(numberOfProbes > maxSize) return;
  }
  keys[hashIndex] = key;
  values[hashIndex] = value;
}
int get(int key){
  int hashIndex = hashFunction(key);

  int numberOfProbes = 0;
  while(keys[hashIndex] != -1 && keys[hashIndex] != key){
    hashIndex = (hashIndex + 1 ) % maxSize;
    numberOfProbes++;
    if(numberOfProbes > maxSize) return -1;
  }

  return keys[hashIndex] == -1 ? -1: values[hashIndex];
}

void remove(int key){
  int hashIndex = hashFunction(key);
  int numberOfProbes = 0;
  while(keys[hashIndex] != -1)
  {
    if(keys[hashIndex] == key)
    {
      keys[hashIndex] = -1;
      values[hashIndex] = 0;
      return;
    }
    hashIndex = (hashIndex + 1) % maxSize;
    numberOfProbes++;
    if(numberOfProbes > maxSize)
    return;
  }
}

};

int main() {
    HashTable myHashTable(10);

    myHashTable.put(12, 1200);
    myHashTable.put(2, 200);
    myHashTable.put(3, 300);
    myHashTable.put(13, 1300);
    myHashTable.put(7, 7);
    myHashTable.put(37, 37);
    myHashTable.put(122, 122);
    myHashTable.put(123, 123);
    myHashTable.put(124, 124);
    myHashTable.put(125, 125);
    myHashTable.put(1, 1); // edge case for put method

    std::cout << "Value for key 12: " << myHashTable.get(12) << std::endl; // handle collision
    myHashTable.remove(45); // edge case for remove method
    std::cout << "Value for key 57 after removal: " << myHashTable.get(57) << std::endl; // edge case for get method

    return 0;
}
