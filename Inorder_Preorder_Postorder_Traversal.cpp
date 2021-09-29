//Inorder, Preorder, Postorder Traversal implementation in C++; (Depth First Search)

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


void Inorder(node* &root){                     //Inorder Traversal (Left->Root->Right)
if(root==NULL){
    return;
}
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}


void Preorder (node* &root){                   //Preorder Traversal (Root->Left->Right)
if(root==NULL){
    return;
}
cout<<root->data<<" ";
Preorder(root->left);
Preorder(root->right);
}


void Postorder(node* &root){                   //Postorder Traversal (Left->Right->Root)
if(root==NULL)return;
Postorder(root->left);
Postorder(root->right);
cout<<root->data<<" ";
}




int main(){
struct node *root= new node(1);
root->left= new node(2);
root->right= new node(3);
root->left->left= new node(4);
root->left->right= new node(5);
root->right->left= new node(6);
root->right->right= new node(7);
// Inorder(root);
// Preorder(root);                                
// Postorder(root);
return 0;
}