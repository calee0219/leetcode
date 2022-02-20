struct Solution {}

impl Solution {
    pub fn count_even(num: i32) -> i32 {
        let mut tmp: i32 = num;
        let mut check: i32 = 0;
        while (tmp > 0) {
            check += tmp % 10;
            tmp /= 10;
        }
        if check & 1 == 1 {
            return (num-1) / 2; // go back to find the biggest even sumation
        }
        num / 2
    }
}
