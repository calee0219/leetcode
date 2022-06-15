class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool check[100010] = {};
        // 0
        for (int idx = 0; idx < n; ++idx) {
            if (triplets[idx][0] > target[0])
                check[idx] = 1;
        }
        // 1
        
        for (int idx = 0; idx < n; ++idx) {
            if (triplets[idx][1] > target[1])
                check[idx] = 1;
        }
        // 2
        for (int idx = 0; idx < n; ++idx) {
            if (triplets[idx][2] > target[2])
                check[idx] = 1;
        }
        // total
        vector<int> test = {0, 0, 0};
        for (int idx = 0; idx < n; ++idx) {
            if (!check[idx]) {
                test[0] = max(test[0], triplets[idx][0]);
                test[1] = max(test[1], triplets[idx][1]);
                test[2] = max(test[2], triplets[idx][2]);
            }
        }
        if (test[0] == target[0] && test[1] == target[1] && test[2] == target[2])
            return true;
        else
            return false;
    }
};