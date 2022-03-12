impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut exist = [0; 26];
        let mut latest = 0;
        for (idx, c) in s.chars().enumerate() {
            // println!("{} {}", c, idx);
            let t_idx = (c as u8 - 'a' as u8) as usize;
            exist[t_idx] += 1;
            while latest <= idx && exist[(s.as_bytes()[latest] as u8 - 'a' as u8) as usize] > 1 {
                latest += 1;
            }
        }
        if latest == s.len() {
            return -1;
        }
        latest as i32
    }
}
