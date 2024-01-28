class Solution {
public:
    int n;
    vector<int> dp;
    int solve(vector<int>& nums,int idx){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=0,not_take=0;
        take=nums[idx]+solve(nums,idx+2);
        not_take=solve(nums,idx+1);
        return dp[idx]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        return solve(nums,0);
    }
};