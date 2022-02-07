class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        // Whenever I'm hitting Null, It's time to add our node
        if(!root) return new TreeNode(val);
        //If my val is greater than current val, I'm going to right
        if(val>root->val) 
            root->right = insertIntoBST(root->right,val);
            
        //If my val is lesser than current val, I'm going to left
        if(val<root->val) 
            root->left = insertIntoBST(root->left,val);
            
        return root;
    }
};
