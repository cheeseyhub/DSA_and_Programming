#include <iostream>

class HeapSortImplementation  {
public:
void heapify(int array[], int n , int i) {
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if(left < n&& array[left] > array[largest])  largest = left;


  if(right < n && array[right] > array[largest])  largest = right;

  if(largest != i)
  {
    int swap = array[i];
    array[i] = array[largest];

    array[largest] = swap;



    heapify(array,n,largest);
  }

}


void heapSort(int array[] , int n){

  for(int i = n /2 -1; i >=0 ;i--)
  {
    heapify(array,n,i);
  }
  for(int i = n -1 ; i > 0; i--)
  {
    int temp = array[0];
    array[0] = array[i];
    array[i] = temp;


    heapify(array,i,0);
  }
}



};
int main() {
    HeapSortImplementation sorter;
    int array[] = {7, 12, 9, 4, 11, 6};
    int n = sizeof(array) / sizeof(array[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    sorter.heapSort(array, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return 0;
}
