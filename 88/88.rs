impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
    	// do from back, because there is space enough to fill in n2 at most
        // if index < 0, the queue is empty. we cannot declear as usize
        // due to the overflow will stop us from checking queue empty
        let mut idx1 = (m - 1);
        let mut idx2 = (n - 1);
        let mut idx = (m + n - 1);
        while idx >= 0 {
            // put in to nums1[idx]
            if idx1 >= 0 && idx2 >= 0 {
                if nums1[idx1 as usize] >= nums2[idx2 as usize] {
                    nums1[idx as usize] = nums1[idx1 as usize];
                    idx1 -= 1;
                } else {
                    nums1[idx as usize] = nums2[idx2 as usize];
                    idx2 -= 1;
                }
            } else if idx1 >= 0 {
                nums1[idx as usize] = nums1[idx1 as usize];
                idx1 -= 1;
            } else {
                nums1[idx as usize] = nums2[idx2 as usize];
                idx2 -= 1;
            }
            idx -= 1;
        }
        // let clone1 = nums1.clone();
        // let (mut idx1, mut idx2): (usize, usize) = (0, 0);
        // for idx in 0..(m+n) as usize {
        //     if idx1 < m as usize && idx2 < n as usize {
        //         if clone1[idx1] < nums2[idx2] {
        //             nums1[idx] = clone1[idx1];
        //             idx1 += 1;
        //         } else {
        //             nums1[idx] = nums2[idx2];
        //             idx2 += 1;
        //         }
        //     } else if idx1 < m as usize {
        //         nums1[idx] = clone1[idx1];
        //         idx1 += 1;
        //     } else {
        //         nums1[idx] = nums2[idx2];
        //         idx2 += 1;
        //     }
        // }
    }
}