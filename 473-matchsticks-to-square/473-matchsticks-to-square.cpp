class Solution {
    bool rec(const int length, vector<int>& matchsticks, int stick, vector<int>& sides) {
        if (stick == matchsticks.size()) {
            if (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])
                return true;
            else
                return false;
        }
        for (int idx = 0; idx < 4; ++idx) {
            if (sides[idx] + matchsticks[stick] <= length) {
                sides[idx] += matchsticks[stick];
                if (rec(length, matchsticks, stick+1, sides))
                    return true;
                sides[idx] -= matchsticks[stick];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), [](int a, int b){return a > b;});
        long long int sum = 0;
        for (int m: matchsticks)
            sum += m;
        if (sum % 4) return false;
        vector<int> sides (4, 0);
        return rec(sum / 4, matchsticks, 0, sides);
    }
};