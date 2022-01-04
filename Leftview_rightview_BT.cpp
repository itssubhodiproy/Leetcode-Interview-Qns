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

void dfs(TreeNode* root, int level, map<int,int> &m){
    if(!root) return;
    
    if(m[level]==0) m[level]=root->val;
    
    
    //Just change the order here whether you need leftside view or rightside view//
    dfs(root->right,level+1,m);
    dfs(root->left,level+1,m);
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        map<int,int> m;
        dfs(root,1,m); // where 1 is our step and map will store values for each step //
        for(auto it: m){
            v.push_back(it.second);
        }
        // returning a vector//
        return v;
    }
};
