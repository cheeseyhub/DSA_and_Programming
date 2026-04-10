public class BinarySearchSort {
        
    

    public static int[] binarySearchSort(int[] list)
    {
        for(int i = 1 ; i < list.length ;i++)
        {

            int indexToInsert = binarySearch(list, i);

            int temp = list[i];
            for(int k = i ; k > indexToInsert;k--)
            {
                list[k] = list[k-1];
            }
            list[indexToInsert] = temp;

        }
        return list;
    }
    public static int binarySearch(int[]list ,int comparedIndex)
    {
        int start = 0;
        int end = comparedIndex;
        int currentVal = list[comparedIndex];

        while(start < end)
        {
            int middle = start + (end - start ) /2 ;
            if(currentVal < list[middle])
            {
                end = middle;
            }
            else 
            {
                start = middle  + 1;
            }

        }
        return end;
    }

    public static void main(String[] args) {
        
        int[] myList = {1,2,3,3,4,0};
        int[] sorted = binarySearchSort(myList);
        for(int i : sorted)
        {
            System.out.print(i+" ,");
        }
    }
    


    

    
}
