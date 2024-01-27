class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st;
        st.insert(1);
        int cnt=1;
        while(cnt<n){
            long long frst=*st.begin();
            st.erase(st.begin());
            st.insert(frst*2);
            st.insert(frst*3);
            st.insert(frst*5);
            cnt++;
        }
        int frst=*st.begin();
        return frst;
    }
};