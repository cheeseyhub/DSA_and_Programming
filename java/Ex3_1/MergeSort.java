import java.util.Random;

public class MergeSort {
    
    public static void printArray(int[] array)
    {
        System.out.print("[ ");
        for(int i = 0 ; i < array.length; i++)
        {

        System.out.print(array[i]+ " ,");
        }
        System.out.print("]\n");

    }
    public static void mergeSort(int[] inputArray)
    {
        if (inputArray.length < 2 )
        {
            return;
        }
        int middle = inputArray.length / 2;

        int[] firstHalf = new int[middle];
        int[] secondHalf = new int[inputArray.length - middle];



        System.arraycopy(inputArray,0,firstHalf,0, middle);
        System.arraycopy(inputArray,middle,secondHalf,0, inputArray.length - middle);


        mergeSort(firstHalf);
        mergeSort(secondHalf);

        // //Merge
        merge(inputArray, firstHalf, secondHalf);
    }
    public static void merge(int[] inputArray,int[] leftHalf, int[] rightHalf)
    {

        int leftSize = leftHalf.length;
        int rightSize =rightHalf.length; 


        int i = 0 , j  = 0  , k = 0;

        while( i< leftSize && j < rightSize)
        {
            if(leftHalf[i] <= rightHalf[j])
            {
                inputArray[k] = leftHalf[i];
            i++;
            }
            else {
                inputArray[k] = rightHalf[j];
            j++;
            }
            k++;
        }

        while( i < leftSize)
        {
            inputArray[k] = leftHalf[i];
            i++;
            k++;
        }
        while( j < rightSize)
        {
            inputArray[k] = rightHalf[j];
            j++;
            k++;
        }


    }
    public static void main(String[] args) {
        
        Random rand = new Random();

        int[] array1 = new int[10];
        for(int i = 0 ; i < 10 ; i++)
        {
            array1[i] = rand.nextInt(10000);
        }

        System.out.println("Before :");
        printArray(array1);

        mergeSort(array1);
        System.out.println("After : ");
        printArray(array1);






    }
}
