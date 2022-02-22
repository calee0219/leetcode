impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut l: usize = 0;
        let mut r: usize = nums.len();
        while l < r {
            // [l, r)
            let mut mid: usize = l + (r-l)/2;
            if nums[mid] == target {
                return mid as i32;
            }
            if nums[mid] > target {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        r as i32
    }
    // pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
    //     nums.binary_search(&target).unwrap_or_else(|x| x) as i32
    // }
}
