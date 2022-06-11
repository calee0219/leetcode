class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<char,unordered_set<char>> um;
        int sbsz = sub.size();
        int ssz = s.size();
        for (auto & m: mappings) {
            um.insert({m[0], unordered_set<char>()});
            um[m[0]].insert(m[1]);
        }
        for (int idx = 0; idx < ssz; ++idx) {
            int jdx = 0;
            for (jdx = 0; jdx < sbsz; ++jdx) {
                if (s[idx+jdx] == sub[jdx]) continue;
                if (um[sub[jdx]].find(s[idx+jdx]) == um[sub[jdx]].end()) break;
            }
            if (jdx == sbsz) return true;
            // cout << idx << " " << jdx << endl;
        }
        return false;
    }
};