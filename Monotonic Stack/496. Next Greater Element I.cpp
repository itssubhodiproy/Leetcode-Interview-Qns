class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& v) {
        vector<int> ans;int n=v.size();
        stack<int>st;map<int,int>m;
        for(int i=n-1;i>=0;--i){
            if(st.empty()){ans.push_back(-1);st.push(v[i]);}
            //two cases
            else if(st.top()>v[i]){
                ans.push_back(st.top());
                st.push(v[i]);
            }
            else{
                while(!st.empty()&& st.top()<v[i])
                    st.pop();
                if(st.empty()){ans.push_back(-1);st.push(v[i]);}
                else{ans.push_back(st.top());st.push(v[i]);}
            }
            m[v[i]]=i;
        }
        reverse(ans.begin(),ans.end());
        v.clear();
        for(auto it: nums1)
            v.push_back(ans[m[it]]);
        return v;
    }
};
