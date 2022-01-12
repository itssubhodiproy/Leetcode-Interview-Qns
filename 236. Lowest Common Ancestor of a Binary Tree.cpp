
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

                                        // My Own Code

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //If I've found the value or NULL
        if(!root || root==p || root==q){
            return root;
        }
        
        //Recursive calls will go-on and try to find the nodes
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        
        //if We've found the left & Right node, return root;
        if(l && r){
            return root;
        }
        //If left is containing our value
        if(l!=NULL){
            return l;
        }
        //If right is containing our value
        if(r!=NULL){
            return r;
        }
        //if both are null
        return NULL;
    }
};
