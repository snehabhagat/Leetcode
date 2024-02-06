class Solution {
public:
    int n;
    vector<int> dp;
    int solve(vector<int>&days,vector<int>&costs,int idx){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int a=costs[0]+solve(days,costs,idx+1);
        int b=costs[1];
        int x=days[idx],i=0;
        while(idx+i<n && days[idx+i]<x+7){
            i++;
        }
        b+=solve(days,costs,idx+i);
        int c=costs[2];
        int y=days[idx],j=0;
        while(idx+j<n && days[idx+j]<y+30){
            j++;
        }
        c+=solve(days,costs,idx+j);
        return dp[idx]=min({a,b,c});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        dp.resize(n,-1);
        return solve(days,costs,0);
    }
};