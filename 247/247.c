impl Solution {
    pub fn find_strobogrammatic(n: i32) -> Vec<String> {
        fn rec(depth: i32, n: i32, s: String, vec: &mut Vec<String>) {
            if n == depth {
                vec.push(s);
                return;
            }
            let candidate = ["0", "1", "8", "6", "9"];
            if depth == 0 {
                for idx in 1..5 {
                    rec(depth+1, n, s.clone()+candidate[idx], vec);
                }
            } else if (n & 1) == 1 && depth == n/2 {
                for idx in 0..3 {
                    rec(depth+1, n, s.clone()+candidate[idx], vec);
                }
            } else if depth >= n/2 {
                let mut tmp = s.clone();
                let mut c: char;
                if s.as_bytes()[(n-depth-1) as usize] as char == '6' {
                    c = '9';
                } else if s.as_bytes()[(n-depth-1) as usize] as char == '9' {
                    c = '6'
                } else {
                    c = s.as_bytes()[(n-depth-1) as usize] as char;
                }
                tmp.push(c);
                rec(depth+1, n, tmp, vec);
            } else {
                for idx in 0..5 {
                    rec(depth+1, n, s.clone()+candidate[idx], vec);
                }
            }
        }
        if n == 1 {
            return vec!["0".to_string(), "1".to_string(), "8".to_string()];
        }
        let mut vec = Vec::new();
        let s = "";
        rec(0, n, "".to_string(), &mut vec);
        vec
    }
}
