
array: list[int] =  [1,23,90,100];
def linear_search(ordered_array: list[int] ,value: int ) -> int | None :

    for i in range (0,len(ordered_array)):
        if ordered_array[i] == value:
            return i;
        elif ordered_array[i] > value:
            break;
    return None;



print(linear_search(array,100));






