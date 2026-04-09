public class smallerThanPreceding {

    public static int lessPreceding(int[] list)
    {
        for(int i = 0 ; i < list.length -1 ; i++)
        {
            if(list[i+1] < list[i])
            {
                return list[i+1];
            }
        }
        return -1 ;
    }
    public static void main(String[] args) {
        
        int[] myList = {2,2,3,4,5,1};
        System.out.println(lessPreceding(myList));
    }
    
}
