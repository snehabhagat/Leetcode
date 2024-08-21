class Solution {
public:
    vector<vector<int>> dp;
    int solve(int s,int e,string& str){
        if(s>e){
            return 0;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int mini=1+solve(s+1,e,str);
        for(int k=s+1;k<=e;k++){
            if(str[s]==str[k]){
                int x=solve(s,k-1,str)+solve(k+1,e,str);
                mini=min(mini,x);
            }
        }
        return dp[s][e]=mini;
    }
    int strangePrinter(string s) {
        string uniqueChars;
        int i = 0;
        while (i < s.length()) {
            char currentChar = s[i];
            uniqueChars += currentChar;
            while (i < s.length() && s[i] == currentChar) {
                i++;
            }
        }
        int n=uniqueChars.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,uniqueChars);
    }
};