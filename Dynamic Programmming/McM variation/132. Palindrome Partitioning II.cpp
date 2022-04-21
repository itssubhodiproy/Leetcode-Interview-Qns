  bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }

int pal(string s, int i,int j, vector<vector<int>> &v){
    
    // base case
    if( i==j || isPalindrome(s,i,j) ) return 0;
    
    if(v[i][j]!=-1) return v[i][j];
    
    int ans=1e9;
    
    for(int k=i;k<j;++k){ 
        // check left once in our matrix
        int left,right;
        if(v[i][k]!=-1){
            left=v[i][k];
        }
        if(v[i][k]==-1){
             left=pal(s, i, k, v);
        }
        // check right once in our matrix
        if(v[k+1][j]!=-1){
            right=v[k+1][j];
        }
        if(v[k+1][j]==-1){
             right=pal(s, k+1, j, v);
        } 
        
        int temp = left + right + 1;
        ans = min (ans, temp);    
    }
    return v[i][j]=ans;
}


class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<vector<int>> v( n+1 , vector<int> (n+1, -1));
        return pal(s,0,n-1,v);
    }
};
