impl Solution {
     pub fn find_min(nums: Vec<i32>) -> i32 {
        // binary search
        let (mut l, mut r) = (0, nums.len()-1);  // [l, r]
        while l < r {
            let mid = (l + r) / 2;
            if nums[mid] > nums[r] {
                // if nums[mid] > nums[r], the smallest must in the right of mid
                l = mid + 1;
            } else {
                // left is coutinuous increasing
                r = mid;
            }
        }
        nums[l]
    }
    // pub fn find_min(nums: Vec<i32>) -> i32 {
    //     if nums[0] < nums[nums.len()-1] {
    //         nums[0]
    //     } else {
    //         // binary search
    //         let (mut l, mut r) = (0, nums.len()-1);  // [l, r]
    //         while l < r {
    //             let mid = (l + r) / 2;
    //             if nums[mid] < nums[r] {
    //                 r = mid;
    //             } else if nums[mid] > nums[l] {
    //                 l = mid;
    //             } else {
    //                 // mins[l] >= nums[mid] >= nums[r]
    //                 // => nums[l] == nums[mid] > nums[r]
    //                 // or nums[l] > nums[mid] == nums[r]
    //                 // in this condition, difference of l and r are only be 1 and r should be the smallest
    //                 println!("l: {}, m: {}, r: {}", l, mid, r);
    //                 l = r;
    //             }
    //         }
    //         nums[l]
    //     }
    // }
}