public class BinarySearch {
    public static long binarySearch(long[] list,long x)
    {
        int start = 0;
        int end = list.length ;

        while (start < end ){
            int middle = (start) + (end - start) / 2;
            if (list[middle]  == x )
            {
                return  middle;
            }
            else if (list[middle] < x ){
                start = middle + 1;
            }
            else {
                end = middle ;
            }


        }

        return -1;
    }
    public static void main(String args[])
    {

        long[] a = {4,5,8};
        System.out.println(binarySearch(a, 8));

    }
    
}
