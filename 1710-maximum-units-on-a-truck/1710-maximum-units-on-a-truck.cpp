class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){ return a[1] > b[1]; });
        int ans = 0;
        for (auto & v: boxTypes) {
            if (truckSize < v[0]) {
                ans += truckSize * v[1];
                break;
            }
            ans += v[0] * v[1];
            truckSize -= v[0];
        }
        return ans;
    }
};