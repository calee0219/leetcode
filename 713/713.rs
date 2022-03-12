/*
1
12   2
123  23  3
1234 234 34 4
*/
use std::collections::HashSet;

impl Solution {
    pub fn num_subarray_product_less_than_k(nums: Vec<i32>, k: i32) -> i32 {
        let mut total = 0;
        let mut start = 0;
        let mut product = 1;
        for end in 1..=nums.len() { // end not included: [start, end)
            product *= nums[end-1];
            while start < end && product >= k {
                product /= nums[start];
                start += 1;
            }
            // println!("{} {} {}", start, end, product);
            total += (end - start) as i32;
        }
        total
    }
    
    // pub fn num_subarray_product_less_than_k(nums: Vec<i32>, k: i32) -> i32 {
    //     fn iter(nums: &Vec<i32>, start: usize, end: usize, product: i32, k: i32, visited: &mut HashSet<(usize,usize)>) -> i32 {
    //         if visited.contains(&(start,end)) {
    //             return 0;
    //         } else {
    //             visited.insert((start,end));
    //         }
    //         // println!("{} {} {}", start, end, product);
    //         let mut sub = 0;
    //         if start < end {
    //             // do right process
    //             sub += iter(nums, start+1, end, product / nums[start], k, visited);
    //         }
    //         if product < k {
    //             if end < nums.len()-1 {
    //                 // do down process
    //                 sub += iter(nums, start, end+1, product * nums[end+1], k, visited);
    //             }
    //             1 + sub
    //         } else {
    //             sub
    //         }
    //     }
    //     let mut visited = HashSet::new();
    //     iter(&nums, 0, 0, nums[0], k, &mut visited)
    // }
}
