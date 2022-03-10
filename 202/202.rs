impl Solution {
    pub fn is_happy(n: i32) -> bool {
        fn process(n: i32) -> i32 {
            if n == 0 {
                0
            } else {
                (n % 10) * (n % 10) + process(n/10)
            }
        }
        let (mut slow, mut fast) = (n, n);
        loop {
            slow = process(slow);
            fast = process(process(fast));
            // println!("{} {}", slow, fast);
            if slow == 1 || fast == 1 {
                return true;
            }
            if slow == fast {
                break;
            }
        }
        false
    }
}