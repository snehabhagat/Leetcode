class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid1,vector<vector<int>>& grid2,vector<vector<int>>&vis2,int & flag){
        if(i<0 || j<0 || i>=grid1.size() || j>=grid1[0].size() || vis2[i][j]==1 || grid2[i][j]==0){
            return;
        }
        if(grid1[i][j]==0){
            flag=0;
        }
        vis2[i][j]=1;

        dfs(i+1,j,grid1,grid2,vis2,flag);
        dfs(i-1,j,grid1,grid2,vis2,flag);
        dfs(i,j+1,grid1,grid2,vis2,flag);
        dfs(i,j-1,grid1,grid2,vis2,flag);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int count=0;
        int flag=1;
        vector<vector<int>> vis2(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis2[i][j]==0 && grid2[i][j]==1){
                    dfs(i,j,grid1,grid2,vis2,flag);
                    if(flag==1){
                        count++;
                    }
                }
                flag=1;
            }
        }
        return count;
    }
};