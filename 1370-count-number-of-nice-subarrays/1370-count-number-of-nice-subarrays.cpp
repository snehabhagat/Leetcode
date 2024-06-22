class Solution {
public:
    int atmost(vector<int>& nums,int k){
        int n=nums.size();
        int i=0,j=0;
        int count=0,ans=0;
        while(j<n){
            if(nums[j]%2==1){
                count++;
            }
            while(i<j && count>k){
                if(nums[i]%2==1){
                    count--;
                }
                i++;
            }
            if(count<=k){
                ans+=(j-i+1);
            }
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a=atmost(nums,k);
        int b=atmost(nums,k-1);
        return a-b;
    }
};