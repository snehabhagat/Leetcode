class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    if(i-1<0){
                        ans++;
                    }
                    else if(grid[i-1][j]==0){
                        ans++;
                    }
                    if(j-1<0){
                        ans++;
                    }
                    else if(grid[i][j-1]==0){
                        ans++;
                    }
                    if(i+1==row){
                        ans++;
                    }
                    else if(grid[i+1][j]==0){
                        ans++;
                    }
                    if(j+1==col){
                        ans++;
                    }
                    else if(grid[i][j+1]==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};