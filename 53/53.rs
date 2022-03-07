struct Solution {}

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut sum_max_so_far: i32 = 0;
        let mut max_sum: i32 = nums[0];
        for n in nums.iter() {
            if (sum_max_so_far < 0) {
                sum_max_so_far = 0;
            }
            sum_max_so_far += n;
            max_sum = std::cmp::max(max_sum, sum_max_so_far);
        }
        max_sum
    }
    // pub fn max_sub_array(nums: Vec<i32>) -> i32 {
    //     let mut sum_max_so_far: i32 = 0;
    //     let mut max_sum: i32 = nums[0];
    //     for n in nums.iter() {
    //         sum_max_so_far += n;
    //         if (max_sum < sum_max_so_far) {
    //             max_sum = sum_max_so_far;
    //         }
    //         if (sum_max_so_far < 0) {
    //             sum_max_so_far = 0;
    //         }
    //     }
    //     max_sum
    // }
}
