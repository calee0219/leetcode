impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut exist = [0; 26];
        // count magazine
        for c in magazine.chars() {
            exist[(c as u8 - 'a' as u8) as usize] += 1;
        }
        for c in ransom_note.chars() {
            let tmp = (c as u8 - 'a' as u8) as usize;
            if exist[tmp] <= 0 {
                return false;
            }
            exist[tmp] -= 1;
        }
        true
    }
}
