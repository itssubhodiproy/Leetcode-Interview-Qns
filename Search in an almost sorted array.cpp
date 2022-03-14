int binarySearch(int arr[], int l, int r, int x)
{
while(l<=r){
  int m=(l+r)/2;
  // main case
  if(arr[m]==x){
    return m;
  }
  if(arr[m]<x){
    if(arr[m-1]==x){
    return m-1;
    }
    l=m+1;
  }
  else if(arr[m]>x){
    if(arr[m+1]==x){
    return m+1;
    }
    r=m;
  } 
}
// We reach here when element is not present in array
return -1;
}
