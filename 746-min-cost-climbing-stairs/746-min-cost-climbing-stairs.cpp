class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1) return 0;
        int cosz = cost.size();
        int dp[1010];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int idx = 2; idx < cosz; ++idx) {
            dp[idx] = min(dp[idx-1], dp[idx-2]) + cost[idx];
        }
        return min(dp[cosz-1], dp[cosz-2]);
    }
};