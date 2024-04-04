class Solution {
public:
    int n,m;
    vector<vector<int>> vis;
    bool solve(vector<vector<char>>& board,string &word,int k,int i,int j){
        if(k==word.size()){
            return true;
        }
        if(i<0 || j<0 || i==n || j==m){
            return false;
        }
        if(vis[i][j]){
            return false;
        }
        if(word[k]==board[i][j]){
            vis[i][j]=1;
            bool a=solve(board,word,k+1,i+1,j);
            bool b=solve(board,word,k+1,i,j+1);
            bool c=solve(board,word,k+1,i-1,j);
            bool d=solve(board,word,k+1,i,j-1);
            if(a || b || c || d){
                return true;
            }
            vis[i][j]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        vis.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j] && solve(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};