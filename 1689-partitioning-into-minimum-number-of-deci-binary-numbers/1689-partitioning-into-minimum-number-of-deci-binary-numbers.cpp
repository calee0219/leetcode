class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char ch: n) {
            ans = max(ans, ch-'0');
            if (ans == 9) return ans;
        }
        return ans;
    }
};