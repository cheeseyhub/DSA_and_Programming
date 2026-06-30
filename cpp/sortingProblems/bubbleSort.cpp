#include <iostream>

class BubbleSort
{
public:
    // WRITE YOUR CODE HERE
    static void bubbleSort(int arr[], int n)
    {
        bool swap;
        do
        {
            swap = false;
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i + 1] < arr[i])
                {
                    int temp = arr[i + 1];
                    arr[i + 1] = arr[i];
                    arr[i] = temp;
                    swap = true;
                }
            }
        } while (swap);
    }
};

int main()
{
    int arr[] = {62, 88, 17, 95, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort::bubbleSort(arr, n);

    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
