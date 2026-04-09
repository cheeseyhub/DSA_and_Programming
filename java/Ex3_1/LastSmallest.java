public class LastSmallest {
    public static int last_smallest(int[] list) {
        int location = 0,minValue = list[0];

        for (int i = 1 ; i < list.length; i++)
        {
            if(list[i] <= minValue)
            {
                minValue = list[i];
                location = i;
            }

        }
        return location;
    }
    public static void main(String[] args) {
        

        int[] myList = {1,2,3,4,5,6,7,123,3,1};

        System.out.println(last_smallest(myList));


    }
    
}
