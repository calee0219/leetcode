class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
        //     return -1;
        int n = gas.size();
        vector<int> diff (n, 0);
        int total = 0;
        for (int idx = 0; idx < n; ++idx) {
            diff[idx] = gas[idx] - cost[idx];
            total += diff[idx];
            // cout << diff[idx] << " ";
        }
        if (total < 0) return -1;
        int ans = 0;
        int sum = 0;
        for (int idx = 0; idx < n; ++idx) {
            sum += diff[idx];
            if (sum < 0) {
                ans = idx + 1;
                sum = 0;
            }
        }
        return ans;
    }
};