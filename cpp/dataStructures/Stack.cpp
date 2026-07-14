#include <iostream>
// WRITE YOUR CODE HERE
class Node {
  public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = nullptr;
  }
};

class LinkedStack {

  private:
  Node* head;

  public:
   LinkedStack() {
    head = nullptr;
  }
  // push to end;
  void push(int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    
  }
  int peek() {
    return head->data;
  }

  int pop() {
    if(isEmpty() ){
      std::cout << "Stack is empty cannot pop" << std::endl;
      return -1;
    }
    int poppedValue = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return poppedValue;

  }
  bool  isEmpty() {
    return head == nullptr;
  }

};
int main() {
    // Create a LinkedStack instance
    LinkedStack myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Peek at the top element and display it
    std::cout << "Peek: " << myStack.peek() << std::endl;
    // Pop an element and display it
    std::cout << "Pop: " << myStack.pop() << std::endl;
    // Peek at the new top element and display it
    std::cout << "Peek: " << myStack.peek() << std::endl;

    return 0;
}
