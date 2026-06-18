#include <iostream>

class InsertionSort
{
public:
    // WRITE YOUR CODE HERE
    void sort(int array[], int size)
    {
        for (int i = 1; i < size; i++)
        {
            int element = array[i];
            int placeToInsert = i - 1;
            while (placeToInsert >= 0 && element < array[placeToInsert])
            {
                array[placeToInsert + 1] = array[placeToInsert];
                placeToInsert--;
            }
            array[placeToInsert + 1] = element;
        }
    }
};

int main()
{
    int array[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(array) / sizeof(array[0]);

    InsertionSort sorter;
    sorter.sort(array, n);

    std::cout << "Sorted array = {";
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i];
        if (i < n - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;

    return 0;
}
