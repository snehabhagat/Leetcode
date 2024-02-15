class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> sum(n);
        for(int i=0;i<n;i++){
            if(i==0){
                sum[i]=nums[i];
            }
            else{
                sum[i]=sum[i-1]+nums[i];
            }
        }
        long long ans=0;
        for(int i=2;i<n;i++){
            if(sum[i-1]>nums[i]){
                ans=max(ans,sum[i]);
            }
        }
        if(ans==0){
            return -1;
        }
        return ans;
    }
};