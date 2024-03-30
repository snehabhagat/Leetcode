class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n=nums.size();
        unordered_map<int,int> mp;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp.size()<=k){
                ans+=(j-i+1);
            }
            else{
                while(mp.size()>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                if(mp.size()<=k){
                    ans+=(j-i+1);
                }
            }
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a=solve(nums,k);
        int b=solve(nums,k-1);
        return a-b;
    }
};