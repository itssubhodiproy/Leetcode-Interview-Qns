#include <iostream>
using namespace std;
int arr[1000];

// int stair(int n)                                <<<<<<<<<<<<<-------Memoization---------->>>>>>>>>>
// {

//     if (arr[n] != 0)
//     {
//         return arr[n];
//     }

//     if (n <= 2)
//     {
//         arr[n] = n;
//         return n;
//     }

//     arr[n] = stair(n - 1) + stair(n - 2);
//     return arr[n];
// }

 int stair(int n) {                                         ///////// <<<<<<<<----------Tabulation----------->>>>>>>>>>>
        int dp[n+1];
        dp[0]=1; dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

int main()
{
    int n;
    cin >> n;
    cout << stair(n) << endl;
    return 0;
}
