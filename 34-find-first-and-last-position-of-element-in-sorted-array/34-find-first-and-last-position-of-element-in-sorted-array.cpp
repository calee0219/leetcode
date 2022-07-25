class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int> (2, -1);
        }
        int left = 0, right = nums.size(); // [ ) [0, 1)
        int start_point, end_point;
        while (left < right) {
            int mid = left + (right - left) / 2; // mid = 0 [0, 1)
            // cout << left << " " << mid << " " << right << endl;
            if (nums[mid] < target) {
                // cout << "(1)";
                left = mid+1; // [3, 3)
                // cout << left << " " << mid << " " << right << endl;
            } else {
                // cout << "(2)";
                // nums[mid] >= target
                right = mid; // [0, 0)
            }
        }
        if (left >= nums.size() || nums[left] != target) { return vector<int> (2, -1); }
        start_point = left; // 0
        left = 0; right = nums.size(); // [0, 1)
        while (left < right) {
            int mid = left + (right - left) / 2; // mid=0, [0,1)
            if (nums[mid] <= target) {
                left = mid+1; // [1, 1)
            } else {
                // nums[mid] >= target
                right = mid; // [5,5)
            }
        }
        end_point = left-1; // 0
        vector<int> ans;
        ans.push_back(start_point);
        ans.push_back(end_point);
        return ans; // [0,0]
    }
};