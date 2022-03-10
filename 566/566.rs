impl Solution {
    pub fn matrix_reshape(mat: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        let (m, n) = (mat.len(), mat[0].len());
        if (m * n) as i32 != r * c {
            return mat;
        }
        let mut ret = vec![vec![0; c as usize]; r as usize];
        for r_idx in 0..m {
            for c_idx in 0..n {
                ret[(r_idx*n+c_idx)/c as usize][(r_idx*n+c_idx)%c as usize] = mat[r_idx][c_idx];
            }
        }
        ret
    }
}