#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct Treenode
{
    ll data;
    Treenode *left;
    Treenode *right;

    Treenode(ll val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void Bottomview(Treenode* root, ll steps, map<ll,ll> &m){
    if(root==NULL) return ;

    m[steps]=root->data;

    Bottomview(root->left,steps-1,m);
    Bottomview(root->right,steps+1,m);
}

void Topview(Treenode* root, ll steps, map<ll,ll> &m){
    if(root==NULL) return ;

    if(m[steps]==0){   // That's how this will take only 1st occ of every steps
    m[steps]=root->data;
    Topview(root->left,steps-1,m);
    Topview(root->right,steps+1,m);
}

}

int main()
{
    struct Treenode *root = new Treenode(1);
    root->left = new Treenode(2);
    root->right = new Treenode(3);
    root->left->left = new Treenode(4);
    root->left->right = new Treenode(5);
    root->right->left = new Treenode(6);
    root->right->right = new Treenode(7);
    
    map<ll,ll> m;

    // Bottomview(root,0,m);
    Topview(root,0,m);

    for (auto it : m)
    {
        cout << it.second << " ";
    }

    cout << '\n';
    return 0;
}
