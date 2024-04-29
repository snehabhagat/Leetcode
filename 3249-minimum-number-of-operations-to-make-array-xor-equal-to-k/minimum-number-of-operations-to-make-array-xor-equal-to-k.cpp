class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int var=0;
        for(auto it:nums){
            var=var^it;
        }
        int ans=0;
        for(int i=0;i<32;i++){
            int a=(var>>i)%2;
            int b=(k>>i)%2;
            //cout<<a<<b<<endl;
            if(a!=b){
                ans++;
            }
        }
        return ans;
    }
};