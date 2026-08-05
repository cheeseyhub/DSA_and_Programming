#include <iostream>
class HeapImplementation {
private:
    int* heap;
    int size;
    int capacity;
public:
HeapImplementation(int capacity){
  heap = new int[capacity];
  this->capacity = capacity;
  size = 0;
}

void resize() {
  int* resizedHeap = new int[capacity * 2];
  for(int i = 0 ; i < capacity ; i++){
    resizedHeap[i] = heap[i];
  }
  delete[] heap;
  heap = resizedHeap;
  capacity *=2;
}

void insert(int value){
  if (size == capacity) resize();
  heap[size] = value;
  heapifyUp();
  size++;
}
void heapifyUp() {
  int index = size;
  while(hasParent(index) && parent(index) < heap[index])
  {
    swap(getParentIndex(index), index);
    index = getParentIndex(index);
  }
}

bool hasParent(int i) {
  return getParentIndex(i) >= 0;
}

int parent(int i ) { 
  return heap[getParentIndex(i)];
}
int getParentIndex(int i) 
{
   return (i - 1) / 2;
}


void swap(int i , int j ){
  int temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

int deleteRoot() {
  if (size == 0 ) throw std::logic_error("Heap is empty" );


  int root = heap[0];
  heap[0] = heap [ size - 1];
  size--;
  heapifyDown();
  return root;
}

void heapifyDown() {
  int index = 0;
  while(hasLeftChild(index))
  {
    int largerChildIndex = getLeftChildIndex(index);
    if(hasRightChild(index) && rightChild(index) > leftChild(index))
    {
      largerChildIndex = getRightChildIndex(index);
  }
  if(heap[index] < heap[largerChildIndex])
  {
    swap(index, largerChildIndex);
  }
  else {
    break;
  }
index = largerChildIndex;
}
}
bool hasLeftChild(int i) { return getLeftChildIndex(i) < size; }
bool hasRightChild(int i) { return getRightChildIndex(i) < size; }
int leftChild(int i) { return heap[getLeftChildIndex(i)]; }
int rightChild(int i) { return heap[getRightChildIndex(i)]; }
int getLeftChildIndex(int i) { return 2 * i + 1; }
int getRightChildIndex(int i) { return 2 * i + 2; }

void printHeap() {
        for (int i = 0; i < size; i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }

    bool search(int value) {

      for(int i = 0 ; i < size; i++)
      {
        if(heap[i] == value)
        return true;
      }
      return false;
    }
};
int main() {
 HeapImplementation heap(10);
    heap.insert(15);
    heap.insert(10);
    heap.insert(20);

    int valueToSearch = 10;
    bool isFound = heap.search(valueToSearch);
    std::cout << "Is value " << valueToSearch << " in the heap? " << (isFound ? "true" : "false") << std::endl;

    return 0;


}
