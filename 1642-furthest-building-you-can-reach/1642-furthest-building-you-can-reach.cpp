class Solution {
    vector<int> diff;
    bool check(int bricks, int ladders, int index) {
        cout << index << " ";
        vector<int> tmp;
        for (int idx = 0; idx <= index; ++idx)
            tmp.push_back(diff[idx]);
        sort(tmp.begin(), tmp.end(), [](int a, int b) { return a > b; });
        // for (int idx = 0; idx <= index; ++idx)
        //     cout << tmp[idx] << " ";
        int sum = 0;
        for (int idx = ladders; idx <= index; ++idx) {
            sum += tmp[idx];
        }
        if (sum <= bricks) { /* cout << "T" << endl; */ return true; }
        else { /* cout << "F" << endl; */ return false; }
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        diff.push_back(0);
        for (int idx = 1; idx < heights.size(); ++idx) {
            diff.push_back((heights[idx] > heights[idx-1]) * (heights[idx] - heights[idx-1]));
        }
        int l = 0, r = heights.size();
        while (l < r) {
            int m = l + (r-l) / 2;
            if (check(bricks, ladders, m))
                l = m+1;
            else
                r = m;
        }
        return l-1;
    }
};