struct Solution {}

impl Solution {
    pub fn maximum_even_split(final_sum: i64) -> Vec<i64> {
        if final_sum % 2 == 1 {
            return vec![];
        }
        let mut ans = Vec::new();
        let mut sum: i64 = 0;
        let mut i: i64 = 1;
        let helf_final: i64 = final_sum / 2;
        while sum + 2 * i + 1 <= helf_final {
            ans.push(i * 2);
            sum += i;
            i += 1;
        }
        ans.push(final_sum - sum * 2);
        //println!("{} {}", i, sum);
        ans
    }
}
