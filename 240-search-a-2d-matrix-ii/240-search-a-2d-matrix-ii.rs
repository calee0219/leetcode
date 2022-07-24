impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
//         let m = matrix.len();
//         let n = matrix[0].len();
//         let (mut x_l, mut x_r) = (0, m);
//         // let (mut y_l, mut y_r) = (0, n);
//         while (x_l < x_r) {
//             let x_mid = (x_l + x_r) / 2;
//             if (matrix[x_mid][0] == target) {
//                 return true;
//             } else if (matrix[x_mid][0] < target) {
                
//             } else {
//                 x_r = x_mid;
//             }
//         }
        for col in matrix.iter() {
            for c in col.iter() {
                if *c == target {
                    return true;
                }
            }
        }
        false
    }
}