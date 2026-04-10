public class InsertionSort {
    

    public static int[] insertionSort(int[] list)
    {
        for (int i = 1 ; i < list.length;i++)
        {
            int temp = list[i];
            int j = i - 1;

            while(j >= 0 && list[j] > temp)
            {
                list[j+1] = list[j];
                j--;

            }
            list[j+1] = temp;
        }
        return list;
    }
    public static int[] bookInsertionSort(int[] list)
    {
        for(int i = 1 ; i < list.length ;i++)
        {
            int j = 0 ;
            while(list[i] > list[j])
            {
                j++;
            }


            int temp = list[i];
            for(int k = i ; k > j;k--)
            {
                list[k] = list[k-1];
            }
            list[j] = temp;

        }
        return list;
    }
    public static void main(String[] args) {
        
        int[] myList = {3,4,9,5,1,3,9};
        int[] sorted = bookInsertionSort(myList);
        for(int i : sorted)
        {
            System.out.print(i+" ,");
        }
    }
    


    
}
