class Solution {
public:
    int m,n;
    int solve(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &vis){
        if(i<0 || j<0 || i==m || j==n || grid[i][j]==0 || vis[i][j]){
            return 0;
        }
        vis[i][j]=1;
        int a=solve(grid,i+1,j,vis);
        int b=solve(grid,i-1,j,vis);
        int c=solve(grid,i,j-1,vis);
        int d=solve(grid,i,j+1,vis);
        vis[i][j]=0;
        return grid[i][j]+max({a,b,c,d});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    int x=solve(grid,i,j,vis);
                    ans=max(ans,x);
                }
            }
        }
        return ans;
    }
};