class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<int,int>> um[26]; // index of words -> index in word
        for (int idx = 0; idx < words.size(); ++idx) {
            um[words[idx][0] - 'a'].push_back({idx, 0});
        }
        int ans = 0;
        for (char ch: s) {
            vector<pair<int,int>> tmp (um[ch-'a']);
            um[ch-'a'].clear();
            for (auto pr: tmp) {
                // cout << pr.first << " " << pr.second << endl;
                if (pr.second == words[pr.first].size()-1)
                    ans++;
                else
                    um[words[pr.first][pr.second+1]-'a'].push_back({pr.first, pr.second+1});
            }
        }
        return ans;
    }
};