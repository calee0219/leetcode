class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for (int idx = 0; idx < k; ++idx) {
            while (!dq.empty() && nums[dq.back()] < nums[idx])
                dq.pop_back();
            dq.push_back(idx);
        }
        for (int idx = k; idx < nums.size(); ++idx) {
            ans.push_back(nums[dq.front()]);
            if (!dq.empty() && dq.front() <= idx-k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[idx])
                dq.pop_back();
            dq.push_back(idx);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};