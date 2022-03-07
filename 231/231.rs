impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n <= 0 {
            false
        } else {
            n & (n-1) == 0
        }
    }

    // pub fn is_power_of_two(n: i32) -> bool {
    //     if n <= 0 {
    //         false
    //     } else {
    //         let c = n.count_ones();
    //         if c == 1 {
    //             true
    //         } else {
    //             false
    //         }
    //     }
    // }

    // pub fn is_power_of_two(n: i32) -> bool {
    //     if n <= 0 {
    //         false
    //     } else {
    //         let mut m = n;
    //         while m & 1 == 0 {
    //             println!("{}", m);
    //             m >>= 1;
    //         }
    //         if m >> 1 == 0 {
    //             true
    //         } else {
    //             false
    //         }
    //     }
    // }
}