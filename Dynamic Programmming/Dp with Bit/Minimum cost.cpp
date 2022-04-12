#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
int cost[21][21];
int dp[21][(1<<21)];
 
int solve(int i, int mask, int& n)
{
    if(i == n)
        return 0;
 
    if(dp[i][mask] != -1)
        return dp[i][mask];
 
    int answer = INT_MAX;
    for(int j = 0; j < n; j++)
    {
        if(mask&(1<<j))
            answer = min(answer, cost[j][i] + solve(i+1, (mask^(1<<j)), n));
    }
 
    return dp[i][mask] = answer;
}
 
int main() {
   fast_io;
   int t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   memset(dp, -1, sizeof dp);
   while(t--)
   {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> cost[i][j];
        }
        cout << solve(0, (1<<n) - 1, n) << '\n';
   }
 
   return 0;
}
