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

class LinkedList{
  public:
  Node* head;

  LinkedList(){
    head = nullptr;
  }

  void add(int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
      head = newNode;
    }
    else {
      Node* temp = head;
      while(temp->next !=nullptr){

        temp = temp->next;
      }
      temp->next = newNode;

    }
  }
  void printList() {
    Node* temp = head;
    while(temp != nullptr){
      std::cout << temp->data << "  ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
  int countNodes() {
    Node* temp = head;
    int counter = 0 ; 
    while(temp != nullptr){
      counter++;
      temp = temp->next;
    }
    return counter;
  }
  void insertAtTheBeginning(int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }
  void insertAtTheEnd(int data){
    Node* newNode = new Node(data);
    Node* last = head;
    while(last->next != nullptr){

      last = last->next;
    }
    last->next = newNode;
  }
  void deleteNode(int data){
    Node* temp = head, *prev = nullptr;

    if(temp != nullptr && temp->data == data){
      head = temp->next;
      return;
    }
    while(temp != nullptr && temp->data !=data){
      prev = temp;
      temp = temp->next;
    }
    if(temp == nullptr) return;
    prev->next = temp->next;
    delete temp;
  }
  bool search(int data){
    Node* temp = head;
    while(temp !=nullptr){
      if(temp->data == data){
        return true;
      }
      temp = temp->next;
    }
    return false;
  }
};


int main() {
  LinkedList list;
  list.add(1);
  list.add(2);
  list.add(3);
  list.insertAtTheBeginning(5);
  list.insertAtTheEnd(33);

      list.deleteNode(33);

  std::cout << "There are " << list.countNodes() << " nodes." << std::endl;
  list.printList();

  std::cout << std::boolalpha;
  std::cout << "Search for 3: " << list.search(3) << std::endl;
  std::cout << "Search for 2: " << list.search(2) << std::endl;

  return 0 ;
}
