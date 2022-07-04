class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        int rsz = ratings.size();
        vector<int> l2r (rsz, 0);
        vector<int> r2l (rsz, 0);
        
        // l2r
        l2r[0] = 1;
        for (int idx = 1; idx < rsz; ++idx) {
            if (ratings[idx] > ratings[idx-1]) l2r[idx] = l2r[idx-1] + 1;
            else l2r[idx] = 1;
        }
        // r2l
        r2l[rsz-1] = 1;
        for (int idx = rsz-2; idx >= 0; --idx) {
            if (ratings[idx] > ratings[idx+1]) r2l[idx] = r2l[idx+1] + 1;
            else r2l[idx] = 1;
        }
        int ans = 0;
        for (int idx = 0; idx < rsz; ++idx)
            ans += max(l2r[idx], r2l[idx]);
        return ans;
    }
};