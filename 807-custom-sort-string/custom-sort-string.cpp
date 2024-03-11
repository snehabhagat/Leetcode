class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> mp(26);
        for(int i=0;i<order.size();i++){
            mp[order[i]-'a']=i;
        }
        sort(s.begin(),s.end(),[mp](char a, char b) {
            return mp[a-'a']<mp[b-'a'];
        });
        return s;
    }
};