#include <iostream>

// WRITE YOUR CODE HERE

class SelectionSort
{
public:
    static void selectionSort(int arr[], int n)
    {

        for (int i = 0; i < n; i++)
        {
            int minimumElementIndex = i;
            int j;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minimumElementIndex])
                {
                    minimumElementIndex = j;
                }
            }
            int temp = arr[minimumElementIndex];
            arr[minimumElementIndex] = arr[i];
            arr[i] = temp;
        }
    }
};

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort::selectionSort(arr, n);

    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
