class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>> pq;
        pq.push({(double)1,start});
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<double> dis(n,0);
        dis[start]=1;
        double ans=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            double d=p.first;
            int node=p.second;
            if(node==end){
                ans=max(ans,d);
            }
            for(auto it:adj[node]){
                if(dis[it.first]<(d*it.second)){
                    dis[it.first]=d*it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        if(ans==0){
            return 0.00000;
        }
        return ans;
    }
};