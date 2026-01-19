from typing import override



class Point:
    def __init__(self,x:int ,y :int ) -> None:
        self.x:int  = x;
        self.y:int  = y;
    @override
    def __str__(self) ->str:
        return f"[ {self.x}, {self.y} ]";


class Shape:
    def __init__(self,points :list[Point]) ->None:
        self.points :list[Point]= points;
    @override
    def __str__(self) -> str:

        points_string :str= ""
        for point in self.points:
            points_string += str(point);
        return points_string;

class Rectangle:
    def __init__(self,length:int ,width :int) -> None:
        self.length: int = length;
        self.width: int = width;
    def area(self) -> int :
        return self.length * self.width;
    @override
    def __str__(self) -> str:
        return f"Area is  : {str(self.length * self.width)}"


class Square(Rectangle):
    def __init__(self, length: int) -> None:
        super().__init__(length, length)

    @override
    def __str__(self) -> str:
        return f"Area is  : {str(self.length * self.width)}"



normal_rectangle :Rectangle= Rectangle(30,90);
print(normal_rectangle);

normal_square:Square = Square(30);
print(normal_square)
        




