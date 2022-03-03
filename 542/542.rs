impl Solution {
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        fn dfs1(mat: &Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>, m: usize, n: usize) -> i32 {
            if mat[m][n] == 0 {
                0
            } else {
                let mut tmp = 1;
                if n > 0 && m > 0 {
                    tmp += std::cmp::min(dp[m][n-1], dp[m-1][n]);
                } else if n > 0 {
                    tmp += dp[m][n-1];
                } else if m > 0 {
                    tmp += dp[m-1][n];
                } else {
                    tmp = std::i32::MAX;
                }
                if tmp < 0 {
                    dp[m][n]
                } else {
                    std::cmp::min(tmp, dp[m][n])
                }
            }
        }
        fn dfs2(mat: &Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>, m: usize, n: usize) -> i32 {
            if mat[m][n] == 0 {
                0
            } else {
                let mut tmp = 1;
                if n < mat[0].len()-1 && m < mat.len()-1 {
                    tmp += std::cmp::min(dp[m][n+1], dp[m+1][n]);
                } else if n < mat[0].len()-1 {
                    tmp += dp[m][n+1];
                } else if m < mat.len()-1 {
                    tmp += dp[m+1][n];
                } else {
                    tmp = std::i32::MAX;
                }
                if tmp < 0 {
                    dp[m][n]
                } else {
                    std::cmp::min(tmp, dp[m][n])
                }
            }
        }
        
        let m_widgh = mat[0].len();
        let m_heigh = mat.len();
        let mut dp = vec![vec![std::i32::MAX; m_widgh]; m_heigh];
        for i in 0..(m_heigh+m_widgh-1) {
            for j in 0..=i {
                let k = i - j;
                if j < m_heigh && k < m_widgh {
                    // println!("i: {}, j: {}", j, k);
                    dp[j][k] = std::cmp::min(dfs1(&mat, &mut dp, j, k), dp[j][k]);
                }
            }
        }
        for i in (0..(m_heigh+m_widgh-1)).rev() {
            for j in (0..=i).rev() {
                let k = i - j;
                if j < m_heigh && k < m_widgh {
                    // println!("i: {}, j: {}", j, k);
                    dp[j][k] = std::cmp::min(dfs2(&mat, &mut dp, j, k), dp[j][k]);
                }
            }
        }
        dp
    }
}
