import java.util.ArrayList;
import java.util.List;

public class RecursiveMin {

    public static <T extends Comparable<T>> T recursiveMin(List<T> list) {
        T currentMin = list.getLast();

        if (list.size() == 1) {
            return currentMin;
        }

        T otherMin = recursiveMin(list.subList(0, list.size() - 1));

        if (currentMin.compareTo(otherMin) < 0) {
            return currentMin;
        } else {
            return otherMin;
        }

    }

    public static void main(String[] args) {
        ArrayList<Integer> array = new ArrayList<>();
        array.add(34);
        array.add(234);
        array.add(12);
        array.add(-89);
        array.add(-123);
        array.add(-39);

        System.out.println(recursiveMin(array));
    }

}
