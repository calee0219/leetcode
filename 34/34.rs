impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        if nums.len() == 0 || target < nums[0] || target > nums[nums.len()-1] {
            return vec![-1, -1];
        }
        // search start
        let (mut left, mut right) = (0, nums.len()); // [left, right)
        while left < right {
            let mid = (left + right) / 2;
            if nums[mid] < target {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        // println!("{} {}", left, nums[left]);
        if nums[left] != target {
            return vec![-1, -1];
        }
        let start = left as i32;
        // search end
	// left can start with start to increase the speed
        // left = start;
        right = nums.len();
        while left < right {
            let mid = (left + right) / 2;
            if nums[mid] <= target {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        // println!("{} {}", left, nums[left]);
        let end = left as i32;
        vec![start, end-1]
    }
}