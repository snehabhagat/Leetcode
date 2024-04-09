class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            q.push({tickets[i],i});
        }
        int count=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            x--;
            if(x!=0){
                q.push({x,y});
            }
            count++;
            if(y==k && x==0){
                return count;
            }
        }
        return count;
    }
};


