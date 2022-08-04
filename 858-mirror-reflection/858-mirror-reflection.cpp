class Solution {
    int gcd(int a, int b) {
        // a >= b
        if (!(a % b)) return b;
        return gcd(b, a % b);
    }
public:
    int mirrorReflection(int p, int q) {
        int c = gcd(p, q); // p >= q
        p /= c;
        q /= c;
        if (p&1 && q&1) return 1;
        if (p&1 && !(q&1)) return 0;
        if (!(p&1) && q&1) return 2;
        return -1;
    }
};