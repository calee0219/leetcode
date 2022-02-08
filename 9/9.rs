//use std::io;

struct Solution {}

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }
        let mut source: i32 = x;
        let mut target: i32 = 0;
        let mut reserve: i32 = 0;

        while source > 0 {
            if source == target || source * 10 + reserve == target {
                return true;
            }
            if target > source {
                return false;
            }
            //reserve = source % 10;
            target = target * 10 + source % 10;
            source /= 10;
        }
        target == x
    }
}

fn main(){
    println!("Resoult: {}", Solution::is_palindrome(11));
}
