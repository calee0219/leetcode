class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        for (int idx = 0; idx < k; ++idx) {
            ms.insert(nums[idx]);
        }
        vector<int> ans;
        for (int idx = k; idx < nums.size(); ++idx) {
            ans.push_back(*ms.rbegin());
            ms.erase(ms.find(nums[idx-k]));
            ms.insert(nums[idx]);
        }
        ans.push_back(*ms.rbegin());
        return ans;
    }
};