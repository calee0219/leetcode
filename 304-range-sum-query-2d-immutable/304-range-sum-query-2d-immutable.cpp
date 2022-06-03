class NumMatrix {
    int prefix_sum[210][210];
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memset(prefix_sum, 0, sizeof(prefix_sum));
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                prefix_sum[x+1][y+1] = prefix_sum[x][y+1] + prefix_sum[x+1][y] + matrix[x][y] - prefix_sum[x][y];
            }
        }
        // for (int x = 0; x <= m; ++x) {
        //     for (int y = 0; y <= n; ++y)
        //         cout << prefix_sum[x][y] << " ";
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2 += 1; col2 += 1;
        return prefix_sum[row2][col2] - prefix_sum[row2][col1] - prefix_sum[row1][col2] + prefix_sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */