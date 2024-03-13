class Solution {
public:
    int pivotInteger(int n) {
        int sum=(n*(n+1))/2;
        int s=0;
        for(int i=1;i<=n;i++){
            s+=i;
            int y=sum-s+i;
            if(s==y){
                return i;
            }
        }
        return -1;
    }
};