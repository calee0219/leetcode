impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let p_len = p.len();
        let mut p_count = [0; 26];
        for c in p.chars() {
            p_count[(c as u8 - 'a' as u8) as usize] += 1;
        }
        let mut w_count = [0; 26];
        let mut w_size = 0;
        let mut ret = vec![];
        for (idx, c) in s.chars().enumerate() {
            w_count[(c as u8 - 'a' as u8) as usize] += 1;
            if idx >= p_len {
                w_count[(s.as_bytes()[idx-p_len] - 'a' as u8) as usize] -= 1;
            }
            if idx >= p_len-1 && w_count == p_count {
                ret.push((idx - p_len + 1) as i32);
            }
        }
        ret
    }
}
