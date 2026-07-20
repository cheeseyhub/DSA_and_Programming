#include <iostream>
#include <queue>

// WRITE YOUR CODE HERE
class Node {
  public:
  int data;
  Node* left;
  Node* right;


  Node(int item){
    data  = item;
    left = right = nullptr;
  }
};

class Tree {
  public:
  Node* root;

  Tree() {
    root = nullptr;
  }

  void insert(int value) {
    root = insert(root,value);
  }
  void dfs(){
	  dfs(root);
  }

  void bfs() {

	  if(root == nullptr) return;

	  std::queue<Node*> queue;
	  queue.push(root);

		  while(!queue.empty() ) {
			Node* node = queue.front();
			queue.pop();

			  std::cout << node->data ;
			if(node->left != nullptr) queue.push(node->left);
			if(node->right !=nullptr) queue.push(node->right);
		  }
  }
  private:
  Node* insert(Node* node , int value){

    if(node == nullptr) 
    {
      return new Node(value);
    }
    
    if(value < node->data){
      node->left = insert(node->left, value);

    }
    else if (value > node->data){
      node->right = insert(node->right ,value);
    }
  
    return node;
  }

  void dfs(Node* node){
	  if(node == nullptr) return;

	  std::cout << node->data ;
	  dfs(node->left);
	  dfs(node->right);
  }




  


  

};
int main() {
    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);

    // Perform depth-first search
    std::cout << "DFS traversal:" << std::endl;
    tree.dfs();
    std::cout << std::endl;

    // Perform breadth-first search
    // std::cout << "BFS traversal:" << std::endl;
    // tree.bfs();
    // std::cout << std::endl;

    return 0;
}



