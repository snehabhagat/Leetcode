class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(26),pp(26);
        int n=s.size();
        int ans=0;
        for(auto it:s){
            if(it>='a' && it<='z')
                mp[it-'a']++;
            else{
                pp[it-'A']++;
            }
        }
        bool flag=true;
        for(int i=0;i<26;i++){
            if(mp[i]%2==1){
                if(flag){
                    ans+=mp[i];
                    flag=false;
                }
                else{
                    ans+=(mp[i]-1);
                }
            }
            else{
                ans+=mp[i];
            }
        }
        for(int i=0;i<26;i++){
            if(pp[i]%2==1){
                if(flag){
                    ans+=pp[i];
                    flag=false;
                }
                else{
                    ans+=(pp[i]-1);
                }
            }
            else{
                ans+=pp[i];
            }
        }
        return ans;
    }
};