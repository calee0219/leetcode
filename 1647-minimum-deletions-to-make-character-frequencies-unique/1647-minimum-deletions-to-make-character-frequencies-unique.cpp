class Solution {
public:
    int minDeletions(string s) {
        vector<int> feq (26, 0);
        for (char ch: s)
            feq[ch-'a'] += 1;
        sort(feq.begin(), feq.end(), [](int a, int b){ return a > b; });
        int ans = 0;
        int curr_max = feq[0];
        for (int n: feq) {
            // cout << n << " ";
            if (n == 0) break;
            if (curr_max == 0) {
                ans += n;
                continue;
            }
            if (n == curr_max) {
                curr_max--;
            } else if (n < curr_max) {
                curr_max = n - 1;
            } else if (n > curr_max) {
                ans += n - curr_max;
                curr_max--;
            }
        }
        return ans;
    }
};