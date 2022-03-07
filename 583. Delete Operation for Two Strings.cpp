class Solution {
public:
    
    // Direct application of LCS
    
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int t[n+1][m+1];
        //initilazitaion
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0)
                    t[i][j]=0;
            }
        }
        
        // main code
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(word1[i-1]==word2[j-1])
                    t[i][j]=1+t[i-1][j-1];       
                else
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                
            }
        }
        return (n-t[n][m])+(m-t[n][m]);
    }
};
