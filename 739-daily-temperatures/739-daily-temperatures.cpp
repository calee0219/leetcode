class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.size() == 0)
            return {};
        int n = temperatures.size();
        vector<int> ans (temperatures.size(), 0);
        for (int idx = n-2; idx >= 0; --idx) {
            int curr = idx + 1;
            bool check = false;
            while (temperatures[curr] <= temperatures[idx]) {
                if (ans[curr] == 0) {
                    check = true;
                    break;
                }
                curr += ans[curr];
            }
            if (check) continue;
            ans[idx] = curr-idx;
        }
        return ans;
    }
};