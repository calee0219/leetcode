impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        // let mut hs = std::collections::HashSet::new();
        // for n in nums.iter() {
        //     if hs.contains(&n) {
        //         return true;
        //     }
        //     hs.insert(n);
        // }
        // false
        let num_len = nums.len();
        let mut arr = nums;
        arr.sort();
        arr.dedup();
        if arr.len() != num_len {
            return true;
        }
        false
    }
}