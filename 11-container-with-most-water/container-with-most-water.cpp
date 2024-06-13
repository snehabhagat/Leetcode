class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=min(height[0],height[n-1])*(n-1);
        if(n==2){
            return ans;
        }
        int left=0,right=n-1;
        while(left<right){
            if(height[right]<=height[left]){
                ans=max(ans,height[right]*(right-left));
                right--;
            }
            else if(height[left]<=height[right]){
                ans=max(ans,height[left]*(right-left));
                left++;
            }
        }
        return ans;
    }
};