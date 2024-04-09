class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i<=k){
                ans=ans+min(tickets[i],tickets[k]);
            }
            else{
                ans=ans+min(tickets[k]-1,tickets[i]);
            }
        }
        return ans;
    }
};


