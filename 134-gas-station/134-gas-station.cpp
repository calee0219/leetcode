class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
        //     return -1;
        // int n = gas.size();
        int total = 0;
        int ans = 0;
        int sum = 0;
        for (int idx = 0; idx < gas.size(); ++idx) {
            sum += gas[idx] - cost[idx];
            if (sum < 0) {
                ans = idx + 1;
                sum = 0;
            }
            total += gas[idx] - cost[idx];
            // cout << diff[idx] << " ";
        }
        if (total < 0) return -1;
        return ans;
    }
};