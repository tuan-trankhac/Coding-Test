#include <iostream>
#include <vector>

using namespace std;

int countWays(int x, int y)
{
    vector<vector<int> > dp(x + 1, vector<int>(y + 1, 0));

    // base 0-0
    dp[0][0] = 1;

    // x-y
    for (int i = 0; i <= x; ++i)
    {
        for (int j = 0; j <= y; ++j)
        {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }

    // result
    return dp[x][y];
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int> > matrix(2, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1];
    }

    for (int i = 0; i < N; i++)
    {
        cout << countWays(matrix[i][0], matrix[i][1]) << endl;
    }

    return 0;
}
