#include <bits/stdc++.h>
using namespace std;
vector<int> dp(5,-1);

int min_jump(int i, int n, int arr[])         ////// Naive Recursion ///////
{
    if (i == n - 1)
    {
        return 0;
    }
    //if (arr[i]==0) return INT_MAX;
    //Have the edgecase where the array element is zero
    int result = INT_MAX;
    for (int j = 1; j <= arr[i]; j++)
    {
        if ((i + j) > n - 1)
            continue;
        result = min(result, 1 + min_jump(i + j, n, arr));
    }
    return result;
}

int min_jump_memo(int i, int n, int arr[])         ////// Memoization ///////
{
    if (i == n - 1)
    {
        return dp[i]=0;
    }
    //if (arr[i]==0) return INT_MAX;
    //Have the edgecase where the array element is zero
    if (dp[i]!=-1) return dp[i]; 
    int result = INT_MAX;
    for (int j = 1; j <= arr[i]; j++)
    {
        if ((i + j) > n - 1)
            continue;
        result = min(result, 1 + min_jump_memo(i + j, n, arr));
    }
    return dp[i]=result;
}





int main()
{
    // Write C++ code here
    int arr[] = {7, 5, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << min_jump_memo(0, n, arr) << "\n";

    return 0;
}
