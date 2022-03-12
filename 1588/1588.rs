impl Solution {
    pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
        arr.iter().enumerate().fold(0, |sum, (idx, &n)| {
            sum + n * (((idx+1) * (arr.len()-idx) + 1) / 2) as i32
        })
    }
    // pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
    //     let mut ans: i32 = 0;
    //     let arr_len = arr.len();
    //     for (idx, &n) in arr.iter().enumerate() {
    //         for w in (1..=arr_len).step_by(2) {
    //             let mut times = idx+1;
    //             times = std::cmp::min(times, arr_len-times+1);
    //             times = std::cmp::min(times, w);
    //             times = std::cmp::min(times, arr_len-w+1);
    //             // println!("{} {} {}", n, w, times);
    //             ans += n * times as i32;
    //         }
    //     }
    //     ans
    // }
}
