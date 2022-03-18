bool isValid(int mx,vector<int>pageArr,int students){
int temp_stu=1;
    int sum=0;
    for(auto it: pageArr){
        sum+=it;
        if(sum>mx){
            temp_stu++;
            sum=it;
        }
        if(temp_stu>students){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    int Allocate(vector<int>& pageArr, int students) {
        int l=INT_MIN;
        int r=0;
        //taking the maximum value and the total sum of the array//
        for(auto it: pageArr){
            l=max(l,it);
            r+=it;
        }
        int res=0;
        // Our range starts
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(mid,pageArr,students)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
        
    }
};
