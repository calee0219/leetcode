class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> arr; // position, speed
        for (int idx = 0; idx < n; ++idx) {
            arr.push_back({position[idx], speed[idx]});
        }
        sort(arr.begin(), arr.end());
        stack<pair<int,int>> sk;
        sk.push(arr[0]);
        for (int idx = 1; idx < n; ++idx) {
            while(!sk.empty() && (sk.top().second > arr[idx].second) &&
                  (double)(sk.top().first-arr[idx].first)/(arr[idx].second-sk.top().second)*arr[idx].second+arr[idx].first <= target) {
                sk.pop();
            }
            sk.push(arr[idx]);
            cout << sk.size() << endl;
        }
        return sk.size();
    }
};