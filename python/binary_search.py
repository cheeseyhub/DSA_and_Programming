
array = [10,20,30,50,80,90,100,150,300];

def binary_search_recursive(array: list[int],value: int ,start: int =0,end=None)  ->int | None :
    if end is None:
        end = len(array) -1;
    mid: int   = (start + end)  // 2;
    
    if start > end :
        return;
    if array[mid] == value:
        return mid;
    elif value > array[mid]:
        return binary_search_recursive(array,value,mid +1 , end);
    elif value < array[mid]:
        return binary_search_recursive(array,value,start,mid -1 );


def binary_search_loop(array: list[int],value: int )  ->int | None :
    
    start = 0;
    end = len(array ) -1;
    while start <= end:
        mid = (start + end )// 2;
        if array[mid] == value:
            return mid;
        elif value > array[mid]:
            start = mid + 1;
        elif value < array[mid]:
            end = mid - 1 ;

    return None;
    

print(binary_search_loop(array,10));

