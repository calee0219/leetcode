struct TrieNode {
    vector<int> onPath;
    TrieNode * next[26] = {};
};

class WordFilter {
    TrieNode * prefixHead;
    TrieNode * suffixHead;
public:
    WordFilter(vector<string>& words) {
        unordered_set<string> us;
        prefixHead = new TrieNode;
        suffixHead = new TrieNode;
        for (int idx = words.size()-1; idx >= 0; --idx) {
            if (us.find(words[idx]) != us.end()) continue;
            us.insert(words[idx]);
            // build prefix trie
            TrieNode * prefixCurr = prefixHead;
            prefixCurr->onPath.push_back(idx);
            for (int ch_idx = 0; ch_idx < words[idx].size(); ++ch_idx) {
                char ch = words[idx][ch_idx] - 'a';
                if (prefixCurr->next[ch] == NULL)
                    prefixCurr->next[ch] = new TrieNode;
                prefixCurr = prefixCurr->next[ch];
                prefixCurr->onPath.push_back(idx);
            }
            // build suffix trie
            TrieNode * suffixCurr = suffixHead;
            suffixCurr->onPath.push_back(idx);
            for (int ch_idx = words[idx].size()-1; ch_idx >= 0; --ch_idx) {
                char ch = words[idx][ch_idx] - 'a';
                if (suffixCurr->next[ch] == NULL)
                    suffixCurr->next[ch] = new TrieNode;
                suffixCurr = suffixCurr->next[ch];
                suffixCurr->onPath.push_back(idx);
            }
        }
    }
    
    unordered_map<string,int> cache;
    int f(string prefix, string suffix) {
        string cache_str = prefix + "|" + suffix;
        if (cache.find(cache_str) != cache.end())
            return cache[cache_str];
        // find by prefix
        TrieNode * prefixCurr = prefixHead;
        for (int idx = 0; idx < prefix.size(); ++idx) {
            char ch = prefix[idx] - 'a';
            if (prefixCurr->next[ch] != NULL)
                prefixCurr = prefixCurr->next[ch];
            else {
                cache[cache_str] = -1;
                return -1;
            }
        }
        // find by suffix
        TrieNode * suffixCurr = suffixHead;
        for (int idx = suffix.size()-1; idx >= 0; --idx) {
            char ch = suffix[idx] - 'a';
            if (suffixCurr->next[ch] != NULL)
                suffixCurr = suffixCurr->next[ch];
            else {
                cache[cache_str] = -1;
                return -1;
            }
        }
        // search onPath from back to front
        int pe = 0;
        int se = 0;
        while (pe < prefixCurr->onPath.size() && se < suffixCurr->onPath.size()) {
            if (prefixCurr->onPath[pe] == suffixCurr->onPath[se]) {
                cache[cache_str] = prefixCurr->onPath[pe];
                return prefixCurr->onPath[pe];
            } else if (prefixCurr->onPath[pe] < suffixCurr->onPath[se]) {
                se++;
            } else {
                pe++;
            }
        }
        cache[cache_str] = -1;
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */