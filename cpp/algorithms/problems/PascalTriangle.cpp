#include <iostream>
#include <vector>

double factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

double combination(int n, int r)
{
    return factorial(n) / (factorial(n - r) * factorial(r));
}

std::vector<std::vector<double>> generateTriangle(int numberOfRows)
{
    std::vector<std::vector<double>> triangle;

    for (double i = 0; i < numberOfRows + 1; i++)
    {
        std::vector<double> row;

        for (double j = 0; j <= i; j++)
        {
            row.push_back(combination(i, j));
        }
        triangle.push_back(row);
    }

    return triangle;
}
void printArray(std::vector<double> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << " " << array[i];
    }
}
void printTriangle(std::vector<std::vector<double>> triangle)
{
    for (int row = 0; row < triangle.size(); row++)
    {
        printArray(triangle[row]);
        std::cout << "\n";
    }
}
int main()
{

    std::vector<std::vector<double>> triangle = generateTriangle(5);

    printTriangle(triangle);

    return 0;
}