class Solution {
public:
    vector<int> dp;

    int solve(vector<vector<int>>&v, int idx, vector<int>&startTime){
        if(idx>=v.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int notTake = solve(v, idx+1, startTime);
        int take = 0;
        int i=lower_bound(startTime.begin(),startTime.end(),v[idx][1])-startTime.begin();
        take+=v[idx][2]+solve(v,i,startTime);
        return dp[idx]= max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        for(int i=0;i<startTime.size(); i++){
            v.push_back({startTime[i], endTime[i],profit[i]});
        }
        sort(startTime.begin(),startTime.end());
        int n = startTime.size();
        dp.resize(n+1,-1);
        sort(v.begin(),v.end());
        return solve(v, 0, startTime);
    }
};