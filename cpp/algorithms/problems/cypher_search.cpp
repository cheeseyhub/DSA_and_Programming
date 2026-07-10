#include <iostream>
#include <string>

#include <cmath>

int findCypherOccurrences(std::string codenames[], int length, int foundIndex, const std::string& target){
  int leftMost = foundIndex -1 ;
  int rightMost = foundIndex + 1;

  while(  leftMost >= 0 && codenames[leftMost] == target){
    leftMost--;
  }
  while(  rightMost < length && codenames[rightMost] == target){
    rightMost++;
  }
  return std::abs(rightMost-leftMost -1) ;
  

}
int binarySearchForCypher(std::string codenames[], int size , std::string target ){
  int left = 0 ;
  int right = size -1;
  int foundIndex  = -1 ;
  while(left <= right)
  {
    int mid = left + (right - left) / 2;
    if (codenames[mid] == target){
      foundIndex = mid;
      break;
    }
    else if (target > codenames[mid]){
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
 if(foundIndex == -1 )
  {
    return -1;
  }
 else {
  std::cout << "Binary Search: "  << codenames[foundIndex] << std::endl;
  return findCypherOccurrences(codenames,size,foundIndex,target);
 }

}




// FREEZE CODE BEGIN
int main(int argc, char *argv[]) {
    // Get codenames from command line arguments
    std::string codenames[argc - 1];
    for (int i = 1; i < argc; i++) {
        codenames[i - 1] = argv[i];
    }
    // Perform binary search for "Cypher"
    int result = binarySearchForCypher(codenames, argc - 1, "Cypher");
    
    // Print result
    if (result != -1) {
        std::cout << "Cypher codename appears " << result << " times in the logs." << std::endl;
    } else {
        std::cout << "Cypher codename does not appear in the logs." << std::endl;
    }

    return 0;
}
