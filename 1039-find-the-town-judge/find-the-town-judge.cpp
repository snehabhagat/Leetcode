class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> mp(n+1),p(n+1,0);
        for(auto it:trust){
            mp[it[0]]++;
            p[it[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==0 && p[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};