struct Solution {}

impl Solution {
    pub fn repeat_limited_string(s: String, repeat_limit: i32) -> String {
        let mut char_count: [i32; 26] = [0; 26];
        // Count char number
        for c in s.chars() {
            char_count[c as usize - 'a' as usize] += 1;
        }
        let mut idx: i32 = 25;
        let mut ans = String::new();
        let mut count: i32 = 0;
        while idx >= 0 {
            while idx >= 0 && char_count[idx as usize] == 0 {
                idx -= 1;
                count = 0;
            }
            if idx < 0 {
                break;
            }
            if count >= repeat_limit {
                // find next number to insert
                let mut tmp: i32 = idx - 1;
                while tmp >= 0 && char_count[tmp as usize] == 0 {
                    tmp -= 1;
                }
                if tmp < 0 {
                    break;
                }
                // insert char
                ans.push(('a' as u8 + tmp as u8) as char);
                char_count[tmp as usize] -= 1;
                count = 0;
                continue;
            }
            ans.push(('a' as u8 + idx as u8) as char);
            char_count[idx as usize] -= 1;
            count += 1;
        }
        ans
    }
}
