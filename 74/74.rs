impl Solution {
    // BS twice
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        let (mut left, mut right) = (0, m);
        while left < right {
            let mid = (left + right) / 2;
            let mid_val = matrix[mid][0];
            if target == mid_val {
                return true;
            }
            if target < mid_val {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        let mut col = 0;
        if left != 0 {
            col = left - 1;
        }
        left = 0;
        right = n;
        while left < right {
            let mid = (left + right) / 2;
            let mid_val = matrix[col][mid];
            if target == mid_val {
                return true;
            }
            if target < mid_val {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        false
    }
    // reduce 2D array to 1D array
    // pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
    //     let m = matrix.len();
    //     let n = matrix[0].len();
    //     let (mut left, mut right) = (0, m*n);
    //     while left < right {
    //         let mid = (left + right) / 2;
    //         let mid_val = matrix[mid/n][mid%n];
    //         if target == mid_val {
    //             return true;
    //         }
    //         if target < mid_val {
    //             right = mid;
    //         } else {
    //             left = mid + 1;
    //         }
    //     }
    //     false
    // }
}