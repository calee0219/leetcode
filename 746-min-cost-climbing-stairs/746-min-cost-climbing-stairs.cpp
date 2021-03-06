class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1) return 0;
        int cosz = cost.size();
        int a[2] = {cost[0], cost[1]};
        for (int idx = 2; idx < cosz; ++idx) {
            a[idx&1] = min(a[0], a[1]) + cost[idx];
        }
        return min(a[0], a[1]);
    }
};