class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int mn=points[0][1];
        int count=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=mn && mn<=points[i][1]){
                continue;
            }
            else{
                mn=points[i][1];
                count++;
            }
        }
        return count;
    }
};