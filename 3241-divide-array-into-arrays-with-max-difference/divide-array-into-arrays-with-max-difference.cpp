class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            vector<int> temp;
            int x=nums[i];
            int y=nums[i+2];
            if(y-x>k){
                return {};
            }
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};