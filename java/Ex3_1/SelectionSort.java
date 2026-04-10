public class SelectionSort {
        

    public static int[] selectionSort(int[] list)
    {

        for(int i = 0 ; i < list.length; i++)
        {
            int minLocation =findMin(list, i, list.length -1 );
            int temp = list[minLocation];
            list[minLocation] = list[i];
            list[i] = temp;
        }

        return list;
    }
    public static int findMin(int[] list,int startIndex,int endIndex)
    {
        int min = list[startIndex];
        int location = startIndex;
        for(int i = startIndex ; i<= endIndex;i++)
        {
            if(list[i] < min){
                min = list[i];
                location = i;
            }
            
        }
        return location;
    }

    public static void main(String[] args) {
        
        int[] myList = {3,4,9,5,1,3,9};
        int[] sorted = selectionSort(myList);
        for(int i : sorted)
        {
            System.out.print(i+" ,");
        }
    }
    


    

}
