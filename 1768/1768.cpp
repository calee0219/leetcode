class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx;
        string ret;
        for (idx = 0; idx < max(word1.size(), word2.size()); idx++) {
            if (idx < word1.size()) {
                ret += word1[idx];
            }
            if (idx < word2.size()) {
                ret += word2[idx];
            }
        }
        return ret;
    }
};
