impl Solution {
    pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32 {
        if nums.len() < 3 {
            0
        } else {
            let mut subq_len = 2;
            let mut reminder = nums[1] - nums[0];
            let mut ans = 0;
            for idx in 2..nums.len() {
                if nums[idx] - nums[idx-1] == reminder {
                    subq_len += 1;
                } else {
                    ans += (subq_len-2 + 1) * (subq_len-2) / 2;
                    subq_len = 2;
                    reminder = nums[idx] - nums[idx-1];
                }
            }
            ans += (subq_len-2 + 1) * (subq_len-2) / 2;
            ans
        }
    }
}
