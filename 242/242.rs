impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        let (mut s_save, t_save) = ([0; 26], [0; 26]);
        for c in s.chars() {
            s_save[(c as u8 - 'a' as u8) as usize] += 1;
        }
        for c in t.chars() {
            if s_save[(c as u8 - 'a' as u8) as usize] > 0 {
                s_save[(c as u8 - 'a' as u8) as usize] -= 1;
            } else {
                return false;
            }
        }
        true
    }
}
