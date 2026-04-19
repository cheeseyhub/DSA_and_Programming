import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

public class ParallelMergeSort extends RecursiveAction {

    private int[] array;

    public ParallelMergeSort(int[] array) {
        this.array = array;
    }

    protected void compute() {
        if (array.length < 2) {
            return;
        }

        int middle = array.length / 2;

        // First half
        int[] firstHalf = new int[middle];
        int[] secondHalf = new int[array.length - middle];

        System.arraycopy(array, 0, firstHalf, 0, middle);
        System.arraycopy(array, middle, secondHalf, 0, array.length - middle);

        ParallelMergeSort leftTask = new ParallelMergeSort(firstHalf);
        ParallelMergeSort rightTask = new ParallelMergeSort(secondHalf);

        leftTask.fork();
        rightTask.compute();
        leftTask.join();

        merge(array, firstHalf, secondHalf);

    }

    public static void merge(int[] array, int[] firstHalf, int[] secondHalf) {

        int i = 0, j = 0, k = 0;

        while (i < firstHalf.length && j < secondHalf.length) {
            if (firstHalf[i] <= secondHalf[j]) {
                array[k] = firstHalf[i];
                i++;
            } else {
                array[k] = secondHalf[j];
                j++;
            }
            k++;
        }

        while (i < firstHalf.length) {
            array[k] = firstHalf[i];
            k++;
            i++;
        }
        while (j < secondHalf.length) {
            array[k] = secondHalf[j];
            k++;
            j++;
        }

    }

    public static void printArray(int[] array) {
        System.out.print("[ ");
        for (int i = 0; i < array.length; i++) {

            System.out.print(array[i] + " ,");
        }
        System.out.print("]\n");

    }

    public static void main(String[] args) {

        int[] data = { 5, 2, 9, 1, 5, 6 };
        printArray(data);
        ForkJoinPool pool = new ForkJoinPool();

        ParallelMergeSort mainTask = new ParallelMergeSort(data);

        pool.invoke(mainTask);
        pool.close();
        printArray(data);
    }
}
