class Solution {
public:
    unordered_map<string,int> mp;
    int n;
    vector<int> dp;
    bool solve(string &s,int idx){
        if(idx>=n){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        string temp="";
        for(int i=idx;i<n;i++){
            temp+=s[i];
            if(mp.count(temp) && solve(s,i+1)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict){
            mp[it]++;
        }
        n=s.size();
        dp.resize(n+1,-1);
        return solve(s,0);
    }
};