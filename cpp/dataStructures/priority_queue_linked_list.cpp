#include <iostream>
#include <stdexcept>
// WRITE YOUR CODE HERE
class Node {
  public:
  int data;
  Node* next;
  Node(int data){
    this->data = data;
  }
};
class LinkedListPriorityQueue {
  private:
  Node* head;
  int size;

  public:
  LinkedListPriorityQueue() {
    head = nullptr;
    size = 0 ;
  }
  ~LinkedListPriorityQueue() {
    while(!isEmpty() ){
      dequeue();
    }
  }

  
  bool isEmpty() {
    return this->size == 0;
  }
  void enqueue(int value){
    Node* newNode = new Node(value);
    if(isEmpty() ||value > head->data){
      newNode->next = head;
      head = newNode;
    }
    else {
      Node* current = head;
      while(current->next != nullptr && current->next->data <= value){
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
    size++;
  }
  int dequeue() {
    if(isEmpty()){
      throw std::runtime_error("Priority queue is empty");

    }
    int value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
    return value;

  }
  int peek()  {
    if(isEmpty() ){
      throw std::underflow_error("Priority queue is empty");
    }
    return head->data;
  }
  int getSize() {
    return this->size;
  }
};

int main() {
    LinkedListPriorityQueue myPQ;
    myPQ.enqueue(3);
    myPQ.enqueue(2);
    myPQ.enqueue(4);
    std::cout << "Highest priority element: " << myPQ.peek() << std::endl;
    std::cout << "Priority queue size: " << myPQ.getSize() << std::endl;
    std::cout << "Dequeue operation result: " << myPQ.dequeue() << std::endl;
    std::cout << "Priority queue size: " << myPQ.getSize() << std::endl;
    return 0;
}
