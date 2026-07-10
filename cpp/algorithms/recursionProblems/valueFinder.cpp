#include <iostream>

class Max
{
public:
    int maxValue(int array[], int left, int right)
    {
        if (right - left <= 1)
        {
            return array[left] > array[right] ? array[left] : array[right];
        }
        else
        {
            int mid = left + (right - left) / 2;
            int rightMost = maxValue(array, mid, right);
            int leftMost = maxValue(array, left, mid);

            return rightMost > leftMost ? rightMost : leftMost;
        }
    }
    int minValue(int array[], int left, int right)
    {
        if (right - left <= 1)
        {
            return array[left] < array[right] ? array[left] : array[right];
        }
        int mid = left + (right - left) / 2;
        int rightMin = minValue(array, mid, right);
        int leftMin = minValue(array, left, mid);
        return rightMin < leftMin ? rightMin : leftMin;
    }
};

int main()
{
    int array[] = {0, -9, 13, 4, 645, 86, -67, 230, 21, 42};
    Max mx;
    int result = mx.maxValue(array, 0, sizeof(array) / sizeof(array[0]) - 1);
    int minResult = mx.minValue(array, 0, sizeof(array) / sizeof(array[0]) - 1);
    // Output the result
    std::cout << "The element with the greatest value is: " << result << std::endl;
    std::cout << "The element with the least value is: " << minResult << std::endl;

    return 0;
}
