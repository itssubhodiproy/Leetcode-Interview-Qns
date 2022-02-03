class Solution {
public:
    int findMin(vector<int>& nums) {
        //pointer initialization
        int start=0;
        int end=nums.size()-1;
        
        while(start < end){
            if(nums[start]<nums[end]){
                return nums[start];
            }
            int mid=(start+end)/2;
            // if middle is greater than end, right part of the array is not sorted
            // Need to check for the right
            if(nums[mid]>nums[end]){
                start=mid+1;
            }
            //left part of the array is not sorted,
            // Need to check for the left
            else{
                end=mid;
            }
        }
        return nums[start];
        
    }
};
