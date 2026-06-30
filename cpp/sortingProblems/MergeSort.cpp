#include <iostream>

class MergeSort
{
private:
    void merge(int array[], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = (right - mid);

        int *leftArray = new int[n1];
        int *rightArray = new int[n2];

        for (int i = 0; i < n1; i++)
        {
            leftArray[i] = array[left + i];
        }
        for (int i = 0; i < n2; i++)
        {
            rightArray[i] = array[mid + i + 1];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2)
        {
            if (leftArray[i] <= rightArray[j])
            {
                array[k] = leftArray[i];
                i++;
            }
            else
            {
                array[k] = rightArray[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            array[k] = leftArray[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            array[k] = rightArray[j];
            j++;
            k++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }

public:
    void sort(int array[], int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            sort(array, left, mid);
            sort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }
};

int main()
{
    int array[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int size = sizeof(array) / sizeof(array[0]);

    // Sort the array
    MergeSort sorter;
    sorter.sort(array, 0, size - 1);

    // Print the sorted array
    std::cout << "Sorted array: { ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i];
        if (i < size - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;

    return 0;
}
