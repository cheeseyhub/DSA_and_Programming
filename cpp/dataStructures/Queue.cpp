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
class LinkedListQueue {
  private:
  Node* front;
  Node* back;

  public:
  LinkedListQueue() {
    front = nullptr;
    back = nullptr;
  }

  void enqueue(int value) {
    Node* newNode = new Node(value);
    if(front == nullptr){
      front = newNode;
      back = newNode;
    }
    else {
      back->next = newNode;
      back = newNode;
    }
  }
  int  dequeue() {
    if(isEmpty()){
      throw std::runtime_error("The Queue is empty " );
    }
    Node* temp = front;
    int frontData = temp->data;
    front = front->next;
    delete temp;
    if(isEmpty()){
      back = nullptr;
    }

    return frontData;
  }
  int peek() {
    if(isEmpty()){
      throw std::runtime_error("Queue is empty");
    }
    return front->data;
  }
  bool isEmpty() {
    return front == nullptr;
  }

  ~LinkedListQueue(){
    while(!isEmpty()){
      dequeue();
    }
  }

};

int main() {
    LinkedListQueue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    std::cout << "Peek: " << myQueue.peek() << std::endl;
    std::cout << "Dequeue: " << myQueue.dequeue() << std::endl;
    std::cout << "Peek: " << myQueue.peek() << std::endl;

    return 0;
}
