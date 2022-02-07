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
int func(TreeNode* root, int &path){
    if(!root) return 0;
        
        int l = max(func(root->left,path),0);
        int r = max(func(root->right,path),0);
        
        path=max(l+r+root->val,path);
        path=max(path,root->val);
        path=max(path,root->val+max(l,r));
        
        return root->val+max(l,r);
}


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int path=INT_MIN;
        int ans=func(root,path);
        
        return path;
    }
};
