struct Solution {}

impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let num_len = numbers.len();
        // Binary Search
        // Time: O(nlogn), Space: O(1)
        // let mut idx1: i32 = 0;
        // let mut idx2: i32 = 0;
        // for idx in 0..num_len {
        //     let goal = target - numbers[idx];
        //     // search for goal from numbers[idx1+1] - numbers[numbers.len()-1]
        //     let mut start = idx+1;
        //     let mut end = num_len;
        //     while (start < end) {
        //         let mid = (start + end) / 2;
        //         if numbers[mid] == goal {
        //             idx2 = mid as i32;
        //             idx1 = idx as i32;
        //             break;
        //         }
        //         if numbers[mid] > goal {
        //             end = mid;
        //         } else {
        //             start = mid+1;
        //         }
        //     }
        // }
        // vec![idx1 + 1, idx2 + 1]
        // Two Pointer Solution
        // Time: O(n), Space: O(1)
        let mut left: usize = 0;
        let mut right: usize = num_len - 1;
        while (left < right) {
            let sum = numbers[left] + numbers[right];
            if sum == target {
                break;
            }
            if sum < target {
                left += 1;
            } else {
                right -= 1;
            }
        }
        vec![(left + 1) as i32, (right + 1) as i32]
    }
}
