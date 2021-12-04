#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> coins{1, 5, 7};
int dp[100005];

ll min_coin(int i)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    ll result = INT_MAX;
    for (int j = 0; j < coins.size(); j++)
    {
        if (coins[j] > i)
            continue;

        result = min(result, 1 + min_coin(i - coins[j]));
    }
    return dp[i] = result;
}

ll coin_TB(int n)
{
    vector<int> Dp(n + 1, INT_MAX);
    Dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (coins[j] > i)
                continue;
            Dp[i] = min(Dp[i], 1 + Dp[i - coins[j]]);
        }
    }
    return Dp[n];
}

int main()
{
    memset(dp, -1, sizeof dp);
    // cout << min_coin(11) << "\n";
    cout << coin_TB(11) << "\n";
    return 0;
}
