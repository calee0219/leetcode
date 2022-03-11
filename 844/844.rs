impl Solution {
    // Two pointers version
    pub fn backspace_compare(s: String, t: String) -> bool {
        // the problem must be compare from back to front
        // a charactor will exist or not in the final depand on future backspace
        let (mut sp, mut tp) = ((s.len()-1) as i32, (t.len()-1) as i32);
        let (mut s_remind_bs, mut t_remind_bs) = (0, 0);
        while sp >= 0 || tp >= 0 {
            // println!("{} {}", sp, tp);
            while sp >= 0 && s.as_bytes()[sp as usize] == '#' as u8 {
                s_remind_bs += 1;
                sp -= 1;
            }
            while tp >= 0 && t.as_bytes()[tp as usize] == '#' as u8 {
                t_remind_bs += 1;
                tp -= 1;
            }
            // sp and tp all point to char
            if s_remind_bs != 0 {
                s_remind_bs -= 1;
                sp -= 1;
                continue;
            }
            if t_remind_bs != 0 {
                t_remind_bs -= 1;
                tp -= 1;
                continue;
            }
            // tow of pointer no remind bs
            if sp < 0 || tp < 0 {
                return false;
            }
            if s.as_bytes()[sp as usize] != t.as_bytes()[tp as usize] {
                return false;
            } else {
                sp -= 1;
                tp -= 1;
            }
        }
        true
    }
    // Stack version, Time: O(n), Space: O(n)
    // pub fn backspace_compare(s: String, t: String) -> bool {
    //     let mut s1 = Vec::new();
    //     let mut s2 = Vec::new();
    //     let mut idx = 0;
    //     while idx < s.len() || idx < t.len() {
    //         if idx < s.len() {
    //             if s.as_bytes()[idx] == '#' as u8 {
    //                 s1.pop();
    //             } else {
    //                 s1.push(s.as_bytes()[idx] as char);
    //             }
    //         }
    //         if idx < t.len() {
    //             if t.as_bytes()[idx] == '#' as u8 {
    //                 s2.pop();
    //             } else {
    //                 s2.push(t.as_bytes()[idx] as char);
    //             }
    //         }
    //         idx += 1;
    //     }
    //     if s1 == s2 {
    //         return true;
    //     }
    //     false
    // }
}