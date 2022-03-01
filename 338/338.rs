impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut v = vec![0; n as usize + 1];
        // for i in 1..=n {
        //     // if i is even, ig. 10010, the bit will same as shift 1, 1001
        //     // if i is odd, ig. 1001, the bit will same as shift 1 add 1, 100 need to add 1
        //     // because shift 1 will remove right significant bit 1001<- this 1
        //     v.push(v[(i as usize)>>1] + (i & 1));
        // }
        (1..=n as usize).for_each(|i| v[i] = v[i>>1] + (i & 1) as i32);
        v
    }
    // pub fn count_bits(n: i32) -> Vec<i32> {
    //     fn MSB(mut n: usize) -> usize {
    //         n |= n>>1;
    //         n |= n>>2;
    //         n |= n>>4;
    //         n |= n>>8;
    //         n |= n>>16;
    //         n += 1;
    //         n >>= 1;
    //         n
    //     }
    //     let mut v = Vec::new();
    //     v.push(0);
    //     for i in 1..=n as usize {
    //         v.push(v[i - MSB(i)] + 1);
    //     }
    //     v
    // }
}
