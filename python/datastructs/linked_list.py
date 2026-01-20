from typing import  Generic, override
from typing import TypeVar
T = TypeVar("T")


class Node(Generic[ T ]):
    def __init__(self,data: T) -> None:
        self.val:T= data;
        self.next: Node[T] | None = None;



class LinkedList(Generic[T]):
    def __init__(self,newNode:Node[T]| None = None) -> None:
        self.head:Node[T]|None = newNode;  

    def append(self,data:T) ->None:
        #create a new node of that data;
        new_node :Node[T]=Node(data);
        #if the head is empty then set the head to new node
        if self.head is None:
            self.head = new_node;
            return;
        # Other wise keep looping through and and the node to the end;
        current :Node[T]= self.head;
        while current.next is not None:
            current = current.next;
        current.next = new_node;
    def prepend(self,data:T)->None:
        new_node:Node[T] = Node(data);
        new_node.next = self.head;
        self.head = new_node;


    @override
    def __str__(self) -> str:
        if self.head is None:
            return "";
        string_to_return :str= ""
        current:Node[T] = self.head;

        while current.next is not None:
            string_to_return  +=  f"{current.val} -> ";
            current = current.next;
            
        return string_to_return + str(current.val);


newNode = Node(99);
newLink:LinkedList[int] = LinkedList(newNode);
newLink.prepend(999090);
print(newLink)
