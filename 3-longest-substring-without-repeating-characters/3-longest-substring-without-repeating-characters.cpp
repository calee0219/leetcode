class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int r = 0;
        int ans = 0;
        for (int l = 0; l < s.size(); ++l) {
            while (us.find(s[l]) != us.end()) {
                us.erase(s[r++]);
            }
            us.insert(s[l]);
            ans = max(ans, (int)us.size());
        }
        return ans;
    }
};