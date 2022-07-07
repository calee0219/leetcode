class Solution {
    vector<vector<bool>> mem;
    bool test(string & t, int pt, string & s1, int p1, string & s2, int p2) {
        if (pt == t.size()) return true;
        if (p1 < s1.size() && p2 < s2.size() && mem[p1][p2]) return false;
        if (p1 < s1.size() && s1[p1] == t[pt] && test(t, pt+1, s1, p1+1, s2, p2))
            return true;
        if (p2 < s2.size() && s2[p2] == t[pt] && test(t, pt+1, s1, p1, s2, p2+1))
            return true;
        if(p1 < s1.size() && p2 < s2.size()) mem[p1][p2] = true;
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        mem.resize(s1.size(), vector<bool>(s2.size(), false));
        return test(s3, 0, s1, 0, s2, 0);
    }
};