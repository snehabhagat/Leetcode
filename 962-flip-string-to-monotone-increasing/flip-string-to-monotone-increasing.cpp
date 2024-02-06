class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(string &s,int idx,char prev){
        if(idx==n){
            return 0;
        }
        int i;
        if(prev=='0'){
            i=0;
        }
        else{
            i=1;
        }
        if(dp[idx][i]!=-1){
            return dp[idx][i];
        }
        int a=INT_MAX,b=INT_MAX;
        if(s[idx]=='0'){
                if(prev=='1'){// 1 0
                    a=1+solve(s,idx+1,'1');
                    return dp[idx][i]=a;
                }
                else{
                    a=1+solve(s,idx+1,'1');
                    b=solve(s,idx+1,s[idx]);
                    return dp[idx][i]=min(a,b);
                }
        }
        else{
                if(prev=='0'){
                    a=1+solve(s,idx+1,'0');
                    b=solve(s,idx+1,s[idx]);
                    return dp[idx][i]=min(a,b);
                }
                else{
                    a=solve(s,idx+1,s[idx]);
                    return dp[idx][i]=a;
                }
        }
        return n;
    }
    int minFlipsMonoIncr(string s) {
        n=s.size();
        dp.resize(n,vector<int>(2,-1));
        return solve(s,0,'0');
    }
};