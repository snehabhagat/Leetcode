class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>&sat,int idx,int mul){
        if(idx==n){
            return 0;
        }
        if(dp[idx][mul]!=-1){
            return dp[idx][mul];
        }
        int take=0,not_take=0;
        take=sat[idx]*mul+solve(sat,idx+1,mul+1);
        not_take=solve(sat,idx+1,mul);
        return dp[idx][mul]=max(take,not_take);
    }
    int maxSatisfaction(vector<int>& sat) {
        n=sat.size();
        dp.resize(n,vector<int>(n+1,-1));
        sort(sat.begin(),sat.end());
        return solve(sat,0,1);
    }
};