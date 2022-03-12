impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut min_size = std::i32::MAX;
        let mut sum = 0;
        let mut l = 0;
        for r in 0..nums.len() { // [l, r]
            sum += nums[r];
            while l <= r && sum >= target {
                min_size = std::cmp::min(min_size, (r-l+1) as i32);
                sum -= nums[l];
                l += 1;
            }
        }
        if min_size == std::i32::MAX {
            return 0;
        }
        min_size
    }
}
