impl Solution {
    pub fn largest_perimeter(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        for idx in (2..nums.len()).rev() {
            if nums[idx-2] + nums[idx-1] > nums[idx] {
                return nums[idx] + nums[idx-1] + nums[idx-2];
            }
        }
        0
    }
}