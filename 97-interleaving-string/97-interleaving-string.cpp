class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        int sz1 = s1.size(), sz2 = s2.size();
        vector<vector<bool>> dp (sz1+1, vector<bool>(sz2+1, false));
        dp[0][0] = true;
        for (int p1 = 0; p1 < sz1; ++p1) {
            dp[p1+1][0] = dp[p1][0] && s1[p1] == s3[p1];
        }
        for (int p2 = 0; p2 < sz2; ++p2) {
            dp[0][p2+1] = dp[0][p2] && s2[p2] == s3[p2];
        }
        for (int p1 = 0; p1 < sz1; ++p1) {
            for (int p2 = 0; p2 < sz2; ++p2) {
                dp[p1+1][p2+1] = (dp[p1][p2+1] && s1[p1] == s3[p1+p2+1])
                              || (dp[p1+1][p2] && s2[p2] == s3[p1+p2+1]);
            }
        }
        // for (int p1 = 0; p1 <= s1.size(); ++p1) {
        //     for (int p2 = 0; p2 <= s2.size(); ++p2) {
        //         cout << dp[p1][p2] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[sz1][sz2];
    }
};