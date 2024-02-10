class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string& s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
}
    int solve(string& s,int i,int n){
        if(i==n){
            return 0;
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        int count=0;
        for(int k=i;k<n;k++){
            if(isPalindrome(s,i,k)){
                count++;
            }
        }
        return dp[i][n]=count+solve(s,i+1,n);
    }
    int countSubstrings(string s) {
        int n=s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(s,0,n);
    }
};