struct Solution {}

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        if nums.len() <= 0 {
            return 0;
        }
        let mut now: i32 = nums[0];
        let mut count: i32 = 0;
        for n in nums {
            if now == n {
                count += 1;
            } else if count > 0 {
                count -= 1;
            } else {
                now = n;
                count += 1;
            }
        }
        now
    }
}


// impl Solution {
//     pub fn majority_element(nums: Vec<i32>) -> i32 {
//         let mut now: i32 = nums[0];
//         let mut count: i32 = 0;
//         for n in nums {
//             if count == 0 {
//                 now = n;
//             }
//             if now == n {
//                 count += 1;
//             } else {
//                 count -= 1;
//             }
//         }
//         now
//     }
// }
