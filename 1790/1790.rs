impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        if s1 == s2 {
            return true;
        }
        if s1.len() == s2.len() {
            let mut diff: [usize; 2] = [0; 2];
            let mut diff_idx = 0;
            for (idx, c) in s1.chars().enumerate() {
                if c != s2.chars().nth(idx).unwrap() {
                    if diff_idx >= 2 {
                        return false;
                    }
                    diff[diff_idx] = idx;
                    diff_idx += 1;
                }
            }
            if diff_idx == 2
            && s1.chars().nth(diff[0]).unwrap() == s2.chars().nth(diff[1]).unwrap()
            && s1.chars().nth(diff[1]).unwrap() == s2.chars().nth(diff[0]).unwrap() {
                return true;
            }
        }
        false
    }
}