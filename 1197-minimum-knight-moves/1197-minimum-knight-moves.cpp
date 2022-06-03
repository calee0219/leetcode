class Solution {
    int mem[310][310] = {};
public:
    int minKnightMoves(int x, int y) {
        x = abs(x); y = abs(y);
        if (mem[x][y] != 0) return mem[x][y];
        if (x + y == 0) return 0;
        if (x + y == 2) return 2;
        mem[x][y] = min(minKnightMoves(x-2, y-1), minKnightMoves(x-1, y-2)) + 1;
        return mem[x][y];
    }
};