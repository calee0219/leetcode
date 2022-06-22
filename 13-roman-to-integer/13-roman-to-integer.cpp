class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> um ({{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}});
        int ans = 0;
        for (int idx = 0; idx < s.size(); ++idx) {
            if (idx+1 < s.size() && um[s[idx]] < um[s[idx+1]])
                ans -= um[s[idx]];
            else
                ans += um[s[idx]];
        }
        return ans;
    }
};