This question is solved using Segment Tree (Range Sum Query Mutable)


class NumArray {
public:
    int n;
    vector<int>seg;
    
    void build(int node, int start, int end, vector<int>nums){
        if(start==end){
            seg[node]=nums[start];
            return;
        }
        int mid = (start+end)/2;
        build(2*node+1, start, mid, nums);
        build(2*node+2, mid+1, end, nums);
        seg[node] = seg[2*node+1]+seg[2*node+2];
    }
    
    int query(int node,int start,int end,int left, int right){
        if(start>right ||left>end) return 0;
        if(start>=left && right>=end) return seg[node];
        int mid = (start+end)/2;
        int leftChild = query(2*node+1,start,mid,left,right);
        int rightChild = query(2*node+2,mid+1,end,left,right);
        return leftChild+rightChild; 
    }
    
    void pointUpdate(int node,int start,int end,int indx,int val){
        if(start>indx ||indx>end) return;
        if(start==end) seg[node]=val;
        int mid = (start+end)/2;
        pointUpdate(2*node+1,start,mid,indx,val);
        pointUpdate(2*node+2,mid+1,end,indx,val);
        seg[node] = seg[2*node+1]+seg[2*node+2];
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(!n) return;
        seg.resize(4*n);
        build(0,0,n-1,nums);
    }
    //single point update
    void update(int index, int val) {
        pointUpdate(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,left,right,0,n-1);
    }
};
