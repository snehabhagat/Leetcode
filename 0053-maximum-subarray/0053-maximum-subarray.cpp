class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_till=INT_MIN,ans=INT_MIN,sum_till=0;
        for(int i=0;i<n;i++){
            if(sum_till<0){
                sum_till=0;
            }
            sum_till+=nums[i];
            ans=max(ans,sum_till);
        }
        return ans;
    }
};