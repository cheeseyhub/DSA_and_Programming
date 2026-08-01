// FREEZE CODE BEGIN
#include <iostream>
#include <vector>
#include "Helper.h"
#include "Tree.h"
#include "Node.h"
class Largest {
// FREEZE CODE END

// WRITE YOUR CODE HERE
public:
static int largest(Tree tree, int height){
 
  return nodeSearch(tree.getRoot(), height);
}

private:
static int nodeSearch(Node* node , int height){
 // Find the left largest ;
   // find the right largest;
   if( node->height == height ){
    return node->value;
   }
   else if (node->left == nullptr || node->right == nullptr){
    return 0;
   }
   int leftLargest = nodeSearch(node->left,height);
   int rightLargest = nodeSearch(node->right,height);
   return std::max(leftLargest,rightLargest);
}


//FREEZE CODE BEGIN
};
int main(int argc, char* argv[]) {
    int treeType = std::stoi(argv[1]);
    Tree tree = Helper::generateTree(treeType);
    int height = std::stoi(argv[2]);
    std::cout << Largest::largest(tree, height) << std::endl;
    return 0;
}
// FREEZE CODE END

