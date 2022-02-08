//use std::io

struct Solution {}

impl Solution {
    fn sum_digit(x: i32) -> i32 {
        let mut y: i32 = x;
        let mut z: i32 = 0;
        while y != 0 {
            z += y % 10;
            y /= 10;
        }
        //println!("{}: {}", x, z);
        z
    }
    pub fn count_balls(low_limit: i32, high_limit: i32) -> i32 {
        let mut arr: [usize; 50] = [0; 50];
        //let mut ans: i32 = 0;
        for idx in low_limit..=high_limit {
            arr[Solution::sum_digit(idx) as usize] += 1;
        }
        arr.iter().copied().max().unwrap() as i32
    }
}

fn main() {
    println!("{}", Solution::count_balls(1, 200));
}
