// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

struct Solution {}

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
		let mut l: i32 = 0;
        let mut r: i32 = n;
        // (l, r]
        while l < r {
            //println!("{} {}", l, r);
            let mid: i32 = (r - l) / 2 + l; // avoid overflow
            if self.isBadVersion(mid) { // (l, mid, r]
                r = mid;
            } else {
                l = mid+1;
            }
        }
        l
    }
}
