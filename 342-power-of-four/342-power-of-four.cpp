class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && !(__builtin_ctz(n) & 1) && !(n & (n-1));
    }
};