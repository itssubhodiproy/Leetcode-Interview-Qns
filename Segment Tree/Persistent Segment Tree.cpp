// 732. My Calendar III
// segment tree (with lazy propagation) without using array/ extra space //

class Node{
public:
    Node* left,* right;  // pointers to left and right of our segment tree node
    int val, lazy; // val equals the maximum value for the range considered under this node, lazy contains the value that's to be used for lazy propogation
	
    Node(): left(NULL), right(NULL), val(0), lazy(0) {}
    
    void extend() { // used to create the left and right nodes of this node if they don't exist
        if(left==NULL) { // Note that since both the nodes are created together checking only the left or the right's creation ensures wether both of them have been created or not
            left=new Node();
            right=new Node();
        }
    }
};
class Segtree {
public:
    Node* root;
    int n;
    
    Segtree(int n): n(n) {
        root = new Node();
    }
    
    void up(int l,int r, int val) {
        update(root,1,n,l,r,val);
    }
    
    int get(int l,int r) {
        return query(root,1,n,l,r);
    }
    
    void update(Node* p,int s,int e,int l,int r,int val) {
        if(p->lazy) {
            p->val+=p->lazy;
            if(s!=e) { 
                p->extend();
                p->left->lazy+=p->lazy;
                p->right->lazy+=p->lazy;
            }
            p->lazy=0;
        }
        
        if(s>r || e<l) return;
        
        if(s>=l && e<=r) {
            p->val+=val;
            if(s!=e) {
                p->extend();
                p->left->lazy+=val;
                p->right->lazy+=val;
            }
            return;
        }
        
        int m=(s+e)/2;
        p->extend();
        update(p->left,s,m,l,r,val);
        update(p->right,m+1,e,l,r,val);
        p->val=max(p->left->val, p->right->val);
    }
    
    int query(Node* p,int s,int e,int l, int r) {
         if(p->lazy) {
            p->val+=p->lazy;
            if(s!=e) { 
                p->extend();
                p->left->lazy+=p->lazy;
                p->right->lazy+=p->lazy;
            }
            p->lazy=0;
        }
        
        if(s>r || e < l) {
			return 0;
		}
        
        if(s>=l && e<=r) {
            return p->val;
        }
        
        int m=(s+e)/2;
        p->extend();
        return max(query(p->left,s,m,l,r),query(p->right,m+1,e,l,r));
    }
};

class MyCalendarThree {
public:
    int n;
    Segtree* sg;
    MyCalendarThree() {
        n=1e9;
        sg=new Segtree(n);
    }
    
    int book(int start, int end) {
        sg->up(start,end-1,1);
        return sg->get(1,n);
    }
};
