
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, p[101], dp[101][101] = {0};

    cout << "Enter number of matrices: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid number of matrices.";
        return 0;
    }

    cout << "Enter dimensions: ";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    // Chain length
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: "
         << dp[1][n];

    return 0;
}
