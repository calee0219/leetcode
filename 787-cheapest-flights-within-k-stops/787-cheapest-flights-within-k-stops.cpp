class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>> pq; // price, next, remain
        vector<vector<pair<int,int>>> graph (n, vector<pair<int,int>>()); // next, price
        vector<int> lv (n, -1);
        for (auto & f: flights) {
            graph[f[0]].push_back({f[1], f[2]});
        }
        for (auto & p: graph[src]) {
            pq.push({-p.second, p.first, k});
        }
        // int ans = INT_MAX;
        while(!pq.empty()) {
            int price = -get<0>(pq.top());
            int next = get<1>(pq.top());
            int remain = get<2>(pq.top());
            pq.pop();
            lv[next] = remain;
            if (next == dst)
                return price;
                // ans = min(ans, price);
            if (remain == 0)
                continue;
            for (auto & n: graph[next]) {
                if (remain-1 > lv[n.first])
                    pq.push({-price-n.second, n.first, remain-1});
            }
        }
        // if (ans == INT_MAX) return -1;
        // return ans;
        return -1;
    }
};