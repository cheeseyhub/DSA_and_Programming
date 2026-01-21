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
        self.length :int = 0;
        if newNode :
            self.length += 1;

    def append(self,data:T) ->None:
        self.length+=1;
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
            return;


    def prepend(self,data:T)->None:
        new_node:Node[T] = Node(data);
        new_node.next = self.head;
        self.head = new_node;
        self.length +=1;

    def shift(self) ->None:
        if self.head is None:
            return;
        self.head = self.head.next;
        self.length -=1;

    def pop(self) ->None:
        if self.head is None or self.tail is None:
            return;

        if self.head == self.tail:
            self.head=None;
            self.tail=None;

        self.length -=1;

        current:Node[T] | None = self.head;
        while current is not None and  current.next != self.tail:

            current =current.next;

        if current is not None:
            current.next = None;
            self.tail = current


    def insert_at(self,data:T,index:int) -> None:
        if index == 0 :
            self.prepend(data);
            return;

        # if no head then just append at start;
        if self.head is None:
            self.append(data);
            return;


        #if add at the end then just do append;
        if index == self.length   -1 :
            self.append(data);
            return;


        counter = 0;
        current:Node[T]= self.head;
        while current.next is not None and counter < index  - 1 :
            current = current.next;
            counter+= 1;

        new_node:Node[T] | None= Node(data);

        #Get the right side of the linked list
        right_side:Node[T] | None = current.next ;

        #set the right side of linked list to the new node next;
        new_node.next = right_side;

        #then set the current.next to the new node;
        current.next = new_node;
        self.length += 1;


    def remove_at(self,index:int):
        
        if index == self.length -1 :
            self.pop();
            return;
        if index == 0  or self.head is None:
            self.shift();
            return;


        counter =0;
        current:Node[T] | None= self.head;
        while  current.next is not None and counter <index - 1:
            current = current.next;
            counter +=1;

        current.next = current.next.next;
        self.length -=1;







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



newList : LinkedList[int] =LinkedList();
newList.append(99)
newList.append(8888)
newList.append(78)

newList.insert_at(33,2)


print(str(newList));

