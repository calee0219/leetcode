
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let num_len = nums.len();
        // do from outside to inside
        let mut left_idx: usize = 0;
        let mut right_idx: usize = num_len - 1;
        let mut ret = vec![0; num_len];
        // let mut idx = num_len;
        while left_idx <= right_idx {
            let right_sq = nums[right_idx] * nums[right_idx];
            let left_sq = nums[left_idx] * nums[left_idx];
            // idx -= 1;
            //println!("{} {}", nums[left_idx], nums[right_idx]);
            if left_sq >= right_sq {
                ret[right_idx - left_idx] = left_sq; // Use right_idx - left_idx replace num-- to reduce memory
                // ret[idx] = left_sq;
                left_idx += 1;
            } else {
                ret[right_idx - left_idx] = right_sq;
                // ret[idx] = right_sq;
                right_idx -= 1;
            }
        }
        ret
    }
}
