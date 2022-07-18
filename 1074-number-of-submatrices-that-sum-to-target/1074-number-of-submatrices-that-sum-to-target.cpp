class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int X = matrix.size();
        int Y = matrix[0].size();
        // create prefix
        vector<vector<int>> prefix (X, vector<int>(Y+1, 0));
        for (int x = 0; x < X; ++x) {
            for (int y = 1; y <= Y; ++y) {
                // cout << x << " " << y << endl;
                prefix[x][y] = prefix[x][y-1] + matrix[x][y-1];
            }
        }
        // for (int x = 0; x < X; ++x) {
        //     for (int y = 0; y <= Y; ++y) {
        //         cout << prefix[x][y] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = 0;
        for (int y1 = 1; y1 <= Y; ++y1) {
            for (int y2 = 0; y2 < y1; ++y2) {
                unordered_map<int,int> um; // sum, count
                um.insert({0, 1});
                int pre = 0;
                for (int x = 0; x < X; ++x) {
                    pre += prefix[x][y1] - prefix[x][y2];
                    // cout << pre << endl;
                    if (um.find(pre - target) != um.end()) {
                        // cout << " " << um[pre - target] << endl;
                        ans += um[pre - target];
                    }
                    if (um.find(pre) == um.end())
                        um.insert({pre, 1});
                    else
                        um[pre]++;
                }
            }
        }
        return ans;
    }
};