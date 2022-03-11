use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn next_greater_element(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut stack = Vec::new();
        let mut max = vec![-1; 10010];
        for &n in nums2.iter() {
            while stack.last().unwrap_or(&std::i32::MAX) < &n {
                let tmp = stack.pop().unwrap();
                max[tmp as usize] = n;
            }
            stack.push(n);
        }
        let mut ans = vec![];
        for &n in nums1.iter() {
            ans.push(max[n as usize]);
        }
        ans
    }
    // Priority Queue version, but there is no need to use priority queue!!!
    // if the previous element be push into the stack, it always remind decrease tend!!!
    // pub fn next_greater_element(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    //     let mut pq = BinaryHeap::new();
    //     let mut max = vec![-1; 10010];
    //     for &n in nums2.iter() {
    //         while pq.peek().is_some() && Reverse(n) < *pq.peek().unwrap() {
    //             let Reverse(tmp) = pq.pop().unwrap();
    //             // println!("{} {}", tmp, n);
    //             max[tmp as usize] = n;
    //         }
    //         pq.push(Reverse(n));
    //     }
    //     let mut ans = vec![];
    //     for &n in nums1.iter() {
    //         ans.push(max[n as usize]);
    //     }
    //     ans
    // }
}