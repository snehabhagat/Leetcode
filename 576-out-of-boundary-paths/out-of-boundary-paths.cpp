class Solution {
public:
    int dp[51][51][51];
    int mod = 1e9 + 7;
    int solve(int i, int j, int m, int n, int mx, int mv) {
        if (mv > mx) {
            return 0;
        }
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 1;
        }
        if (dp[i][j][mv] != -1) {
            return dp[i][j][mv];
        }
        int a = solve(i - 1, j, m, n, mx, mv + 1) % mod;
        int b = solve(i + 1, j, m, n, mx, mv + 1) % mod;
        int c = solve(i, j - 1, m, n, mx, mv + 1) % mod;
        int d = solve(i, j + 1, m, n, mx, mv + 1) % mod;
        return dp[i][j][mv] = ((a + b) % mod + (c + d) % mod) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // dp.resize(m + 1, vector<int>(n + 1, -1))
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, m, n, maxMove, 0);
    }
};