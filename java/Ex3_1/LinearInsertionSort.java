public class LinearInsertionSort {
    
    

    public static int[] linearInsertionSort(int[] list)
    {
        for(int i = 1 ; i < list.length ;i++)
        {

            int indexToInsert = linearSearch(list, i);

            int temp = list[i];
            for(int k = i ; k > indexToInsert;k--)
            {
                list[k] = list[k-1];
            }
            list[indexToInsert] = temp;

        }
        return list;
    }
    public static int linearSearch(int[]list ,int comparedIndex)
    {
        // for(int i = 0 ; i < comparedIndex;i++)
        // {
        //     if(list[comparedIndex] < list[i]){
        //         return i;
        //     }
        // }
        // return 0;
        int i;
        for(i = 0 ; i <comparedIndex;i++ )
        {
            if(list[comparedIndex] < list[i])
            {
                break;
            }
        }
        return i;

    }

    public static void main(String[] args) {
        
        int[] myList = {3,4,9,5,1,3,9};
        int[] sorted = linearInsertionSort(myList);
        for(int i : sorted)
        {
            System.out.print(i+" ,");
        }
    }
    


    
}

