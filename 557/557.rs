struct Solution {}

impl Solution {
    pub fn reverse_words(s: String) -> String {
        let s_len = s.len();
        let mut w_len = 0;
        let mut ret_s = String::new();
        for (i, c) in s.chars().enumerate() {
            if c == ' ' {
                for idx in ((i-w_len)..i).rev() {
                    ret_s.push(s.as_bytes()[idx] as char);
                }
                ret_s.push(' ');
                w_len = 0;
                continue;
            }
            w_len += 1;
        }
        for idx in ((s_len-w_len)..s_len).rev() {
            ret_s.push(s.as_bytes()[idx] as char);
        }
        ret_s
    }
}
