int f(vector<int>nums,int i,vector<int> &dp){
    if(i<0) return 0;
    if(i==0) return nums[i];
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(nums[i]+f(nums,i-2,dp),f(nums,i-1,dp));
}

int tabu(vector<int>nums){
vector<int>dp1(nums.size());  
    dp1[0]=nums[0];
    dp1[1]=max(nums[0], nums[1]);
    
        for(int i=2;i<nums.size();i++){
            dp1[i]=max(nums[i]+dp1[i-2],dp1[i-1]);
        }
    return dp1[nums.size()-1];
}

int rob1(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        // vector<int> dp(1001,-1);
        // return f(nums,nums.size()-1,dp);
    return tabu(nums);
    }

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};
