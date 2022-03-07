impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.iter().fold(0, |acc, n| acc ^ n)
        // let mut ans: i32 = 0;
        // for n in nums.iter() {
        //     ans ^= n;
        // }
        // ans
    }
}
