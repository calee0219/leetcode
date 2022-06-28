class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool check = false;
        for (int idx = 0; idx < nums.size() - 1; ++idx) {
            if (nums[idx] > nums[idx+1]) {
                if (check) return false;
                if (idx > 0 && nums[idx+1] < nums[idx-1]) {
                    nums[idx+1] = nums[idx];
                }
                check = true;
            }
        }
        return true;
    }
};