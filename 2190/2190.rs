impl Solution {
    pub fn most_frequent(nums: Vec<i32>, key: i32) -> i32 {
        let num_len = nums.len();
        let mut count = [0; 1001];
        for idx in 0..num_len-1 {
            if nums[idx] == key {
                count[nums[idx+1] as usize] += 1;
            }
        }
        let mut max_idx: usize = 0;
        for idx in 0..1001 {
            if count[idx] > count[max_idx] {
                max_idx = idx;
            }
        }
        max_idx as i32
    }
}