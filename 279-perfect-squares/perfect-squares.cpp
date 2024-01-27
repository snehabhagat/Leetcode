class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n+1);
        v[1]=1;
        for(int i=2;i<=n;i++){
            int r=i-1;
            int l=1;
            int x=sqrt(i);
            if(x*x==i){
                v[i]=1;
            }
            else{
                int temp=i;
                while(l<=r){
                    temp=min(temp,v[l]+v[r]);
                    l++;
                    r--;
                }
                v[i]=temp;
            }
        }
        return v[n];
    }
};