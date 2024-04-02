class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,char> mp,dp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end() && dp.find(t[i])==dp.end()){
                mp[s[i]]=t[i];
                dp[t[i]]=s[i];
            }
            else{
                if(mp[s[i]]!=t[i] && dp[t[i]]!=s[i]){
                    //cout<<mp[s[i]]<<" "<<t[i]<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};