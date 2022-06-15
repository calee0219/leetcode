class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& target) {
        int n = t.size();
        int test = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (t[idx][0] == target[0] && t[idx][1] <= target[1] && t[idx][2] <= target[2]) {
                test |= 1;
            }
            if (t[idx][0] <= target[0] && t[idx][1] == target[1] && t[idx][2] <= target[2]) {
                test |= 2;
            }
            if (t[idx][0] <= target[0] && t[idx][1] <= target[1] && t[idx][2] == target[2]) {
                test |= 4;
            }
            if (test == 7) return true;;
        }
        return false;
    }
};