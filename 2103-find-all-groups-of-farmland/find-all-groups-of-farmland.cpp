class Solution {
public:
    int n,m;
    void dfs(int i,int j,int &r,int &c,vector<vector<int>>& vis,vector<vector<int>>& land){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || land[i][j]==0){
            return;
        }
        vis[i][j]=1;
        if(i>r){
            r=i;
        }
        if(j>c){
            c=j;
        }
        dfs(i+1,j,r,c,vis,land);
        dfs(i-1,j,r,c,vis,land);
        dfs(i,j+1,r,c,vis,land);
        dfs(i,j-1,r,c,vis,land);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && land[i][j]==1){
                    vector<int> temp;
                    int r=i,c=j;
                    dfs(i,j,r,c,vis,land);
                    ans.push_back({i,j,r,c});
                }
            }
        }
        return ans;
    }
};