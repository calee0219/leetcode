class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<int> sk;
        int prev_max = 0;
        int ans = 0;
        for (int idx = nums.size()-1; idx >= 0; --idx) {
            // int popCnt = 0;
            prev_max = max(prev_max, (int)sk.size());
            while (!sk.empty() && (sk.top() < nums[idx])) {
                // popCnt += 1;
                sk.pop();
            }
            // ans = max(ans, popCnt);
            if (prev_max > sk.size())
                ans = max(ans, (int)(prev_max - sk.size()));
            sk.push(nums[idx]);
            
            // cout << popCnt << " " << sk.top() << endl;
        }
        return ans;
    }
};