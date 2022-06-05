class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<int> sk;
        int prev_max = 0;
        int ans = 0;
        for (int idx = nums.size()-1; idx >= 0; --idx) {
            prev_max = max(prev_max, (int)sk.size());
            while (!sk.empty() && (sk.top() < nums[idx])) {
                sk.pop();
            }
            ans = max(ans, max(0, prev_max - (int)sk.size()));
            sk.push(nums[idx]);
            
            // cout << popCnt << " " << sk.top() << endl;
        }
        return ans;
    }
};