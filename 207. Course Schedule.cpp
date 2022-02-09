
bool iscycle(vector<int> adj[],vector<inadj[],vector<int>t> &vis,int node){
    if(vis[node]==1) return true;
    if(vis[node]==2) return false;
    vis[node]=1;
    for(auto it: adj[node]){
       if(iscycle(adj,vis,it)){
           return true;
       }
       }
    vis[node]=2;
    return false;
    }

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        for(auto edge : prerequisites)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        // for dis-connected components
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i)){
                return false;
            }
        }
        return true;
    }
};
