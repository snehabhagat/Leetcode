class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> lst;
        for(int i=0;i<n;i++){
            lst.push_back({capital[i],profits[i]});
        }
        sort(lst.begin(),lst.end());
        if(w<lst[0].first){
            return 0;
        }
        priority_queue<int> pq;
        int i=0;
        for(int j=0;j<k;j++){
            while(i<n){
                if(w>=lst[i].first){
                    pq.push(lst[i].second);
                    i++;
                }
                else{
                    break;
                }
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
            else{
                break;
            }
        }
        return w;
    }
};