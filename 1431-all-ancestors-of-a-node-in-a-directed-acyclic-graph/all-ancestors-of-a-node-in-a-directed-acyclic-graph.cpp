class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ans(n);
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(auto it:adj[p]){
                ans[it].insert(p);
                for(auto jt:ans[p]){
                    ans[it].insert(jt);
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<vector<int>> a;
        for(auto it:ans){
            vector<int> temp;
            for(auto jt: it){
                temp.push_back(jt);
            }
            a.push_back(temp);
        }
        return a;
    }
};