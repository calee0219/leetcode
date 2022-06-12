struct TrieNode {
    int index;
    unordered_map<char,TrieNode *> next;
    TrieNode(): index(-1) {}
};

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        int count[256] = {};
        int mapping[256][256] = {};
        
        // build trie
        TrieNode * head = new TrieNode;
        for (int idx = 0; idx < n; ++idx) {
            count[ideas[idx][0]] += 1;
            TrieNode * curr = head;
            TrieNode * last = curr;
            for (int jdx = ideas[idx].size()-1; jdx >= 0; --jdx) {
                char ch = ideas[idx][jdx];
                if (curr->next.find(ch) == curr->next.end())
                    curr->next.insert({ch, new TrieNode});
                last = curr;
                curr = curr->next[ch];
            }
            curr->index = idx;
            for (auto it: last->next) {
                if (it.second->index != -1 && it.first != ideas[idx][0]) {
                    // cout << ideas[idx][0]<< " " << it.first << endl;
                    mapping[it.first][ideas[idx][0]] += 1;
                    mapping[ideas[idx][0]][it.first] += 1;
                }
            }
        }
        long long ans = 0;
        for (int i = 'a'; i <= 'z'; ++i) {
            for (int j = i+1; j <= 'z'; ++j) {
                ans += (count[i] - mapping[i][j]) * (count[j] - mapping[j][i]) * 2;
            }
        }
        return ans;
    }
};