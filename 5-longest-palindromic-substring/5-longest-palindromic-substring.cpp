class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (size_t pivot = 0; pivot < s.length(); ++pivot) {
            // xxppxx
            for (size_t idx = 0; idx <= pivot && pivot + 1 + idx < s.length(); ++idx) {
                if (s[pivot - idx] == s[pivot + 1 + idx]) {
                    if (2 * (idx+1) > ans.length()) {
                        ans = s.substr(pivot-idx, 2 * (idx+1));
                    }
                } else { break; }
            }
            // xxpxx
            for (size_t idx = 0; idx <= pivot && idx + pivot < s.length(); ++idx) {
                if (s[pivot - idx] == s[pivot + idx]) {
                    if (1 + idx * 2 > ans.length()) {
                        ans = s.substr(pivot-idx, 2 * idx + 1);
                    }
                } else { break; }
            }
        }
        return ans;
    }
};