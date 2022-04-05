// memoization
int memo(vector<int>nums,int i,vector<int> &dp){
    if(i<0) return 0;
    if(i==0) return nums[i];
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(nums[i]+memo(nums,i-2,dp),memo(nums,i-1,dp));
}
// Tabulation
int tabu(vector<int>nums){
vector<int>dp1(nums.size());
dp1[0]=nums[0];
 dp1[1]=max(nums[0], nums[1]);
    for(int i=2;i<nums.size();i++){
        dp1[i]=max(nums[i]+dp1[i-2],dp1[i-1]);
    }
    return dp1[nums.size()-1];
}

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        // vector<int> dp(401,-1);
        // return memo(nums,nums.size()-1,dp);
        return tabu(nums);
    }
};
