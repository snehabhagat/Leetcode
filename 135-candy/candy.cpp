class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> smaller_left(n),smaller_right(n);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                smaller_left[i]=smaller_left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                smaller_right[i]=smaller_right[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(max(smaller_left[i],smaller_right[i])+1);
        }
        return ans;
    }
};
     