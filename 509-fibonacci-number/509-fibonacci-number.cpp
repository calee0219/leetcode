class Solution {
public:
    int fib(int n) {
        int f[40];
        f[0] = 0; f[1] = 1;
        for (int idx = 2; idx <= n; ++idx)
            f[idx] = f[idx-1] + f[idx-2];
        return f[n];
    }
};