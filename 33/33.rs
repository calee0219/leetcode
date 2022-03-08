impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let num_len = nums.len();
        let (mut left, mut right) = (0, num_len);
        while left < right {
            let mid = (left + right) / 2;
            if nums[mid] == target {
                return mid as i32;
            }
            // println!("left{}: {}, mid{}: {}, right{}", left, nums[left], mid, nums[mid], right);
            if nums[mid] > nums[left] {
                if target >= nums[left] && target < nums[mid] {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if nums[mid] < nums[left] {
                if target > nums[mid] && target <= nums[right - 1] {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else { // nums[mid] == nums[left]
	        // I don't think this will happened (?)
                left += 1;
            }
        }
        -1
    }
    // Or maybe find shift value also with BS
    // not implement
    // pub fn search(nums: Vec<i32>, target: i32) -> i32 {
    //     fn id(idx: usize, shift: usize, size: usize) -> usize {
    //         (idx + shift) % size
    //     }
    //     let num_len = nums.len();
    //     // find shift size
    //     let mut shift = 0;
    //     for idx in 1..num_len {
    //         if nums[idx] < nums[idx-1] {
    //             shift = idx;
    //             break;
    //         }
    //     }
    //     println!("{}", shift);
    //     let (mut left, mut right) = (0, num_len);
    //     while left < right {
    //         let mid = (left + right) / 2;
    //         println!("left: {}, mid: {}, right: {}", left, mid, right);
    //         if nums[id(mid, shift, num_len)] == target {
    //             return id(mid, shift, num_len) as i32;
    //         }
    //         if nums[id(mid, shift, num_len)] < target {
    //             left = mid + 1;
    //         } else {
    //             right = mid;
    //         }
    //     }
    //     -1
    // }
}