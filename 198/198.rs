impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        if nums.len() < 2 {
            return nums[0];
        }
        let mut dp = vec![];
        dp.push(nums[0]);
        dp.push(std::cmp::max(nums[1], nums[0]));
        for idx in 2..nums.len() {
            dp.push(std::cmp::max(dp[idx-1], dp[idx-2]+nums[idx]));
        }
        dp[nums.len()-1]
    }
}