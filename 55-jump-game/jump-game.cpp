class Solution {
public:
    int n;
    vector<int> dp;
    bool solve(vector<int>&nums,int idx){
        if(idx>=n-1){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        if(nums[idx]==0){
            return false;
        }
        bool a=false,b=false;
        int i=nums[idx];
        while(i>0){
            a=solve(nums,idx+i);
            if(a){
                return dp[idx]=a;
            }
            i--;
            b=a|b;
        }
        return dp[idx]=b;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        return solve(nums,0);
    }
};