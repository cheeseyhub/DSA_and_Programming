public class SortedMode {
    public static int Mode(int[] list)
    {
        int modeValue = list[0];
        int maxCount = 1;

        int currentMode = modeValue;
        int currentCount  = maxCount;

        for(int i = 1 ; i < list.length  ; i++)
        {
            if(list[i] == currentMode)
            {
                currentCount++;
            }
            else {
                currentCount = 1;
                currentMode = list[i];
            }

            
             if(currentCount > maxCount)
            {

                maxCount = currentCount;
                modeValue = currentMode;

            }

        }

        return modeValue;
    }
    public static void main(String[] args) {
        
        int[] myList ={ 1,1,2,2,3,3,3,4,5,6,7,8,9,10} ;

        System.out.println(Mode(myList));
    }
    
}
