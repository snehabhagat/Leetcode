class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(s[i]>s[i+1]){
                ans=ans+(s[i]-s[i+1]);
            }
            else{
                ans=ans+(s[i+1]-s[i]);
            }
        }
        return ans;
    }
};