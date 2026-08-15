#include <iostream>
#include <string>

template <typename T>
T findMax(T array[], T size){
    T max = array[0];
 for(int i = 1; i < size; i++) {
 if(array[i] > max) { max = array[i];};
         
 }
 
 return max;
}
void countSort(int arr[], int n, int exp) {
    
    int output[n];
 // This creates an array that contains the count of frequency of digits;
    int i, count[10] = {0};
    
    // This increases the count each time the digit is found;
    for(i = 0 ; i < n ; i++)
        count[(arr[i] / exp) %10]++;
        
    // Turn the count into positions.
    for(i =1; i < 10; i++)
        count[i] += count[i-1];
        
        
    for(i = n -1 ; i >= 0; i--){
      // put the number into the output array  
      // subtracting 1 because the arrays are zero based in c++ and many programming languages.
     output[count[(arr[i] /exp) %10] -1] = arr[i];
     count[(arr[i] / exp) %10]--;
    }
        
    
    
    for(i = 0 ; i < n ; i++)
        arr[i] = output[i];
    
    
}

void radixSort(int arr[], int n) {
    
    int m = findMax(arr, n);
    
 for(int exp = 1; m / exp > 0; exp *=10) 
    countSort(arr,n,exp);
    
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}
int main()
{
    int array[]  = { 1, 55, 123, 123512, 22, 999999999};
    std::cout << findMax<int>(array, sizeof(array) / sizeof(array[0])) << std::endl;
    
    radixSort(array,6);
    print(array,6);
    
    
    

}
