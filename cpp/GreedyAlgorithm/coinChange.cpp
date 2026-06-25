#include <iostream>
#include <algorithm>

class CoinChangeGreedy
{
public:
    int coinChange(int coins[], int n, int amount)
    {
        std::sort(coins, coins + n);
        int count = 0;
        for (int i = n - 1; i >= 0 && amount; i--)
        {

            while (amount >= coins[i])
            {
                amount -= coins[i];
                count++;
            }
        }

        return amount == 0 ? count : -1;
    }
};

int main()
{
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 30;

    CoinChangeGreedy coinCG;
    int result = coinCG.coinChange(coins, n, amount);

    if (result != -1)
    {
        std::cout << "Minimum coins needed : " << result << std::endl;
    }
    else
    {
        std::cout << "The amount cannot be represented using the given denomination" << std::endl;
    }
}
