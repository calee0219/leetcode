impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        match n {
            1|2 => n, // if n = 1, step = 1, n = 2, step = 2
            _ => {
                let (mut n_1, mut n_2) = (1, 2);    // n_1 stand for step[n-1], n_2 stand for step[n-2]
                for _ in 3..=n {
                    let tmp = n_1 + n_2;            // step[n] = step[n-1] + step[n-2]
                    n_1 = tmp;                      // step[n+1 - 1] = step[n]
                    n_2 = n_1;                      // step[n+1 - 2] = step[n-1]
                }
                n_1
            }
        }
    }
    // pub fn climb_stairs(n: i32) -> i32 {
    //     fn climb(n: i32, dp: &mut Vec<i32>) -> i32 {
    //         if n == 1 {
    //             1
    //         } else if n == 2 {
    //             2
    //         } else if dp[n as usize] != 0 {
    //             dp[n as usize]
    //         } else {
    //             dp[n as usize] = climb(n-1, dp) + climb(n-2, dp);
    //             dp[n as usize]
    //         }
    //     }
    //     let mut dp = vec![0; 46];
    //     climb(n, &mut dp)
    // }
}