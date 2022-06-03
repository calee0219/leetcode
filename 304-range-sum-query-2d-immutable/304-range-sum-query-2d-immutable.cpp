class NumMatrix {
    vector<vector<int>> prefix_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix_sum.push_back(vector<int>(n+1, 0));
        for (int x = 0; x < m; ++x) {
            vector<int> v;
            v.push_back(0);
            for (int y = 0; y < n; ++y) {
                v.push_back(v.back() + matrix[x][y]);
            }
            prefix_sum.push_back(v);
        }
        for (int x = 1; x <= m; ++x) {
            for (int y = 1; y <= n; ++y) {
                prefix_sum[x][y] += prefix_sum[x-1][y];
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