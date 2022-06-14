class Leaderboard {
    multiset<long long> score_set;
    unordered_map<int,multiset<long long>::iterator> user_map; // uid -> iter
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (user_map.find(playerId) == user_map.end()) {
           user_map.insert({playerId, score_set.insert((long long)score)});
        } else {
          long long tmp = *user_map[playerId];
            cout << tmp << endl;
          score_set.erase(user_map[playerId]);
          user_map[playerId] = score_set.insert(tmp + score);
        }
    }
    
    int top(int K) {
        auto it = score_set.end();
        long long ans = 0;
        while(K--) {
          ans += *--it;
        }
        return ans;
    }
    
    void reset(int playerId) {
        score_set.erase(user_map[playerId]);
        user_map.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */