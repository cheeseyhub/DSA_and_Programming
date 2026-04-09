public class BubbleSort {
    

    public static int[] bubbleSort(int[] list)
    {

        boolean swapped = false;
        int n = list.length -1 ;
        do{
            swapped = false;

            for(int i = 0 ; i < n;i++)
            {
                if(list[i] > list[i+1])
                {
                    int temp = list[i+1];
                    list[i+1] = list[i];
                    list[i] = temp;
                    swapped = true;

                }
            }
            n--;

        }
        while(swapped);
        return list;
    }
    public static int[] bubbleSortOptimized(int[] list)
    {

        int n = list.length -1 ;
        for(int i = 0 ; i < n;i++)
        {
            for(int j = 0 ; j <n - i;j++)
            {
                if(list[j] > list[j + 1]){
                int temp  = list[j + 1];
                list[j+1] = list[j];
                list[j] = temp;
                }
            }
        }
        return list;
    }
    public static void main(String[] args) {
        
        int[] myList = {2,2,3,1,4,1,3,5};
        int[] sorted = bubbleSortOptimized(myList);
        for(int i : sorted)
        {
            System.out.print(i+" ,");
        }
    }
    

}
