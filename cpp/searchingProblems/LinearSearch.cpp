#include <iostream>
class LinearSearch
{
public:
    int linearSearch(int array[], int size, int target)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 3;
    LinearSearch ls;

    int result = ls.linearSearch(array, size, target);
    if (result == -1)
    {
        std::cout << "Element not found in the array " << std::endl;
    }
    else
    {
        std::cout << "Element found at index: " << result << std::endl;
    }
    return 0;
}