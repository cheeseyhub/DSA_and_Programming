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
    public static void main(String[] args) {
        
        int[] myList = {2,2,3,1,4,1,3,5};
        int[] sorted = insertionSort(myList);
        for(int i : sorted)
        {
            System.out.print(i+" ,");
        }
    }
    


    
}
