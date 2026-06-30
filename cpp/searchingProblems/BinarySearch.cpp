#include <iostream>
class BinarySearch
{
public:
    int binarySearch(int array[], int size, int target)
    {
        int left = 0;
        int right = size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (array[mid] == target)
            {
                return mid;
            }
            if (array[mid] < target)
            {
                left = mid + 1;
            }
            if (array[mid] > target)
            {
                right = mid - 1;
            }
        }
        return -1;
    }
    int binaryRecursiveSearch(int array[], int left, int right, int target)
    {
        if (left > right)
        {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (array[mid] == target)
        {
            return mid;
        }

        if (array[mid] < target)
        {
            return binaryRecursiveSearch(array, mid + 1, right, target);
        }
        else if (array[mid] > target)
        {
            return binaryRecursiveSearch(array, left, mid - 1, target);
        }
    }
};
int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 3;

    BinarySearch bs;
    int result = bs.binaryRecursiveSearch(array, 0, size - 1, target);

    if (result == -1)
    {
        std::cout << "The element was not found " << std::endl;
    }
    else
    {
        std::cout << "The element was found at the index " << result << std::endl;
    }
}