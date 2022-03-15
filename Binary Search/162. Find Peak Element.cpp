// BS ON ANS CONCEPT
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //2 edgecases
        int n = nums.size();
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        
        // main check
        int l=1;int r=n-2;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        //dummy return
        return 1;
    }
};
