struct TrieNode {
    TrieNode * next[26];
    bool cnt;
    TrieNode(): cnt(0) { memset(next, 0, sizeof(next)); }
};

class WordDictionary {
    TrieNode * head;
    bool search(string & word, int index, TrieNode * curr) {
        if (index == word.size()) {
            return curr->cnt;
        }
        if (word[index] == '.') {
            bool ret = false;
            for (int idx = 0; idx < 26; ++idx) {
                if (curr->next[idx] != NULL) {
                    ret |= search(word, index+1, curr->next[idx]);
                }
            }
            return ret;
        }
        if (curr->next[word[index] - 'a'] == NULL)
            return false;
        else
            return search(word, index+1, curr->next[word[index] - 'a']);
    }
public:
    WordDictionary() {
        head = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode * curr = head;
        for (auto & ch: word) {
            if (curr->next[ch-'a'] == NULL) {
                curr->next[ch-'a'] = new TrieNode;
            }
            curr = curr->next[ch-'a'];
        }
        curr->cnt = 1;
    }
    
    bool search(string word) {
        return search(word, 0, head);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */