class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool flip_x = false;
        bool flip_y = false;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (matrix[x][y] == 0) {
                    if (x == 0) flip_y = true;
                    if (y == 0) flip_x = true;
                    matrix[0][y] = 0;
                    matrix[x][0] = 0;
                }
            }
        }
        for (int x = 1; x < m; ++x) {
            for (int y = 1; y < n; ++y) {
                if (matrix[x][0] == 0 || matrix[0][y] == 0) {
                    matrix[x][y] = 0;
                }
            }
        }
        if (flip_x) {
            for (int x = 0; x < m; ++x)
                matrix[x][0] = 0;
        }
        if (flip_y) {
            for (int y = 0; y < n; ++y)
                matrix[0][y] = 0;
        }
    }
};