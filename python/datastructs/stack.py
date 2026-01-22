from typing import Generic,TypeVar
T = TypeVar("T");


class Stack(Generic[T]):
    
    def __init__(self) -> None:
        self._l: list[T] = []


    def push(self,val:T) ->None:
        self._l.append(val);



    def pop(self) -> T :
        if len(self._l) != 0:
            return self._l.pop();
        else:
            raise Exception("The stack is empty");



new_stack = Stack[int]();

new_stack.push(8);
print(new_stack.pop())
        
