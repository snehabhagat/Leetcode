class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>&prices,int idx,int buy){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int a=0;
        if(buy==1){
            a=prices[idx]+solve(prices,idx+2,0);
        }
        else{
            a=-prices[idx]+solve(prices,idx+1,1);
        }
        int b=solve(prices,idx+1,buy);
        return dp[idx][buy]=max(a,b);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        return solve(prices,0,0);
    }
};