class Twitter {
    vector<pair<int,int>> tweet[501]; // timestamp,tweetId
    unordered_set<int> following[501];
    int time;
public:
    Twitter() {
        time = 0;
        for (int idx = 0; idx < 501; ++idx)
            following[idx].insert(idx);
    }
    
    void postTweet(int userId, int tweetId) {
        this->tweet[userId].push_back({this->time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for (int id: following[userId]) {
            // cout << id << " " << tweet[id].size() << endl;
            for (int idx = tweet[id].size()-1; idx >= 0; --idx) {
                // cout << tweet[id][idx].first << " " << tweet[id][idx].second << endl;
                pq.push({-tweet[id][idx].first, tweet[id][idx].second});
                if (pq.size() > 10) {
                    auto rm = pq.top();
                    pq.pop();
                    if (rm.second == tweet[id][idx].second)
                        break;
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        this->following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        this->following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */