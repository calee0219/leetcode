class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> sk;
        vector<int> ans (temperatures.size(), 0);
        for (int idx = temperatures.size()-1; idx >= 0; --idx) {
            while (!sk.empty() && temperatures[sk.top()] <= temperatures[idx]) {
                sk.pop();
            }
            if (!sk.empty())
                ans[idx] = sk.top()-idx;
            sk.push(idx);
        }
        return ans;
    }
};