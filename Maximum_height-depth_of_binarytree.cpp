//Finding Maximum Depth/Height of a Binary Tree using Recursion
#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
struct node *left, *right;
node(int val){
data=val;
left=right=NULL;
}
};

int MaxDepth(node* &root){                                  //This is a recursive approach
if (root==NULL)
{
   return 0;
}
int l =MaxDepth(root->left);
int r =MaxDepth(root->right);
return 1 + max(l,r);
}


int main(){
struct node *root= new node(1);                                          
root->left= new node(2);                                            
root->right= new node(3);                                           
root->left->left= new node(4);                                           
root->left->right= new node(5);                                              
root->right->left= new node(6);
root->right->right= new node(7);
cout << MaxDepth(root)<<endl;
return 0;
}