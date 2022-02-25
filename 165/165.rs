impl Solution {
    pub fn compare_version(version1: String, version2: String) -> i32 {
        let mut max_bit_1: u32 = 0;
        let mut max_bit_2: u32 = 0;
        let mut curr_bit_1: usize = 0;
        let mut curr_bit_2: usize = 0;
        while curr_bit_1 < version1.len() && curr_bit_2 < version2.len() {
            while curr_bit_1 < version1.len() && version1.as_bytes()[curr_bit_1] != '.' as u8 {
                max_bit_1 *= 10;
                max_bit_1 += (version1.as_bytes()[curr_bit_1] - '0' as u8) as u32;
                curr_bit_1 += 1;
            }
            while curr_bit_2 < version2.len() && version2.as_bytes()[curr_bit_2] != '.' as u8 {
                max_bit_2 *= 10;
                max_bit_2 += (version2.as_bytes()[curr_bit_2] - '0' as u8) as u32;
                curr_bit_2 += 1;
            }
            if max_bit_1 < max_bit_2 {
                return -1;
            }
            if max_bit_1 > max_bit_2 {
                return 1;
            }
            max_bit_1 = 0;
            max_bit_2 = 0;
            curr_bit_1 += 1;
            curr_bit_2 += 1;
            // println!("{} {}", curr_bit_1, curr_bit_2);
        }
        while curr_bit_1 < version1.len() {
            if version1.as_bytes()[curr_bit_1] != '.' as u8 && version1.as_bytes()[curr_bit_1] != '0' as u8 {
                return 1;
            }
            curr_bit_1 += 1;
            // println!("1: {} {}", curr_bit_1, curr_bit_2);
        }
        while curr_bit_2 < version2.len() {
            if version2.as_bytes()[curr_bit_2] != '.' as u8 && version2.as_bytes()[curr_bit_2] != '0' as u8 {
                return -1;
            }
            curr_bit_2 += 1;
            // println!("2: {} {}", curr_bit_1, curr_bit_2);
        }
        return 0;
    }
}
