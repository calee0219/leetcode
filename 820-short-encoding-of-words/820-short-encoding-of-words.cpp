struct TrieNode {
    int length;
    unordered_map<char, TrieNode*> next;
    TrieNode(): length(0) {}
};

class Solution {
    TrieNode * head;
public:
    int minimumLengthEncoding(vector<string>& words) {
        head = new TrieNode;
        int ans = 0;
        for (auto & word: words) {
            TrieNode * curr = head;
            for (int idx = word.size()-1; idx >= 0; --idx) {
                char ch = word[idx];
                if (curr->next.find(ch) == curr->next.end())
                    curr->next.insert({ch, new TrieNode});
                curr = curr->next[ch];
                if (curr->length) {
                    ans -= curr->length;
                    curr->length = 0;
                    // cout << ans << endl;
                }
            }
            if (curr->next.size() == 0) {
                curr->length = word.size() + 1;
                ans += curr->length;
                // cout << ans << endl;
            }
        }
        return ans;
    }
};