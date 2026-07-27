// FREEZE CODE BEGIN
#include <iostream>
//FREEZE CODE END

// WRITE YOUR CODE HERE
class Node {
  public:
  int value,height;
  Node* left;
  Node* right;

  Node(int v) : value(v) , height(1), left(nullptr) , right(nullptr){};



};
class AVLTree {
  private:
  Node* root;

  public:
  AVLTree() : root(nullptr){}
  void insert(int value){
    root = insert(root,value);
  }

  void preOrder(){
    preOrder(root);
  }



 int balanceFactor(Node* node){
  return height(node->left) - height(node->right);
 }

  private:
  Node* rotateLeft(Node* node){
    if(!node || !node->right){
      return node;
    }
    Node* rightChild = node->right;
    node->right =rightChild->left;
    rightChild->left = node;
    updateHeight(node);
    updateHeight(rightChild);
    return rightChild;
  }
  Node* rotateRight(Node* node){
    if(!node || !node->left) return node;

    Node* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right= node;
    updateHeight(node);
    updateHeight(leftChild);
    return leftChild;
  }

  Node* insert(Node* node, int value){
    if(node == nullptr){
      return new Node(value);
    }

    if(value < node->value){
      node->left = insert(node->left,value);
    }
    else if (value > node->value){
      node->right = insert(node->right , value);
    }
    else {
    return node;
    }
    updateHeight(node);
    return rebalance(node);
  }

  void preOrder(Node* node){
    if( node != nullptr){
      std::cout << node->value << " ";
      preOrder(node->left);
      preOrder(node->right);
    }

  }

  int height(Node* node){
    return node ? node->height : -1;
  }
  void updateHeight(Node* node){
    int leftChildHeight = height(node->left);
    int rightChildHeight = height(node->right);
    node->height = std::max(leftChildHeight, rightChildHeight) + 1;
  }

  Node* rebalance(Node* node){
    int balanceFactor = this->balanceFactor(node);
    if(balanceFactor > 1){
      if(this->balanceFactor(node->left )> 0){
        node = rotateRight(node);
      }
      else{
        node = rotateLeft(node);
      }
    }
    else if (balanceFactor < -1){
      if(this->balanceFactor(node->right) < 0){
        node = rotateLeft(node);
      }
      else {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
      }

    }
    return node;
  }
};

int main() {
    AVLTree tree;

    // Insert nodes
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);

    // Insert and print tree
    std::cout << "Before insertion: ";
    tree.preOrder();
    std::cout << "\nAfter insertion: ";
    tree.insert(5);
    tree.preOrder();

    return 0;
}
