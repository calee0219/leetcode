class Solution {
public:
    int removePalindromeSub(string s) {
        string rs (s);
        reverse(rs.begin(), rs.end());
        if (s.compare(rs)) return 2;
        return 1;
    }
};