long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long i=0,j=0,ans=0,sum=0;
        while(j<N){
            sum+=Arr[j];
            if(j-i+1==K){
              ans=max(ans,sum);
              sum-=Arr[i];
              i++;
            }
            j++;
        }
        return ans;
    }
