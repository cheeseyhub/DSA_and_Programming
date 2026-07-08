#include <iostream>

void printArray(int array[], int size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << "]" << std::endl;
}
int summantion(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}
float average(int array[], int size)
{
    return summantion(array, size) / (float)size;
}

class sort

{

public:
    static void swap(int array[], int i, int j)
    {

        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
    static int parition(int array[], int low, int high)
    {
        int pivot = array[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                swap(array, i, j);
            }
        }
        swap(array, i + 1, high);
        return i + 1;
    }
    static void quicksort(int array[], int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = parition(array, low, high);
            quicksort(array, low, pivotIndex - 1);
            quicksort(array, pivotIndex + 1, high);
        }
    }
};
float medianOfData(int array[], int size)
{
    sort::quicksort(array, 0, size - 1);
    if (size % 2 == 0)
    {
        // std::cout << array[(size / 2) - 1] << std::endl;
        // std::cout << array[(((size / 2) + 1) - 1)];
        return (array[(size / 2) - 1] + array[(size / 2 + 1) - 1]) * (0.5);
    }

    return array[(size / 2) - 1];
}

int main()
{
    int array[] = {1075, 1050, 2050, 1030, 2045, 1090, 1530};
    int array2[] = {40, 35, 45, 60, 50, 35, 40, 45, 35, 50};
    int size = sizeof(array2) / sizeof(array2[0]);
    std::cout << "The median of the data is " << medianOfData(array2, size);

    return 0;
}