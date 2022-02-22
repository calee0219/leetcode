use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        if s1.len() > s2.len() {
            return false;
        }
        let mut s1_map = HashMap::new();
        let mut s2_map = HashMap::new();
        // calc s1
        for ch in s1.chars() {
            let counter = s1_map.entry(ch).or_insert(0);
            *counter += 1;
        }
        let s1_len = s1.len();
        let mut total_distence = s1_len;
        for (idx, ch) in s2.chars().enumerate() {
            // println!("1. {} {}", idx, total_distence);
            if s1_map.contains_key(&ch) {
                let counter = s2_map.entry(ch).or_insert(0);
                *counter += 1;
                if *counter <= s1_map[&ch] {
                    total_distence -= 1;
                } else {
                    total_distence += 1;
                }
            }
            // println!("2. {} {}", idx, total_distence);
            if idx < s1_len {
                if total_distence == 0 {
                    return true
                }
                continue;
            }
            let remove_ch = s2.chars().nth(idx-s1_len).unwrap();
            if s2_map.contains_key(&remove_ch) {
                if s2_map[&remove_ch] <= s1_map[&remove_ch] {
                    total_distence += 1;
                } else {
                    total_distence -= 1;
                }
                *s2_map.get_mut(&remove_ch).unwrap() -= 1;
                //s2_map[&remove_ch] -= 1;
            }
            // println!("3. {} {}", idx, total_distence);
            if total_distence == 0 {
                return true
            }
        }
        if total_distence == 0 {
            return true
        }
        false
    }
    // Better sample solution
    // pub fn check_inclusion(s1: String, s2: String) -> bool {
    //     let (mut hm1, mut hm2) = ([0u16; 26], [0u16; 26]);
    //     for ch in s1.chars() {
    //         hm1[(ch as u8 - b'a') as usize] += 1;
    //     }
    //     let s2 = s2.as_bytes();
    //     for (i, ch) in s2.iter().enumerate() { // String can be iter()
    //         hm2[(ch - b'a') as usize] += 1;
    //         if i >= s1.len() {
    //             hm2[(s2[i - s1.len()] - b'a') as usize] -= 1;
    //         }
    //         if hm1 == hm2 { // Rust array can diff, so we don't need to maintain total_distance
    //             return true;
    //         }
    //     }
    //     false
    // }
}

fn main() {
    let s1 = String::from("a");
    let s2 = String::from("ab");
    println!("{}", Solution::check_inclusion(s1, s2));
}
