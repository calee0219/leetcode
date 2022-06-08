int n;

class Solution {
    int check(vector<int> & piles) {
        auto rd_func = [](int a, int b) { return a + b / n + (b % n != 0); };
        return accumulate(piles.begin(), piles.end(), 0, rd_func);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1000000001;
        while (l < r) {
            n = l + (r-l) / 2;
            if (check(piles) > h) {
                l = n+1;
            } else {
                r = n;
            }
        }
        return l;
    }
};