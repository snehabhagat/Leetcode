class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int mx=0;
                for(int a=i;a<=(i+2);a++){
                    for(int b=j;b<=(j+2);b++){
                        mx=max(mx,grid[a][b]);
                    }
                }
                ans[i][j]=mx;
            }
        }
        return ans;
    }
};