class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,int> mp,dp;
        for(int i=0;i<n;i++){
            if(mp[s[i]]!=dp[t[i]]){
                return false;
            }
            mp[s[i]]=i+1;
            dp[t[i]]=i+1;
        }
        return true;
    }
};