/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int diameter(TreeNode* root, int &dia){
    if(!root) return 0;
    
    int l=diameter(root->left,dia);
    int r=diameter(root->right,dia);
    //diameter is basically adding left and right height for each node//
    dia=max(dia,l+r);
    
    return 1+ max(l,r);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        int height=diameter(root,dia);
        return dia;
    }

};
