// WRITE YOUR CODE HERE
#include <algorithm>
#include <iostream>

class Item
{
public:
    int weight;
    int value;

    Item(int weight, int value) : weight(weight), value(value) {};
};
class FractionalKnapsack
{
private:
    static bool compare(Item a, Item b)
    {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        std::sort(arr, arr + n, compare);
        double totalValue = 0;
        for (int i = 0; i < n; i++)
        {
            if (W - arr[i].weight >= 0)
            {
                W -= arr[i].weight;
                totalValue += arr[i].value;
            }
            else
            {
                double fraction = (double)W / arr[i].weight;
                totalValue += arr[i].value * fraction;
                W = 0;
                break;
            }
        }
        return totalValue;
    }
};

int main()
{
    int W = 50;
    Item arr[] = {Item(10, 60), Item(20, 100), Item(30, 120)};
    int n = sizeof(arr) / sizeof(arr[0]);

    FractionalKnapsack knapsackSolver;
    std::cout << "Maximum value in knapsack = " << knapsackSolver.fractionalKnapsack(W, arr, n) << std::endl;

    return 0;
};