class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<int>& candidates,int idx,vector<int>& temp,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=n){
            return;
        }
        int j=idx;
        while(j<n && candidates[idx]==candidates[j]){
            j++;
        }
        solve(candidates,j,temp,target);
        if(target-candidates[idx]>=0){
            temp.push_back(candidates[idx]);
            solve(candidates,idx+1,temp,target-candidates[idx]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates,0,temp,target);
        vector<vector<int>> result;
        for(auto it: ans){
            result.push_back(it);
        }
        return result;
    }
};