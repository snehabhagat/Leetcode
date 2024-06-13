class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            set<int> st;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        vector<vector<int>> res;
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};