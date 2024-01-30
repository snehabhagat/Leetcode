class Solution {
public:
    
    // bool solve(vector<int>&nums,int idx){
    //     if(idx>=n-1){
    //         return true;
    //     }
    //     if(dp[idx]!=-1){
    //         return dp[idx];
    //     }
    //     if(nums[idx]==0){
    //         return false;
    //     }
    //     bool a=false,b=false;
    //     int i=nums[idx];
    //     while(i>0){
    //         a=solve(nums,idx+i);
    //         if(a){
    //             return dp[idx]=a;
    //         }
    //         i--;
    //         b=a|b;
    //     }
    //     return dp[idx]=b;
    // }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[n-1]=1;
        for(int idx=n-1;idx>=0;idx--){
            for(int i=1;i<=nums[idx];i++){
                if(idx+i<n && dp[idx+i]){
                    dp[idx]=true;
                }
            }
        }
        return dp[0];
    }
};