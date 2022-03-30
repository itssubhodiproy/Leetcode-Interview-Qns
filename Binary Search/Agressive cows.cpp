bool f(vector<int> stalls,int k, int minDist)
{
    int cows=1;               
    int lastCowPosition=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastCowPosition>=minDist)
        {
            cows++;
            lastCowPosition=stalls[i];
            if(cows>=k) return true;
        }
    }
    return false;
}
class Solution {
public:
    int maxDistance(vector<int>& position, int cow) {
        sort(position.begin(),position.end());
        int l=1;
        int r=position[position.size()-1];
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(f(position,cow,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
