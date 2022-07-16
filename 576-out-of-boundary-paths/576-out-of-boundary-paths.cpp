#define MOD 1000000007

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long int dp[51][51] = {};
        for (int move = 0; move < maxMove; ++move) {
            long long int tmp_dp[51][51];
            memcpy(tmp_dp, dp, sizeof(dp));
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    dp[x][y] = 0;
                    if (x == 0)   dp[x][y]++;
                    if (y == 0)   dp[x][y]++;
                    if (x == m-1) dp[x][y]++;
                    if (y == n-1) dp[x][y]++;
                    if (x > 0) dp[x][y] += tmp_dp[x-1][y];
                    if (x < m-1) dp[x][y] += tmp_dp[x+1][y];
                    if (y > 0) dp[x][y] += tmp_dp[x][y-1];
                    if (y < n-1) dp[x][y] += tmp_dp[x][y+1];
                    dp[x][y] %= MOD;
                }
            }
        }
        return dp[startRow][startColumn];
    }
};