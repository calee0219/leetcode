class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        int dp[501][501] = {0};
        for (int w1 = 1; w1 <= l1; ++w1) {
            for (int w2 = 1; w2 <= l2; ++w2) {
                dp[w1][w2] = max((word1[w1-1] == word2[w2-1]) + dp[w1-1][w2-1],
                             max(dp[w1-1][w2], dp[w1][w2-1]));
            }
        }
        return l1 + l2 - dp[l1][l2]*2;
    }
};