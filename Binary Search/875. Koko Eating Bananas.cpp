bool f(vector<int>& piles, long long int mid, long long int h){
    long long int sum=0;
    for(auto it: piles){
        sum+=ceil(it/(double)mid);  
    }
        if(sum>h)
            return false;
    return true;
}


class Solution {
public:
    long long int minEatingSpeed(vector< int>& piles, int h) {
        long long int l=1;
        long long int r=1e9;

        
        long long int ans=0;
        // start bs, and check for the function. if ture, try to reduce, if not try to maximize()
        while(l<=r){
            long long int mid=l+((r-l)/2);
            if(f(piles,mid,h)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
