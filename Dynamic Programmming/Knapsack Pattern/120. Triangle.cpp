//Recursive
int ans(vector<vector<int>>& triangle,int n,int i){
    if(n==triangle.size()-1) return triangle[n][i];
        return triangle[n][i]+min(ans(triangle,n+1,i+1),ans(triangle,n+1,i));
}
//Memoization
int memo_ans(vector<vector<int>>& triangle,int n,int i,vector<vector<int>>&dp){
    if(n==triangle.size()-1) return triangle[n][i];
    if(dp[n][i]!=-1) return dp[n][i];
        return dp[n][i]=triangle[n][i]+min(memo_ans(triangle,n+1,i+1,dp),memo_ans(triangle,n+1,i,dp));
}

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    //my dp vector for memo
    vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size()));
    for(auto &it: dp){
        for(auto &jt: it){
            jt=-1;
        }
    }
    // return ans(triangle,0,0);
    return memo_ans(triangle,0,0,dp);  
    }
