class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(string &s,string &r,int i,int j){
        if(i==n || j==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0;
        if(s[i]==r[j]){
            a=1+solve(s,r,i+1,j+1);
        }
        int b=solve(s,r,i+1,j);
        int c=solve(s,r,i,j+1);
        return dp[i][j]=max({a,b,c});
    }
    int longestPalindromeSubseq(string s) {
        n=s.size();
        dp.resize(n,vector<int>(n,-1));
        string r=s;
        reverse(r.begin(),r.end());
        return solve(s,r,0,0);
    }
};