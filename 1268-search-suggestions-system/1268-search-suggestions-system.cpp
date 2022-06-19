struct TrieNode {
    TrieNode * next[26];
    string str;
    TrieNode(): str("") { memset(next, 0, sizeof(next)); }
};

class Solution {
    bool DFS(TrieNode * curr, vector<string> & tmp) {
        if (tmp.size() == 3) return true;
        if (curr->str != "") tmp.push_back(curr->str);
        for (int idx = 0; idx < 26; ++idx) {
            if (curr->next[idx] != NULL && DFS(curr->next[idx], tmp)) {
                return true;
            }
        }
        return false;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // sort(products.begin(), products.end());
        // Build Trie
        TrieNode * head = new TrieNode;
        for (auto & product: products) {
            TrieNode * curr = head;
            for (auto ch: product) {
                if (curr->next[ch-'a'] == NULL)
                    curr->next[ch-'a'] = new TrieNode;
                curr = curr->next[ch-'a'];
            }
            curr->str = product;
        }
        vector<vector<string>> ans;
        TrieNode * curr = head;
        bool isNull = false;
        for (auto ch: searchWord) {
            if (isNull) {
                ans.push_back({});
                continue;
            }
            if (curr->next[ch-'a'] == NULL) {
                isNull = true;
                ans.push_back({});
                continue;
            }
            curr = curr->next[ch-'a'];
            // DFS here
            vector<string> tmp;
            DFS(curr, tmp);
            // for (int idx = 0; idx < 3 && idx < curr->strs.size(); ++idx) {
            //     tmp.push_back(curr->strs[idx]);
            // }
            ans.push_back(tmp);
        }
        return ans;
    }
};