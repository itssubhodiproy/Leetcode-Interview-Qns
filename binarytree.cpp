//Implementation Of Binary Tree in C++;
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

int main(){
struct node *root= new node(1);                                          //          1
root->left= new node(2);                                                //          / \            
root->right= new node(3);                                               //         2   3
root->left->left= new node(4);                                           //       /     \ 
root->left->right= new node(5);                                           //     4       5     
root->right->left= new node(6);
root->right->right= new node(7);
return 0;
}