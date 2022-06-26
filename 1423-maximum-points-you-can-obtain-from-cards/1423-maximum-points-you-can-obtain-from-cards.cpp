class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cardSz = cardPoints.size();
        int sum = 0;
        for (int idx = cardSz - k; idx < cardSz; ++idx)
            sum += cardPoints[idx];
        int ans = sum;
        for (int idx = 0; idx < k; ++idx) {
            sum += cardPoints[idx];
            sum -= cardPoints[cardSz - k + idx];
            ans = max(ans, sum);
        }
        return ans;
    }
};