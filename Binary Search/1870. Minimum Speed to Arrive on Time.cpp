bool f(const vector<int>& dist, const double hour, int mid)
{
    double time = 0;
    for (int i = 0; i < dist.size() - 1; ++i)
         time += ((dist[i] + mid - 1) / mid);
        
time += ((double)dist.back()) / mid;
    if(time> hour)
        return false;
    return true;
}

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour<=(double)n-1) return -1;
        
        int l=1;
        int r=1e7;
        int ans=0;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(f(dist,hour,mid)){
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
