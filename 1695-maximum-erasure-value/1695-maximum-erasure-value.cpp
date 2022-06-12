class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int last[10001] = {};
        int sum = 0, last_sum = 0;
        for (int idx = 0; idx < nums.size(); ++idx) {
            sum += nums[idx];
            last_sum = max(last_sum, last[nums[idx]]);
            ans = max(ans, sum - last_sum);
            last[nums[idx]] = sum;
        }
        return ans;
    }
};