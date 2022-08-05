class Solution {
    vector<int> mem;
    int rec(vector<int>& nums, int target) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (mem[target] != -1) return mem[target];
        int ans = 0;
        for (int n: nums) {
            ans += combinationSum4(nums, target-n);
        }
        // cout << target << " ";
        mem[target] = ans;
        return ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        mem.resize(1001, -1);
        // sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
        return rec(nums, target);
    }
};