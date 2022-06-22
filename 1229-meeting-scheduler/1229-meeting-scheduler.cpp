class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int,int>> pq;
        for (auto & s: slots1) {
            pq.push({-s[0], -s[1]});
        }
        for (auto & s: slots2) {
            pq.push({-s[0], -s[1]});
        }
        pair<int,int> p1, p2;
        p1 = pq.top(); pq.pop();
        while(!pq.empty()) {
            p2 = pq.top(); pq.pop();
            if (p2.first - duration >= p1.second && p2.first - duration >= p2.second)
                return {-p2.first, -p2.first + duration};
            if (p1.second > p2.second)
                p1 = p2;
        }
        return {};
    }
};