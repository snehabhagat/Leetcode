class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n=s.size();
        for(auto it:s){
            bool flag=true;
            if(it>='A' && it<='Z'){
                if(!st.empty() && it-'A'==st.top()-'a'){
                    st.pop();
                    flag=false;
                }
            }
            else{
                if(!st.empty() && it-'a'==st.top()-'A'){
                    st.pop();
                    flag=false;
                }
            }
            if(flag)
            st.push(it);
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;

    }
};