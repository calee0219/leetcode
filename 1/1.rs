impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = std::collections::HashMap::new();
        for (idx, &n) in nums.iter().enumerate() {
            if map.contains_key(&n) {
                return vec![idx as i32, map[&n]];
            }
            let tmp = target - n;
            map.insert(tmp, idx as i32,);
        }
        vec![]
    }
}