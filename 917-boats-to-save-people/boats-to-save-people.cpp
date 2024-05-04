class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int ans=0;
        int k=0,j=n-1;
        while(k<j){
            if(people[k]+people[j]<=limit){
                ans++;
                k++;
                j--;
            }
            else{
                j--;
                ans++;
            }
        }
        if(k==j){
            ans++;
        }
        return ans;
    }
};