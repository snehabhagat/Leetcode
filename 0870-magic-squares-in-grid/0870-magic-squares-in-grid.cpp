class Solution {
 public:
    int numMagicSquaresInside(vector<vector<int>>& v) {
        int n = v.size() , m=v[0].size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                int r1=v[i][j]+v[i][j+1]+v[i][j+2];
                int r2=v[i+1][j]+v[i+1][j+1]+v[i+1][j+2];
                int r3=v[i+2][j]+v[i+2][j+1]+v[i+2][j+2];
                int c1=v[i][j]+v[i+1][j]+v[i+2][j];
                int c2=v[i][j+1]+v[i+1][j+1]+v[i+2][j+1];
                int c3=v[i][j+2]+v[i+1][j+2]+v[i+2][j+2];
                int d1=v[i][j]+v[i+1][j+1]+v[i+2][j+2];
                int d2=v[i+2][j]+v[i+1][j+1]+v[i][j+2];

                vector<int>a={{v[i][j],v[i][j+1],v[i][j+2],v[i+1][j],v[i+1][j+1],v[i+1][j+2],v[i+2][j],v[i+2][j+1],v[i+2][j+2] }};
                sort(a.begin(),a.end());
                
                int flag=1;
                for(int k=1;k<=9;k++)if(a[k-1]!=k)flag=0;
                if(flag && r1==r2 && r1==r3 && r1==c1 && r1==c2 && r1==c3 && r1==d1 && r1==d2)ans++;
            }
        }
        return ans;
    }
};