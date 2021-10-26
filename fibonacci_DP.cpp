#include<bits/stdc++.h>
using namespace std;

int fib(int n,int arr[]){
    int result=0;
    if (arr[n]!=-1)
    {
        return arr[n];
    } 
    if (n==1 || n==2)
    {
        result= 1;
    }
    else{
    result=fib(n-1,arr)+fib(n-2,arr);
    }
    arr[n]=result;
    return arr[n];
}
int main(){
int n;cin>>n;
int arr[n+1];
for (int i = 0; i < n+1; i++)
{
    arr[i]=-1;
}

cout<<fib(n,arr)<<endl;
    return 0;
}