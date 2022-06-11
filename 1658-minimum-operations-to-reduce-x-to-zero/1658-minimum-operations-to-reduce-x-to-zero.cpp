class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0, r = n-1;
        int sum = 0;
        int ans = INT_MAX;
        while (sum < x && l < n) {
            sum += nums[l++];
            if (sum == x) ans = min(ans, l);
        }
        if (l == n && sum < x) return -1;
        if (l == n && sum == x) return n;
        while (r >= 0) {
            sum += nums[r];
            while (l > 0 && sum > x) {
                sum -= nums[--l];
            }
            if (sum == x)
                ans = min(ans, n - (r-l));
            r--;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};