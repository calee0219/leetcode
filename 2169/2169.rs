impl Solution {
    pub fn count_operations(num1: i32, num2: i32) -> i32 {
        let mut ans: i32 = 0;
        let mut n1: i32 = num1;
        let mut n2: i32 = num2;
        while n1 != 0 && n2 != 0 {
            if n1 > n2 {
                ans += n1 / n2;
                n1 %= n2;
            } else {
                ans += n2 / n1;
                n2 %= n1;
            }
        }
        ans
    }
}
