class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> row(m,INT_MAX),column(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i]=min(row[i],matrix[i][j]);
                column[j]=max(column[j],matrix[i][j]);
            }
        }
        sort(row.begin(),row.end());
        sort(column.begin(),column.end());
        int i=0,j=0;
        vector<int> ans;
        while(i<row.size() && j<column.size()){
            if(row[i]==column[j]){
                ans.push_back(row[i]);
                i++;
                j++;
            }
            else if(row[i]>column[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};