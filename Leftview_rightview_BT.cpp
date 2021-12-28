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

void leftview(Treenode *root, ll i, vector<ll> &v) // leftview
{
    if (root == NULL)
        return;

    if (v.size() == i)
        v.push_back(root->data);
    
    leftview(root->left, i + 1, v);
    leftview(root->right, i + 1, v);
}

void rightview(Treenode *root, ll i, vector<ll> &v) // rightview
{
    if (root == NULL)
        return;

    if (v.size() == i)
        v.push_back(root->data);
    
    rightview(root->right, i + 1, v);
    rightview(root->left, i + 1, v);
}

ll height(Treenode *root)   //finding binary tree height
{

    if (root == NULL)
    {
        return 0;
    }
    ll l = height(root->left);
    ll r = height(root->right);

    return 1 + max(l, r);
}

int main()
{
    struct Treenode *root = new Treenode(5);
    root->left = new Treenode(2);
    root->right = new Treenode(3);
    root->left->left = new Treenode(4);
    root->left->right = new Treenode(6);
    root->left->right->right = new Treenode(9);
//if we play with the v.size, then we don't need height separately//

    // ll heighttree = height(root);
    // cout << heighttree << "\n";
    // return 0;

    vector<ll> v;

    // Leftview function
    // leftview(root, 0, v);
    rightview(root, 0, v);

    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << '\n';
    return 0;
}
