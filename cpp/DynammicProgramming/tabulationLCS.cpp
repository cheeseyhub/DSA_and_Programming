#include <iostream>
#include <string>
#include <algorithm>

// WRITE YOUR CODE HERE
int longestCommonSubsequence(std::string A, std::string B)
{
    int m = A.length();
    int n = B.length();

    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    // Example strings A and B.
    std::string A = "BACBDAB";
    std::string B = "BDCAB";

    // Calculate and print the length of LCS.
    std::cout << "Length of LCS: " << longestCommonSubsequence(A, B) << std::endl;

    return 0;
}
