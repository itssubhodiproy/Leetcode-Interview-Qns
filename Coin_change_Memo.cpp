// // Level order traversal using Queue Data-structure in C++
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
    return dp[i]= result;
}

int main()
{
    memset(dp, -1, sizeof dp);
    cout << min_coin(11) << "\n";
    return 0;
}
// }
// A Naive recursive C++ program to find minimum of coins
// to make a given change V
// #include<bits/stdc++.h>
// using namespace std;

// // m is size of coins array (number of different coins)
// int minCoins(int coins[], int m, int V)
// {
// // base case
// if (V == 0) return 0;

// // Initialize result
// int res = INT_MAX;

// // Try every coin that has smaller value than V
// for (int i=0; i<m; i++)
// {
// 	if (coins[i] <= V)
// 	{
// 		int sub_res = minCoins(coins, m, V-coins[i]);

// 		// Check for INT_MAX to avoid overflow and see if
// 		// result can minimized
// 		if (sub_res != INT_MAX && sub_res + 1 < res)
// 			res = sub_res + 1;
// 	}
// }
// return res;
// }

// // Driver program to test above function
// int main()
// {
// 	int coins[] = {9, 6, 5, 1};
// 	int m = sizeof(coins)/sizeof(coins[0]);
// 	int V = 11;
// 	cout << "Minimum coins required is "
// 		<< minCoins(coins, m, V)<<"\n";
// 	return 0;
// }
