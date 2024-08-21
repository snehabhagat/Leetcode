class Solution {
public:
    int dp[101][101][101];
    int solve(int i,int j,int k,vector<int> &boxes){
        if(i>j){
            return 0;
        }
        int I=i,K=k;
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        while(i<j && boxes[i]==boxes[i+1]){
            i++;
            k++;
        }
        int val=(k+1)*(k+1)+solve(i+1,j,0,boxes);
        for(int m=i+1;m<=j;m++){
            if(boxes[m]==boxes[i])
                val=max(val,solve(i+1,m-1,0,boxes)+solve(m,j,k+1,boxes));
        }
        return dp[I][j][K]=val;
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,0,boxes);
    }
};