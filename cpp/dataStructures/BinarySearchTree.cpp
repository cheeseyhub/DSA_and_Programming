#include <iostream>
#include <queue>

class TreeNode {
  public:
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value): value(value), left(nullptr), right(nullptr){};
};
class BinarySearchTree {

  private:
  TreeNode* root;
  TreeNode* insert(TreeNode* node, int value){
    if(node == nullptr){
      return new TreeNode(value);
    }
    if(value < node->value){
      node->left = insert(node->left,value);
    }
    else if( value > node->value){
      node->right = insert(node->right,value);
    }

    return node;
  }

  public:
  BinarySearchTree(): root(nullptr){};
  void insert(int value){
    root = insert(root,value);
  }

  TreeNode* getRoot() {
    return root;
  }
  TreeNode* minValNode(TreeNode* node) {
    while(node->left != nullptr){
      node = node->left;
    }
    return node;
  }
  void deleteNode(int value) {
    root = deleteNode(root,value);
  }



  TreeNode* deleteNode(TreeNode* node , int value){
    if(node == nullptr){
      return node;
    }
 if(value < node->value){
  node->left = deleteNode(node->left, value);
 }
 else if (value > node->value){
  node->right = deleteNode(node->right , value);
 }
 else {
  if(node->left == nullptr){
    return node->right;
  }
  else if(node->right == nullptr){
    return node->left;

  }

  node->value = minValNode(node->right)->value;
  node->right = deleteNode(node->right , node->value);
 }
  
  
  return node;
  
  
  
  }
  void inorderTraversal() {
    std::cout << "In-order Traversal";
    inorder(root);
    std::cout << std::endl;
  }
  void inorder(TreeNode* node){
    if(node != nullptr){
      inorder(node->left);
      std::cout << " " << node->value;
      inorder(node->right);
    }
  }


  void printLevelOrder(){
    printLevels(root);
  }
  void printLevels(TreeNode* node) {
    if(node == nullptr){
      std::cout << "The tree is empty" << std::endl;
      return;
    }
    std::queue<TreeNode*> queue;
    queue.push(node);
    int level = 0;

    while(!queue.empty()){
      int size = queue.size();
      std::cout << "Level " << level <<  ": ";
      level++;


      for(int i = 0 ; i < size ; i ++){
        TreeNode* currentNode = queue.front();
        queue.pop();
        std::cout << currentNode->value << " ";
        if(currentNode->left != nullptr) queue.push(currentNode->left);
        if(currentNode->right != nullptr) queue.push(currentNode->right);
        

      }
      std::cout << std::endl;
    }
  }
};

int main() {
    BinarySearchTree bst;

    bst.insert(6);
    bst.insert(4);
    bst.insert(8);
    bst.insert(2);
    bst.insert(5);

    bst.inorderTraversal();
    bst.printLevelOrder();

    return 0;
}
