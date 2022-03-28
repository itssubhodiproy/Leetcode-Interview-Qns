// SAME AS THE AGRESSIVE COW..

int f(vector<int> &sweetness,int mid){
    int temp_fri=0;
    int sum=0;
    for(int i=0;i<sweetness.size();i++){
        sum+=sweetness[i];
        if(sum>=mid){
            sum=0;
            temp_fri++;
        }
    }
    return temp_fri;
}

class Solution {
public:
    /**
     * @param sweetness: an integer array
     * @param K: an integer
     * @return:  return the maximum total sweetness of the piece
     */
    int maximizeSweetness(vector<int> &sweetness, int K) {
        // write your code here
        K++;
        int l=*min_element(sweetness.begin(),sweetness.end());
        int r;
        for(auto it: sweetness){
            r+=it;
        }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            //if given substring is same as our given k  
            //then, try to find larger value
            if(f(sweetness,mid)==K){
                ans=mid; 
                l=mid+1;
            }
// if, we've got someone valid, but string is lesser than our K, try to maximize
// the size of the array
            else if(sweetness,mid)>K){
                l=mid+1;
            }
            // if we re not able to make till k, try to make k.. atleast
            else if(f(sweetness,mid)<K){
                r=mid-1;
            } 
        }
        return ans;
    }
};
