public class FirstRepeating {
    public static int firstRepeat(int[] list)
    {
        for(int i = 0 ; i <list.length;i++)
        {
            for(int j = 0 ; j < i;j++)
            {
                if( list[i] == list[j])
                    return list[i];
                
            }
        }
        return -1;

    }
    public static void main(String[] args) {
        
        int[] myList = {3,4,1,5,1,5};
        System.out.println(firstRepeat(myList));
    }
    
}
