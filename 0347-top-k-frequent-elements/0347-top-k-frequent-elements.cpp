class Solution {
public:
    static bool compare(pair<int,int> &a, pair<int,int>& b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(auto it:nums){
            mp[it]++;
        }
        vector<pair<int,int>> temp;
        for(auto it:mp){
            int x=it.first;
            int y=it.second;
            temp.push_back({x,y});
        }
        sort(temp.begin(),temp.end(),compare);
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};