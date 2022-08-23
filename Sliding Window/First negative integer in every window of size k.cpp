vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {         
    long long i=0,j=0;queue<long long>q;vector<long long>ans;
    while(j<N){
        if(A[j]<0) q.push(A[j]);
        if(K==j-i+1){
            if(!q.empty()) ans.push_back(q.front());
            if(q.empty()) ans.push_back(0);
            if(q.front()==A[i]) q.pop();
            i++;
        }
        j++;
    }
    return ans;                                              
 }
