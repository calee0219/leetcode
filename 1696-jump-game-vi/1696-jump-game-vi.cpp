class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> mdq;
        vector<int> dp;
        mdq.push_back(nums[0]);
        dp.push_back(nums[0]);
        for (int idx = 1; idx < nums.size(); ++idx) {
            if (idx > k && mdq.front() == dp[idx-k-1])
                mdq.pop_front();
            int tmp = nums[idx] + mdq.front();
            dp.push_back(tmp);
            // cout << tmp << endl;
            while(!mdq.empty() && mdq.back() < tmp)
                mdq.pop_back();
            mdq.push_back(tmp);
            // for (auto n: mdq)
            //     cout << n << " ";
            // cout << endl;
        }
        return dp[dp.size()-1];
    }
};