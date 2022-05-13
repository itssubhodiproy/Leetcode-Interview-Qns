A different kind of technique to store level wise nodes;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(!root) return v;
        queue<TreeNode*>q;q.push(root);
        while(!q.empty()){
            int sz=q.size();
            v.push_back(q.front()->val);
            while(sz--){
                if(q.front()->right)
                    q.push(q.front()->right);
                if(q.front()->left)
                    q.push(q.front()->left);
                q.pop();
            }
        }
        return v;
    }
};
