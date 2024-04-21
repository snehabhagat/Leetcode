class Solution {
public:
    bool dfs(vector<vector<int>>& adj,vector<int>& vis,int src,int des){
        if(src==des){
            return true;
        }
        vis[src]=1;
        for(auto it: adj[src]){
            if(!vis[it] && dfs(adj,vis,it,des)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n);
        return dfs(adj,vis,source,destination);
    }
};