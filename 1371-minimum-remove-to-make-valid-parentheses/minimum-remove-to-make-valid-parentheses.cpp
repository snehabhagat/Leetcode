class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_map<int,int> remove;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(st.empty()){
                    remove[i]++;
                }
                else{
                    if(s[st.top()]=='('){
                        st.pop();
                    }
                    else{
                        remove[i]++;
                    }
                }
            }
            else{
                if(s[i]=='('){
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            remove[st.top()]++;
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                if(remove.count(i)==0){
                    ans+=s[i];
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};