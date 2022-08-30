class Solution {
public:
    int pickToys(vector<int>& f, int k) {
        map<int,int>m;
        int i=0,j=0,n=f.size(),ans=0;
        
        while(j<n){
            m[f[j]]++;
            if(m.size()<=k)
                ans=max(ans,j-i+1);
            else if(m.size()>k){
                while(m.size()>k){
                    m[f[i]]--;
                    if(m[f[i]]==0) m.erase(f[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
