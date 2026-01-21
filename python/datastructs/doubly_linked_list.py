from typing import Generic,override
from typing import TypeVar
T= TypeVar("T");


class Node(Generic[ T ]):

    def __init__(self,data: T | None = None) -> None:
        self.val: T | None = data;
        self.next:Node[T] | None = None;
        self.prev:Node[T] | None = None;

    @override
    def __str__(self) -> str:
        return str(self.val);


class doubly_linked_list(Generic[T]):
    def __init__(self,newNode:Node[T] | None =None) -> None:
        self.head:Node[T] | None = newNode;
    
    def append(self,val:T ) ->None:
        if self.head is None:
            self.head = Node(val);
            return;
        current:Node[T] = self.head;
        while current.next:
            current = current.next

        new_node:Node[T] = Node(val);
        current.next = new_node;
        new_node.prev = current;

    def prepend(self,val:T)-> None:
        new_node :Node[T]= Node(val)
        if self.head is None:
            self.head = new_node;
            return;

        self.head.prev = new_node

        new_node.next = self.head;
        self.head = new_node;

        return;

    def pop(self)-> T | None :
        if self.head is None:
            return self.head;


        current: Node[T]|None= self.head;
        while current.next is not None:
            current = current.next;


        previous_node:Node[T]|None = current.prev;

        # remove pointers of node
        current.prev = None;
        current.next = None;

        if previous_node is None:

            #if there is only one element current head is now none.

            self.head = None;
        else:
        # clear the previous node pointer to current node;
            previous_node.next = None;

        return current.val;



    @override
    def __str__(self) -> str:
        elements:list[str] = [];
        current = self.head;
        while current:
            elements.append(str(current.val));
            current = current.next;
        return " <--> ".join(elements);


newList:doubly_linked_list[int] = doubly_linked_list(Node(5));
newList.append(90);
newList.append(30);
_ = newList.pop();
print(str(newList));


