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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>st;
    stack<int>s1;
       TreeNode* node=root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                s1.push(node->val);
                node=node->right;
            }
        }
        
        
        while (s1.size()!=1)
        {
            int top=s1.top();s1.pop();
            
             if(top<=s1.top()){
                return false;
            }
    }
    return true;
    }
};

// Easiest solution came across so far
void inorder(TreeNode* root, vector<int> &v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
bool isThisIncreasing(vector<int> v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>=v[i+1]){
            return false;
        }
    }
    return true;
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        if(isThisIncreasing(v)) return true;
        return false;
    }
};
