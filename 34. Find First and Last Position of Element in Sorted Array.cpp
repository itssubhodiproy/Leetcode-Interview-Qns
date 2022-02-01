class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        //for first occurence
        int start1=0;
        int end1=nums.size()-1;
        //for last occurence
        int start2=start1;
        int end2=end1;
        
        // binary search for first occurence;
        int ans1=-1;
        while(start1<=end1){
            int mid=(start1+end1)/2;
            
            if(nums[mid]==target){
               ans1=mid; 
               end1=mid-1;
            } 
            else if(nums[mid]>target){
                
                end1=mid-1;
            }
            else{
                start1=mid+1;
            }
        }
        ans.push_back(ans1);
        
        // check for last occurence
        int ans2=-1;
        while(start2<=end2){
            int mid=(start2+end2)/2;
            
            if(nums[mid]==target){
               ans2=mid; 
               start2=mid+1;
            }
            else if(nums[mid]>target){
                
                end2=mid-1;
            }
            else{
                start2=mid+1;
            }
        }
        ans.push_back(ans2);
      
      
      
//       returning ans vector
        return ans;
        }
};
