from typing import Generic, TypeVar, override;
T = TypeVar("T");




class Node(Generic[T]):
    def __init__(self,data:T | None = None) -> None:
        self.val:T|None = data;
        self.next:Node[T];

class circular_linked_list(Generic[T]):
    def __init__(self,data:T | None) -> None:

        if data is not None:
            self.head:Node[T]|None = Node(data);

            #Make new node point to self;
            self.head.next = self.head;
            self.length:int = 1;

        else :
            self.head = None;
            self.length = 0;


    def insert_at(self,data:T,index:int):

        new_node = Node(data);

        if index < 0 or index > self.length:
            raise Exception("Invalid index");
        

        if index == 0:
            if self.head is None:
                self.head = new_node;
                self.head.next = self.head;
            else:
                curr = self.head;
                while curr.next != self.head:
                    curr = curr.next;
                new_node.next = self.head;

                curr.next = new_node;
                self.head = new_node;
            
                self.length +=1;
                return;

        assert self.head;
        current:Node[T]  = self.head;
        counter:int = 0;
        while counter < index -1 :
            current = current.next;
            counter +=1;

        new_node.next = current.next;
        current.next = new_node;

        self.length +=1;
        

    def append(self,data:T) ->None:
        self.insert_at(data,self.length  );

    def prepend(self,data:T) ->None:
        self.insert_at(data,0);


    def remove_at(self,index:int) ->None:

        if index <0 or index >= self.length:
            raise Exception("Invalid index");

        if self.head is None  or self.length == 1:
            self.head = None;
            self.length -=1;
            return;


        if index == 0:
            last = self.head;
            while last.next !=self.head:
                last = last.next;
            self.head = self.head.next;
            print(self.head.val);
            last.next = self.head;
            self.length -=1;
            return;

        current = self.head;
        for i in range(index -1):
            current = current.next;

            
        

        current.next = current.next.next; 
        self.length -=1;
        return;




    @override
    def __str__(self) -> str:
        string_to_return :str= ""
        if self.head is None:
            return string_to_return;

        current:Node[T] = self.head;

        for i in range(self.length):
            string_to_return += str(current.val) + " -> ";
            current= current.next;


        return string_to_return + str(current.val);


circle:circular_linked_list[int] = circular_linked_list(5);
circle.append(10)
circle.append(19)
circle.remove_at(0)
print(str(circle))
