struct TrieNode {
    int val;
    vector<TrieNode *> order;
    TrieNode(): val(-1) { order.clear(); }
    TrieNode(int n): val(n) { order.clear(); }
};

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<unordered_set<int>> out (26, unordered_set<int>());
        vector<int> in (26, 0);
        bool visited[26] = {};
        TrieNode * head = new TrieNode;
        // build graph & trie
        for (auto & word: words) {
            TrieNode * curr = head;
            for (int idx = 0; idx < word.size(); ++idx) {
                int now = word[idx] - 'a';
                visited[now] = true;
                
                if (curr->order.empty() || curr->order.back()->val != now) {
                    if (curr->order.size() > 0) {
                        out[curr->order.back()->val].insert(now);
                        in[now] |= (1<<(curr->order.back()->val));
                    }
                    curr->order.push_back(new TrieNode(now));
                }
                curr = curr->order.back();
            }
            if (curr->order.size() > 0)
                return "";
        }
        
        // topo sort
        queue<int> q;
        for (int idx = 0; idx < 26; ++idx) {
            if (in[idx] == 0 && visited[idx])
                q.push(idx);
        }
        string ans = "";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = false;
            ans += (curr + 'a');
            for (auto & idx: out[curr]) {
                in[idx] &= ((1<<26)-1)^(1<<curr);
                if (in[idx] == 0) {
                    q.push(idx);
                }
            }
        }
        // cout << ans;
        for (int idx = 0; idx < 26; ++idx) {
            if (in[idx])
                return "";
        }
        return ans;
    }
};