class Solution {
public:
    int n;
    int equalSubstring(string a, string b, int k) {
        n=a.size();
        if(k==n){
            return n;
        }
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                temp[i]=a[i]-b[i];
            }
            else{
                temp[i]=b[i]-a[i];
            }
        }
        int ans=0;
        int i=0,j=0;
        int count=0;
        while(j<n){
            if(temp[j]>0){
                count+=temp[j];
            }
            if(count<=k){
                ans=max(ans,j-i+1);
            }
            else{
                while(count>k){
                    if(temp[i]>0){
                        count-=temp[i];
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};