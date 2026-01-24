
from typing import Generic, TypeVar, override

T= TypeVar("T")


class Node(Generic[ T ]):

    def __init__(self,data: T | None = None) -> None:
        self.val: T | None = data
        self.next:Node[T] | None = None
        self.prev:Node[T] | None = None

    @override
    def __str__(self) -> str:
        return str(self.val)


class doubly_linked_list(Generic[T]):
    def __init__(self,newNode:Node[T] | None =None) -> None:
        self.head:Node[T] | None = newNode
    
    def append(self,val:T ) ->None:
        if self.head is None:
            self.head = Node(val)
            return
        current:Node[T] = self.head
        while current.next:
            current = current.next

        new_node:Node[T] = Node(val)
        current.next = new_node
        new_node.prev = current

    def prepend(self,val:T)-> None:
        new_node :Node[T]= Node(val)
        if self.head is None:
            self.head = new_node
            return

        self.head.prev = new_node

        new_node.next = self.head
        self.head = new_node

        return

    def shift(self) ->None:
        if self.head is None:
            return

        # if only one node just set head to None;
        if self.head.next is None:
            self.head = None
            return

        #Make pointer to start
        start = self.head

        #Move the head forward and remove pointer to prev;
        self.head = self.head.next
        self.head.prev = None

        #remove pointers of the start
        start.next = None
        start.prev = None

    def pop(self)-> T | None :
        if self.head is None:
            return None
        if self.head.next is None:
            val = self.head.val
            self.head = None
            return val



        current: Node[T]|None= self.head
        while current.next is not None:
            current = current.next


        previous_node:Node[T]|None = current.prev

        # remove pointers of node
        current.prev = None
        current.next = None

        # clear the previous node pointer to current node;
        if previous_node:
            previous_node.next = None

        return current.val

    def insert_at(self,index_to_insert:int,val:T)->None:
        if index_to_insert  <= 0 or self.head is None:
            self.prepend(val)
            return

        current = self.head
        current_index = 0
        while current.next is not None and current_index < index_to_insert  :
            current = current.next
            current_index+=1

        # if index that is too large is given then throw error;
        if current_index < index_to_insert:
            raise Exception("Invalid index;")

        #if at the end just append;
        if current.next is None:
            self.append(val)
            return

        new_node = Node(val)


        next_node = current.next
        next_node.prev = new_node


        new_node.prev= current
        new_node.next = next_node

        current.next = new_node
        



    def remove_at(self,index_to_remove:int) ->None:

        if self.head is None or index_to_remove == 0:
            self.shift()
            return

        current_index:int = 0
        current = self.head
        while current.next is not None and current_index < index_to_remove :
            current = current.next
            current_index+=1

        # if index that is too large is given then throw error;
        if current_index < index_to_remove:
            raise Exception("Invalid index;")

        if current.next is None:
            _ =self.pop()
            return
        previous_node = current.prev
        next_node = current.next

        current.next = None
        current.prev = None

        assert previous_node is not None
        previous_node.next = next_node
        next_node.prev = previous_node


    @override
    def __str__(self) -> str:
        elements:list[str] = []
        current = self.head
        while current:
            elements.append(str(current.val))
            current = current.next
        return " <--> ".join(elements)


newList:doubly_linked_list[int] = doubly_linked_list(Node(5))
newList.append(900)
newList.append(500)
newList.remove_at(0)
print(str(newList))


