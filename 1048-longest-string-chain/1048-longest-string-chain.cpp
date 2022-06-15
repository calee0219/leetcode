class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> um;
        int ans = 0;
        sort(words.begin(), words.end(), [](string a, string b) {return a.size() < b.size();});
        for (auto word: words) {
            // if (word.size() == 1) {
            //     um.insert({word, 1});
            //     ans = max(ans, 1);
            //     // cout << 1 << " ";
            //     continue;
            // }
            int find = 0;
            for (int idx = 0; idx < word.size(); ++idx) {
                string sub = word.substr(0,idx) + word.substr(idx+1);
                if (um.find(sub) != um.end())
                    find = max(find, um[sub]);
            }
            um.insert({word, find+1});
            // cout << find+1 << " ";
            ans = max(ans, find+1);
        }
        // cout << endl;
        return ans;
    }
};