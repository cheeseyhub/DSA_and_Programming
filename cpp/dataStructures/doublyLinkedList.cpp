#include <iostream>


class Node{
  public:
  int data;
  Node* next;
  Node* prev;
  Node(int data){
    this->data = data;
    this->next =nullptr;
    this->prev =nullptr;

  }
};
class DoublyLinkedList{
  public:
  Node* head;
  Node* tail;
  DoublyLinkedList() {
    head = nullptr;
    tail =nullptr;

  }
  void printList() {

    Node* temp = head;
    while(temp != nullptr){
      std::cout << temp->data << " ";
      temp = temp->next;

    }
    std::cout << std::endl;
  }
  void reversePrint(){
    Node* temp = tail;
    while(temp != nullptr)
    {
      std::cout << temp->data << " ";
      temp = temp->prev;
    }
  }
  void insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if(head != nullptr){
    head->prev = newNode;
    }
    head = newNode;
    if(head->next == nullptr){
      tail = newNode;
    }

  }
  void deleteAtBeginning(){
    if(head ==nullptr){
      return;
    }
    Node* temp = head;

    head = head->next;
    if(head !=nullptr){
      head->prev = nullptr;

    }
    else {
      tail = nullptr;
    }
    delete temp;
  }
  void deleteAtEnd(){
    if(tail == nullptr){
      return;
    }
    Node* temp = tail;
    tail = tail->prev;

    if(tail != nullptr){
      tail->next =nullptr;
    }
    else{
      head = nullptr;
    }
    delete temp;
  }
  void insertAtEnd(int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
      head = newNode;
      tail = newNode;
    }
    else {
    tail->next = newNode;
    newNode->prev =tail;
    tail = newNode;
    }
  }
    void insertAtPos(int data, int pos){
      if(pos < 1 ){
        std::cout << "Invalid position " << std::endl;
        return;
      }
      if(pos == 1){;
        insertAtBeginning(data);
      }
      else {
        Node* current = head;
        int location = 1;
          Node* newNode = new Node(data);

        while(location < pos - 1  && current != nullptr){
          current = current->next;
          location++;
          if(current->next == nullptr){
          std::cout<< "Invalid postion : " << std::endl;
          return;
        }

        newNode->prev = current;
        newNode->next = current->next;
        if(current->next == nullptr){
          tail=newNode;

        }
        else{
          current->next->prev = newNode;
        }
        current->next = newNode;
        }
        

      }
    }
    void deleteAtPos(int pos){
      if(pos < 1){
        std::cout << "Invalid position " <<std::endl;
      }
      if(pos == 1){
        deleteAtBeginning();
      }
      else{
        Node* current = head;
        int currentPos = 1;
        while(currentPos < pos && current != nullptr){
          current = current->next;
          currentPos++;

        }
        if(current == nullptr){
        std::cout << "Invalid position " <<std::endl;

          return;
        }

        current->prev->next = current->next;
        if(current ->next == nullptr){
          tail = current->prev;
        }
        else{
          current->next->prev = current->prev;
        }
        delete current;
        
      }
    }
    Node* findNode(int value){
      Node* currentNode = head;
      while(currentNode !=nullptr){
        if(currentNode->data == value){
          return currentNode;
        }
        currentNode = currentNode->next;
      }

      return nullptr;
    }

    void deleteNode(Node* del){
      if(head == nullptr || del == nullptr ) return;

      if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
      }
      if(head == del){
        deleteAtBeginning();
        return;
      }
      if(tail == del)
      {
        deleteAtEnd(); return;
      }
      del->prev->next = del->next;
      del->next->prev = del->prev;
      delete del;
    }
  };
int main() {
    DoublyLinkedList list;

    std::cout << "Before: ";
    list.insertAtBeginning(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.printList();

    std::cout << "After: ";
    Node* target = list.findNode(3);
    list.deleteNode(target);
    list.printList();
    return 0;
}
