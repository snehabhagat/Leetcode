class Solution {
public:
    int merge(vector<int> &nums,int left,int mid,int right){
        int leftsum=INT_MIN,rightsum=INT_MIN;
        int s=0;
        for(int i=mid;i>=left;i--){
            s+=nums[i];
            leftsum=max(leftsum,s);
        }
        s=0;
        for(int i=mid+1;i<=right;i++){
            s+=nums[i];
            rightsum=max(rightsum,s);
        }
        return leftsum+rightsum;
    }
    int solve(vector<int> &nums,int left,int right){
        if(left==right){
            return nums[left];
        }
        int mid=left+(right-left)/2;
        int left_sum=solve(nums,left,mid);
        int right_sum=solve(nums,mid+1,right);
        int sum=merge(nums,left,mid,right);
        return max({sum,left_sum,right_sum});
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n-1);
    }
};