// FREEZE CODE BEGIN
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Helper.h"
class Range {  
// FREEZE CODE END

// WRITE YOUR CODE HERE
public:
static std::vector<int> findRange(AVLTree& tree, int min, int max){
  std::vector<int>* range = new std::vector<int>();
 
  std::vector<int>* result  = collect(tree.getRoot(), min , max, range);
  std::sort((*result).begin(),(*result).end());
  return *result;
}

private:
static std::vector<int>* collect(AVLTreeNode * node , int min , int max, std::vector<int>* range){
  if(node != nullptr){
  if(node->value >=min && node->value <= max){
    (*range).push_back(node->value);
  }
  collect(node->left, min,max,range);
  collect(node->right,min,max,range);
  }
    return range;

}


// FREEZE CODE BEGIN
};
int main(int argc, char* argv[]) {
    int type = std::atoi(argv[1]);  // Converts the first command-line argument to an integer
    int min = std::atoi(argv[2]);   // Converts the second command-line argument to an integer
    int max = std::atoi(argv[3]);   // Converts the third command-line argument to an integer
    AVLTree tree = Helper::generateTree(type);
    std::vector<int> result = Range::findRange(tree, min, max);
    std::cout << "{";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
    return 0;
}
// FREEZE CODE END

