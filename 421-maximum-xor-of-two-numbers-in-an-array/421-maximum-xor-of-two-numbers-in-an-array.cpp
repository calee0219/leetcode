struct TrieNode {
    int val;
    TrieNode * next[2];
    TrieNode(): val(0) { memset(next, 0, sizeof(next)); }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // build trie
        TrieNode * head = new TrieNode;
        for (auto & n : nums) {
            TrieNode * curr = head;
            for (int pow = 1<<30; pow > 0; pow >>= 1) {
                bool bit = (n & pow);
                if (curr->next[bit] == NULL)
                    curr->next[bit] = new TrieNode;
                curr = curr->next[bit];
            }
            curr->val = n;
        }
        int ans = 0;
        for (auto & n: nums) {
            TrieNode * curr = head;
            for (int pow = 1<<30; pow > 0; pow >>= 1) {
                bool bit = (n & pow);
                if (curr->next[!bit])
                    curr = curr->next[!bit];
                else if (curr->next[bit])
                    curr = curr->next[bit];
                else {
                    cout << "ERROR!" << endl;
                    return 0;
                }
            }
            // cout << n << " " << curr->val << endl;
            ans = max(ans, (n ^ curr->val));
        }
        return ans;
    }
};