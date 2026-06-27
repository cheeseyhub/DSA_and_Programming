#include <iostream>
int *memo;

int fib(int n)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }

    if (n <= 1)
    {
        memo[n] = n;
    }
    else
    {
        memo[n] = fib(n - 1) + fib(n - 2);
    }

    return memo[n];
}

int main()
{
    int n = 40;
    memo = new int[n + 1];

    for (int i = 0; i <= n; ++i)
    {
        memo[i] = -1;
    }

    std::cout << "Fibonacci number at position " << n << " is: " << fib(n) << std::endl;

    delete[] memo;

    return 0;
}