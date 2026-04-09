public class TernerySearch {
    public static int ternerySearch(int[] list, int x) {

        int start = 0;
        int end = list.length -1;

        while (start <= end) {
            int m1 = start + (end - start) / 3;
            int m2 = end - (end - start) / 3;

            if (x == list[m1]) {
                return m1;
            } else if (x == list[m2]) {
                return m2;
            } else if (x < list[m1]) {
                end = m1 - 1;
            } else if (x > list[m2]) {
                start = m2;
            } else {
                start = m1 + 1;
                end = m2 - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {

        int[] myList = { 1, 2, 3, 4, 5, 6, 7, 8 };
        System.out.println(ternerySearch(myList, 8));
    }

}
