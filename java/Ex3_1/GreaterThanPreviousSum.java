import java.util.ArrayList;

public class GreaterThanPreviousSum {

    public static ArrayList<Integer> greaterTerms(Integer[] list)
    {
        ArrayList<Integer> result = new ArrayList<>();

        for(int i = 0 ; i < list.length; i++)
        {
            int currentSum = 0;
            for (int j = 0 ; j <i;j++)
            {
                currentSum +=list[j];
            }
            if(list[i] > currentSum){
                result.add(list[i]);
            }
        }
        return result;

    }
    public static ArrayList<Integer> greaterTermsRunning(Integer[] list)
    {
        ArrayList<Integer> result = new ArrayList<>();

            int currentSum = 0;

        for(int i = 0 ; i < list.length; i++)
        {
            if(list[i] > currentSum)
            {
                result.add(list[i]);
            }
            currentSum += list[i];

        }
        return result;

    }
    public static void main(String[] args) {
        
        Integer[]  myList = {1,3,5,2,99,1000};
        System.out.println(greaterTerms(myList));
    }
    
}
