class Solution {
public:
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
        int count=0;
        for(int k=i;k<n;k++){
            if(isPalindrome(s,i,k)){
                count++;
            }
        }
        return count+solve(s,i+1,n);
    }
    int countSubstrings(string s) {
        int n=s.size();
        return solve(s,0,n);
    }
};