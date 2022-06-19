struct TrieNode {
    TrieNode * next[26];
    vector<string> strs;
    TrieNode() { memset(next, 0, sizeof(next)); }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        // Build Trie
        TrieNode * head = new TrieNode;
        for (auto & product: products) {
            TrieNode * curr = head;
            for (auto ch: product) {
                if (curr->next[ch-'a'] == NULL)
                    curr->next[ch-'a'] = new TrieNode;
                curr = curr->next[ch-'a'];
                curr->strs.push_back(product);
            }
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
            vector<string> tmp;
            for (int idx = 0; idx < 3 && idx < curr->strs.size(); ++idx) {
                tmp.push_back(curr->strs[idx]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};