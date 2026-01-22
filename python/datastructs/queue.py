from typing import Generic,TypeVar, override
T = TypeVar("T")

class Queue(Generic[T]):

    def __init__(self) -> None:
        self.size :int = 0;
        self.queue:list[T] = [];

    def enqueue(self,val:T) -> None:
        self.queue.append(val);
        self.size +=1;

    def dequeue(self) ->None:
        if self.isEmpty():
            return;
        _ = self.queue.pop(0);
        self.size -=1;
        
    def isEmpty(self)->bool:
        if len(self.queue) == 0:
            return True
        else:
            return False;

    def peek(self) ->str:
        if self.isEmpty():
            return "Queue is empty";
        return str(self.queue[0]);

    def len(self) ->int :
        return self.size;

    @override
    def __str__(self) -> str:
        string_to_return = "[";
        for item in self.queue:
            string_to_return += " " + str(item)  ;
        return string_to_return + " ]";


myQueue:Queue[int] = Queue();

myQueue.enqueue(8);
myQueue.enqueue(2);

myQueue.dequeue();

print(str(myQueue));

