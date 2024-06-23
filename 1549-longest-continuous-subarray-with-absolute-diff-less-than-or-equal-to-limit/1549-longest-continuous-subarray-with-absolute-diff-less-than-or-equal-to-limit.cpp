class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int num=nums.size();
        int i=0,j=0;
        int ans=0;
        priority_queue<pair<int,int>> maxheap;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        while(j<num){
            maxheap.push({nums[j],j});
            minheap.push({nums[j],j});
            while(maxheap.top().second <i)
                    maxheap.pop();
            while(minheap.top().second < i)
                    minheap.pop();
            if(maxheap.top().first-minheap.top().first<=limit){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};