class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int add=0;
        for(auto it:nums){
            add+=it;
        }
        return sum-add;
    }
};