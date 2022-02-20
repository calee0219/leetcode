struct Solution {}

impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut ans: i32 = 0;
        for (i, ni) in nums.iter().enumerate() {
            for (j, nj) in nums.iter().enumerate().skip(i+1) {
                //println!("{} {}", i, j);
                if ni == nj && (i * j) as i32 % k == 0 {
                    //println!("{} {}", i, j);
                    ans += 1;
                }
            }
        }
        //println!("{nums:?}");
        ans
    }
}
