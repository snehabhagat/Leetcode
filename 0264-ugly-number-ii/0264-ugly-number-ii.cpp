class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> pq;
        pq.insert(1);
        int ans=0,cnt=0;
        while(cnt<n){
            auto p=pq.begin();
            int x=*p;
            pq.erase(p);
            cnt++;
            if(cnt==n){
                ans=x;
            }
            pq.insert(x*1LL*2);
            pq.insert(x*1LL*3);
            pq.insert(x*1LL*5);
        }
        return ans;
    }
};