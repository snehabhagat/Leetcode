class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        bool flag=false;
        if(n<0){
            flag=true;
        }
        n=abs(n);
        int x=log2(n);
        int y=pow(2,x);
        if(flag){
            if(x%2==0 && y==n){
                return false;
            }
            if(y==n){
                return true;
            }
            return false;
        }
        return y==n;
    }
};