struct TrieNode {
    string str;
    int index;
    int count;
    unordered_map<char,TrieNode*> next;
    TrieNode(): str(""),index(-1),count(0) {}
    TrieNode(string s): str(s),index(-1),count(0) {}
};

class Solution {
    void dfs(TrieNode * node, string pass, vector<string> & ret) {
        if (node->next.size() == 0) {
            // cout << pass << " " << node->str << endl;
            if (node->str.size() - pass.size() > 2) {
                // cout << pass << (node->str.size() - pass.size() - 1) << node->str[node->str.size()-1] << endl;
                ret[node->index] = pass + to_string(node->str.size() - pass.size() - 1) + node->str[node->str.size()-1];
            } else {
                // cout << node->str << endl;
                ret[node->index] = node->str;
            }
            return;
        }
        if (pass == "" && node->count == 1)
            pass = node->str;
        for (auto & it: node->next) {
            dfs(it.second, pass, ret);
        }
    }
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        int words_size = words.size();
        unordered_map<int, TrieNode *> trieForest[26];
        // build trie
        for (int idx = 0; idx < words_size; ++idx) {
            if (trieForest[words[idx][words[idx].size()-1]-'a'].find(words[idx].size()) == trieForest[words[idx][words[idx].size()-1]-'a'].end()) {
                trieForest[words[idx][words[idx].size()-1]-'a'].insert({words[idx].size(), new TrieNode});
            }
            TrieNode * curr = trieForest[words[idx][words[idx].size()-1]-'a'][words[idx].size()];
            string tmp = "";
            for (char ch: words[idx]) {
                tmp += ch;
                if (curr->next.find(ch) == curr->next.end())
                    curr->next.insert({ch, new TrieNode(tmp)});
                curr = curr->next[ch];
                curr->count += 1;
            }
            curr->index = idx;
        }
        // iterate trie
        vector<string> ret (words_size, "");
        for (char ch = 0; ch < 26; ++ch)
            for (auto & head: trieForest[ch])
                dfs(head.second, "", ret);
        return ret;
    }
};