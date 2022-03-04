impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        fn rec(depth: usize, nums: & Vec<i32>, seq: &mut Vec<i32>, used: &mut Vec<bool>, ans: &mut Vec<Vec<i32>>) {
            if depth == nums.len() {
                // println!("{:?}", seq);
                ans.push(seq.to_vec());
            }
            for idx in 0..nums.len() {
                if !used[idx] {
                    used[idx] = true;
                    seq.push(nums[idx]);
                    rec(depth+1, nums, seq, used, ans);
                    used[idx] = false;
                    seq.pop();
                }
            }
        }
        let num_len = nums.len();
        let mut used = vec![false; num_len];
        // let mut seq = vec![];
        let mut ans = vec![];
        rec(0, &nums, &mut vec![], &mut used, &mut ans);
        ans
    }
}
