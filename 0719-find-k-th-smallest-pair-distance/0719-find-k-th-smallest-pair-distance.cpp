class Solution {
public:
    bool isPossible(int mid,vector<int> &nums,int k){
        int count=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]-nums[l]>mid){
                l++;
            }
            count+=(i-l);
        }
        return count>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums[n-1]-nums[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};