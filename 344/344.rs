struct Solution {}

impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let s_len = s.len();
        for idx in 0..s_len/2 {
            // swap s[idx] s[s_len - 1 - idx]
            s[idx] = (s[idx] as u8 ^ s[s_len - 1 - idx] as u8) as char;
            s[s_len - 1 - idx] = (s[idx] as u8 ^ s[s_len - 1 - idx] as u8) as char;
            s[idx] = (s[idx] as u8 ^ s[s_len - 1 - idx] as u8) as char;
        }
    }
}
