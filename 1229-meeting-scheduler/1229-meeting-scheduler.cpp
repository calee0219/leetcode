class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> res;
        
        for(auto& it : slots1) {
            if(it[1] - it[0] >= duration) {
                pq.push({it[0], it[1]});
            }
        }
        
        for(auto& it : slots2) {
            if(it[1] - it[0] >= duration) {
                pq.push({it[0], it[1]});
            }
        }
        
        while(pq.size() > 1) {
            pair<int,int> pre = pq.top();
            pq.pop();
            
            pair<int,int> cur = pq.top();
            
            if(pre.second >= cur.first + duration) {
                res.push_back(cur.first);
                res.push_back(cur.first + duration);
                return res;
            }
        }
        
        return res;
    }
};