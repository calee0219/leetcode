class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        memset(pos, -1, sizeof(pos));
        int start = -1;
        int ans = 0;
        for (int end = 0; end < s.size(); ++end) {
            if (pos[s[end]] > start)
                start = pos[s[end]];
            pos[s[end]] = end;
            ans = max(ans, end - start);
        }
        return ans;
    }
};