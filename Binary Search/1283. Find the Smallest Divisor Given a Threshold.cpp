bool f(int mid,vector<int> nums,int threshold){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=ceil( (nums[i]/(float)mid) );
    }
    if(sum<=threshold){
        return true;
    }
    return false;
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=*max_element(nums.begin(),nums.end());
        int l=1;int r=maxi;
        int result=maxi;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(mid,nums,threshold)){
                result=mid;
                 r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};
