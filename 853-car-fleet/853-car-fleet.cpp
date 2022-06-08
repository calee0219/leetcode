class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> arr; // position, speed
        for (int idx = 0; idx < n; ++idx) {
            arr.push_back({position[idx], speed[idx]});
        }
        sort(arr.begin(), arr.end());
        double time = 0;
        int idx = n-1;
        int ans = 0;
        while (idx >= 0) {
            double t = (double)(target - arr[idx].first) / arr[idx].second;
            if (t > time) {
                time = t;
                ans += 1;
            }
            idx--;
        }
        return ans;
    }
};