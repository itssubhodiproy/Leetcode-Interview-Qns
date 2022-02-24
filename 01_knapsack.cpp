// Navive Recursive solution
      // Wheather pick one element or skip and move forward to do the same
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       if(W==0||n==0){
           return 0;
       }
//       If we wt[n-1]< W, we have space in our bag, and got a choice to take or skip the element
       if(W>=wt[n-1]){
           return max( (val[n-1]+knapSack(W-wt[n-1],wt,val,n-1)),knapSack(W,wt,val,n-1) );
       }
//       If wt[n-1]>W, skip that element
       return knapSack(W,wt,val,n-1);    
    }
