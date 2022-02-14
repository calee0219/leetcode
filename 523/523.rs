use std::collections::HashSet;

struct Solution {}

impl Solution {
    // fn check(nums: & Vec<i32>, start: i32 /* [  */, end: i32 /* ] */, sum: i32, k: i32) -> bool {
    //     if end - start <= 0 {
    //         return false;
    //     }
    //     if sum % k == 0 {
    //         return true;
    //     }
    //     // The testcase is not strong enough so add this condition can speed up return
    //     if sum < k {
    //         return false;
    //     }
    //     Solution::check(&nums, start+1, end, sum - nums[start as usize], k)
    // }
    pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
        // HashMap Solution O(n)
        let mut set = HashSet::new();
        let mut sum: i32 = nums[0] % k;
        let mut twice_before: i32 = nums[0] % k;
        for n in nums.iter().skip(1) {
            sum = (sum + n) % k;
            if set.contains(&sum) || sum == 0 {
                return true;
            }
            // insert twice number before so that when check set.contains,
            // we will not get the n-1's sum so n - (n-1) % k == 0.
            // in this condition, we will only get one number n % k == 0
            set.insert(twice_before);
            twice_before = sum;
        }
        false
        // O(n^2) speed up solution
        // if nums.len() <= 1 {
        //     return false;
        // }
        // let mut sum: i32 = nums[0];
        // for idx in 1..nums.len() {
        //     sum += nums[idx];
        //     if nums[idx] == 0 && nums[idx-1] == 0 {
        //         return true;
        //     }
        //     if Solution::check(&nums, 0, idx as i32, sum, k) {
        //         return true;
        //     }
        // }
        // false
    }
}

fn main() {
    let mut vec = std::vec::Vec::new();
    vec.push(23);
    vec.push(2);
    vec.push(4);
    vec.push(6);
    vec.push(7);
    println!("{}", Solution::check_subarray_sum(vec, 5));
}
