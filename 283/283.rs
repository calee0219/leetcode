struct Solution {}


impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut shift: usize = 0;
        for idx in 0..nums.len() {
            if nums[idx] != 0 {
                nums[shift] = nums[idx];
                shift += 1;
            }
        }
        for idx in shift..nums.len() {
            nums[idx] = 0;
        }
    }
}
