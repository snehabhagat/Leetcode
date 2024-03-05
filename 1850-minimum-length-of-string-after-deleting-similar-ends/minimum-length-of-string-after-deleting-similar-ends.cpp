class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            char a=s[i];
            char b=s[j];
            if(a!=b){
                return j-i+1;
            }
            else{
                while(i<n && s[i]==a){
                    i++;
                }
                while(j>=0 && s[j]==b){
                    j--;
                }
            }
        }
        return i>j?0:1;
    }
};