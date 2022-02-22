/* Binary Search */

struct Solution {}

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut l: usize = 0;
        let mut r: usize = nums.len();
        // [l, r)
        while l < r {
            //println!("{} {}", l, r);
            let mid: usize = (r - l) / 2 + l; // avoid overflow
            let tmp: i32 = nums[mid];
            if target == tmp {
                return mid as i32;
            } else if target < tmp { // [l, target, mid, r)
                r = mid;
            } else {
                l = mid+1;
            }
        }
        -1
    }
}


fn main() {
    let v = vec![-1,0,3,5,9,12];
    let t = 9;
    println!("{}", Solution::search(v, t));
}
