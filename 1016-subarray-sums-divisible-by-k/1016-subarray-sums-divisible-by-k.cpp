class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int pre=0;
        int ans=0;
        mp[pre]++;
        for(int i=0;i<n;i++){
            pre=(pre+nums[i]);
            int x=(pre)%k;
            if(x<0){
                x+=k;
            }
            ans+=mp[x];
            mp[x]++;
        }
        return ans;
    }
};

