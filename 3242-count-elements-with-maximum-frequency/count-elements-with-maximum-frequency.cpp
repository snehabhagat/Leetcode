class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int mx=0;
        for(auto it:nums){
            mp[it]++;
            mx=max(mx,mp[it]);
        }
        int count=0;
        for(auto it:mp){
            int a=it.first;
            int b=it.second;
            if(mx==b){
                count+=b;
            }
        }
        return count;
    }
};