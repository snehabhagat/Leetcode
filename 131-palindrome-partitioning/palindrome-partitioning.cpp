class Solution {
public:
    int n;
    bool isPalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> ans;
    void solve(string s,vector<string> &t){
        if(s.size()==0){
            ans.push_back(t);
            return;
        }
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i+1);
            string rem=s.substr(i+1);
            if(isPalindrome(left)){
                t.push_back(left);
                solve(rem,t);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<string> t;
        solve(s,t);
        return ans;
    }
};