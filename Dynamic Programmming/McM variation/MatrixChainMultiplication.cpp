int Mcm(int arr[],int i,int j,vector<vector<int>>&v){
    if(i==j) return 0;
    if(v[i][j]!=-1) return v[i][j];
    int ans=1e9;
    for(int k=i;k<=j-1;k++){
        int temp=Mcm(arr,i,k,v)+Mcm(arr,k+1,j,v)+(arr[i-1]*arr[k]*arr[j]);
        ans=min(ans,temp);
    }
    return v[i][j]= ans;
}


class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> v( N , vector<int> (N, -1));
       return Mcm(arr,1,N-1,v);
    }
};
