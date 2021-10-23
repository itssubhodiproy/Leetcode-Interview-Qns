//Level order traversal using Queue Data-structure in C++
#include<bits/stdc++.h>
using namespace std;

struct node{                                 //Instead of using struct, you can use class also (use public, private according to our needs)//
int data;
struct node *left, *right;
node(int val){
data=val;
left=right=NULL;
}
};

void LevelOrder(node* root){
queue <node*> q;
q.push(root);
while (!q.empty())
{
    cout<<q.front()->data<<" ";
    if (q.front()->left!=NULL)
    {
        q.push(q.front()->left);
    }
    if (q.front()->right!=NULL)
    {
        q.push(q.front()->right);
    }
    q.pop();
}



}

int main(){
struct node *root= new node(1);                                    
root->left= new node(2);                                                     
root->right= new node(3);                                        
root->left->left= new node(4);                                        
root->left->right= new node(5);                                           
root->right->left= new node(6);
root->right->right= new node(7);
LevelOrder(root);
return 0;
}
