#include <iostream>
#include <cmath>

int jumpSearch(int arr[], int size, int target)
{
    int step = std::floor(std::sqrt(size));

    int prev = 0;
    while (arr[std::min(step, size) - 1] < target)
    {
        prev = step;
        step += std::floor(std::sqrt(size));
        if (prev >= size)
        {
            return -1;
        }
    }
    for (int i = prev; i < std::min(step, size); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = jumpSearch(arr, size, target);

    if (result == -1)
    {
        std::cout << "Element not found." << std::endl;
    }
    else
    {
        std::cout << "Element found at index: " << result << std::endl;
    }
    return 0;
}
