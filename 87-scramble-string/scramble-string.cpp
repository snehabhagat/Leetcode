class Solution {
public:
    unordered_map<string,int> dp;
    bool solve(string s1,string s2){
        if(s1.size()==1){
            return s1==s2;
        }
        string key=s1+" "+s2;
        if(dp.count(key)){
            return dp[key];
        }
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i),s2.substr(i))){
                return dp[key]=true;
            }
            if(solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i),s2.substr(0,n-i))){
                return dp[key]=true;
            }
        }
        return dp[key]=false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};