class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mn=prices[0];
        int ans=0;
        for(int i=1;i<n;i++){
            mn=min(mn,prices[i]);
            ans=max(ans,prices[i]-mn);
        }
        return ans;
    }
};