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

class CircularList {
  public:
  Node* head;
  Node* tail;

  CircularList(){
	  head = nullptr;
	  tail = nullptr;

  }
  void printList(){
	  Node*current  = head;
	  while(current != nullptr){
		  std::cout << current->data << "";	
		  current = current->next;
		  if(current  == head){
			  std::cout << std::endl;
			  break;
		  }
	  
	  
	  }

  }
  void insertAtBeginning(int data){
	  Node* newNode = new Node(data);
	  if(head ==nullptr){
		  head = newNode;
		  tail = newNode;
		  tail->next = head;
	  }
	  else {
		  newNode->next = head;
		  head = newNode;
		  tail->next = head;
	  }
  }
  void deleteAtBeginning(){
    if(head == nullptr) return;
    if(head == tail){
      Node*temp = head;
      head = nullptr;
      tail = nullptr;

      delete temp;
      return;
    }
    head = head->next;
    tail->next = head;
  }
  void insertAtEnd(int data){
    if(head == nullptr){
      insertAtBeginning(data);
      return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;

  }
  void insertAtPos(int data, int pos){
    if(pos < 1){
      std::cout << "Invalid position " << std::endl;
      return;
    }
    if(pos == 1){
      insertAtBeginning(data);
    }else {
      Node* current = head;
      Node* newNode = new Node(data);
      int currentPos = 1;
      while( currentPos < pos -1 ){
      

        current = current->next;
        currentPos++;
        if(current == head){
          std::cout << "Invalid position ";
          return;
          break;
        }
      }
        newNode->next = current->next;
        current->next = newNode;      
      if(newNode->next == head){
        tail = newNode;
      }
    }
  }
  void deleteAtEnd() {
    if (head == nullptr) return;
    if(head == tail){
      deleteAtBeginning();
    }
    else {
      Node* current = head;
      while(current->next != tail){
        current = current->next;
      }
      current->next = head;
      tail =current;
    }
  }
  void deleteAtPos(int pos){
    if(head == nullptr){

      std::cout << "Cannot remove node from an empty list";
      return;
    }
    if(pos < 1){
      std::cout << "Invalid postition";
      return ;
    }
    else {

      Node* current = head;
      int currentPos = 1;
      while(currentPos < pos -1 ){
        current = current->next;
        currentPos++;
        if(current = head){
          std::cout  << "Invalid position ";
          return;
        }
      }
      current->next = current->next->next;
      if(current->next == head){
        tail =current;
      }
      delete current;
     
    }

  }
  Node *findNode(int targetValue){
    Node* current = head;
    while(current != nullptr){
      if(current->data == targetValue){
        return current;
      }
      

      current = current->next;
      if(current == head){
        break;
      }
    }
        return nullptr;

  }
  void delNode(Node* del){
    if(head == nullptr || del == nullptr) return;
    if(head == del || head== tail){
      deleteAtBeginning();
      return
    }
    if(tail == del){
      deleteAtEnd();
    }
    Node* current = head;
    while(current->next  != del && current->next != head){
     current = current->next;
    }
    if(current->next == del){
      current->next = del->next;
      delete del;
    }
  }
};
int main() {
    CircularList list;
    list.insertAtBeginning(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    std::cout << "Before: ";
    list.printList();

    std::cout << "After: ";
    list.deleteAtPos(0);
    list.printList();
    return 0;
}
