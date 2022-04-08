class Solution {
public:
// MEMO
    int solve(vector<int>& coins, int w,int n,vector<vector<int>>&memo){
        if(n==0 || w==0){
           return w==0? 0:INT_MAX - 1;
        }
        if(memo[w][n]!=-1) return memo[w][n];
        if(coins[n-1]>w){
            return memo[w][n] = 0 + solve(coins,w,n-1,memo);
        }
        else return memo[w][n] = min(0+solve(coins,w,n-1,memo),1+solve(coins,w-coins[n-1],n,memo));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>memo(amount+1,vector<int>(n+1,-1));
        int minCoins = solve(coins,amount,coins.size(),memo);
        return minCoins==INT_MAX-1?-1:minCoins;
    }
};
