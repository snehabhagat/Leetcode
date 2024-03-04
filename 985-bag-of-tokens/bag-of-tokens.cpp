class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1;
        int score=0,ans=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
                ans=max(ans,score);
            }
            else{
                if(score>=1){
                    score--;
                    power+=tokens[j];
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};