class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>&sat,int idx,int time){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][time]!=INT_MIN){
            return dp[idx][time];
        }
        int take=sat[idx]*time+solve(sat,idx+1,time+1);
        int not_take=solve(sat,idx+1,time);
        return dp[idx][time]=max(take,not_take);
    }
    int maxSatisfaction(vector<int>& sat) {
        n=sat.size();
        sort(sat.begin(),sat.end());
        dp.resize(n+1,vector<int>(n+1,INT_MIN));
        return solve(sat,0,1);
    }
};