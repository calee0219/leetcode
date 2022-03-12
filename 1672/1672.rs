impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        for v in accounts.iter() {
            let mut sum = 0;
            for &w in v {
                sum += w;
            }
            ans = std::cmp::max(sum, ans);
        }
        ans
    }
}
