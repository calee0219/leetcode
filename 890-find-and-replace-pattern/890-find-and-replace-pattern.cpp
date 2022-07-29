class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int pl = pattern.size();
        vector<string> ans;
        for (auto & word : words) {
            unordered_map<char,char> mp;
            unsigned int used = 0;
            bool err = false;
            for (int idx = 0; idx < pl; ++idx) {
                if (mp.find(word[idx]) == mp.end() && !(used & (1 << (pattern[idx] & 0x1f)))) {
                    // cout << idx << " " << word[idx] << " " << (1 << (pattern[idx] & 0x1f)) << " " << used << endl;
                    used |= (1 << (pattern[idx] & 0x1f));
                    mp.insert({word[idx], pattern[idx]});
                } else if (mp[word[idx]] != pattern[idx]) {
                    err = true;
                    break;
                }
            }
            if (err) continue;
            ans.push_back(word);
        }
        return ans;
    }
};