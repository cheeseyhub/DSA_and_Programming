from typing import  Generic, override
from typing import TypeVar
T = TypeVar("T")


class Node(Generic[ T ]):
    def __init__(self,data: T | None = None) -> None:
        self.val:T | None = data;
        self.next: Node[T] | None = None;



class LinkedList(Generic[T]):
    def __init__(self,newNode:Node[T]| None = None) -> None:
        self.head:Node[T]|None = newNode;  
        self.tail:Node[T]|None = newNode;

    def append(self,data:T) ->None:
        #create a new node of that data;
        new_node :Node[T]=Node(data);
        #if the head is empty then set the head to new node
        if self.head is None:
            self.head = new_node;
            self.tail = new_node;
            return;
            
        if self.tail :
            self.tail.next = new_node;
            self.tail = self.tail.next;


    def prepend(self,data:T)->None:
        new_node:Node[T] = Node(data);
        new_node.next = self.head;
        self.head = new_node;

    def shift(self) ->None:
        if self.head is None:
            return;
        self.head = self.head.next;

    def pop(self) ->None:
        if self.head is None or self.tail is None:
            return;

        if self.head == self.tail:
            self.head=None;
            self.tail=None;


        current:Node[T] | None = self.head;
        while current is not None and  current.next != self.tail:

            current =current.next;

        if current is not None:
            current.next = None;
            self.tail = current






    @override
    def __str__(self) -> str:

        if self.head is None:
            return "";

        string_to_return :str= ""
        current:Node[T]  = self.head;

        while current.next is not None:
            string_to_return  +=  f"{current.val} -> ";
            current = current.next;
            
        return string_to_return + str(current.val);

newList :LinkedList[int] =LinkedList();
newList.append(99)
newList.append(88888)
newList.prepend(909090909);
print(str(newList))

newList.pop();
print(str(newList))

newList.shift()
print(str(newList))
