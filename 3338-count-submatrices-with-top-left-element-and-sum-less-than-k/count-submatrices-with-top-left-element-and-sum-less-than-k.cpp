class Solution {
public:
    int n,m;
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0){
                    grid[i][j]+=grid[i-1][j];
                }
                if(j>0){
                    grid[i][j]+=grid[i][j-1];
                }
                if(i>0 && j>0){
                    grid[i][j]-=grid[i-1][j-1];
                }
                if(grid[i][j]<=k){
                    ans++;
                }
            }
        }
        return ans;
    }
};