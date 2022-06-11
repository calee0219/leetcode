class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // go from left
        int n = nums.size();
        unordered_map<int, int> um;
        um.insert({0, 0});
        int sum = 0;
        for (int idx = 0; idx < n; ++idx) {
            sum += nums[idx];
            um.insert({sum, idx+1});
        }
        int ans = INT_MAX;
        if (um.find(x) != um.end())
            ans = min(ans, um[x]);
        // cout << ans << endl;
        sum = 0;
        for (int idx = n-1; idx >= 0; --idx) {
            sum += nums[idx];
            if (um.find(x - sum) != um.end() && (um[x-sum] + (n-idx) <= n)) {
                ans = min(ans, um[x-sum] + (n-idx));
                // cout << ans << endl;
            }
        }
        if (ans == INT_MAX) return -1;
        else return ans;
    }
};