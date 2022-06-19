struct TrieNode {
    map<char,TrieNode *> next;
    string str;
    TrieNode(): str("") {  }
};

class Solution {
    bool DFS(TrieNode * curr, vector<string> & tmp) {
        if (tmp.size() == 3) return true;
        if (curr->str != "") tmp.push_back(curr->str);
        for (auto & it: curr->next) {
            if (DFS(it.second, tmp)) {
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
                if (curr->next.find(ch) == curr->next.end())
                    curr->next.insert({ch, new TrieNode});
                curr = curr->next[ch];
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
            if (curr->next.find(ch) == curr->next.end()) {
                isNull = true;
                ans.push_back({});
                continue;
            }
            curr = curr->next[ch];
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