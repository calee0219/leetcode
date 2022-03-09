impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut record = [0; 1001];
        for &n in nums1.iter() {
            record[n as usize] += 1;
        }
        let mut ans = Vec::new();
        for &n in nums2.iter() {
            if record[n as usize] != 0 {
                ans.push(n);
                record[n as usize] -= 1;
            }
        }
        ans
    }
}