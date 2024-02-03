class Solution {
    #define ll long long
public:
    // x = k+y
    // x = y-k

    // abs (x-y) = k 
  long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MIN; 

        vector<long long> prefixSum(1, 0);

        unordered_map<int, vector<int>> mp;  
        
        for (int i = 0; i < n; i++) {
            prefixSum.push_back(nums[i] + prefixSum[i]);

            ll a = k + nums[i];
            ll b = nums[i] - k;

            if (mp.find(a) != mp.end()) {
               //vector<int>temp = mp[k + nums[i]];
                for(auto idx: mp[a]){
                    long long tem = prefixSum[i+1] - prefixSum[idx];
                    ans = max(ans, tem);
                }
            }
            if (mp.find(b) != mp.end()) {

                 //vector<int>temp = mp[nums[i] - k];
                 for(auto idx: mp[b]){
                    long long tem = prefixSum[i+1] - prefixSum[idx];
                    ans = max(ans, tem);
                 }
            }
            mp[nums[i]].push_back(i);  
        }

        return ans == LLONG_MIN ? 0 : ans;  
  }
};