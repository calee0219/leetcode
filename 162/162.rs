impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        if nums.len() == 1 {
            0
        /*
	} else if nums[1] < nums[0] {
            0
        } else if nums[nums.len()-1] > nums[nums.len()-2] {
            nums.len() as i32 - 1
	*/
        } else {
            let (mut l, mut r) = (0, nums.len()-1);
            while l < r {
                let mid = l + ((r - l) >> 1); // avoid to overflow == l + ((r - l) / 2) == (l + r) / 2
                // check if increase or decrease
                // because nums[i] != nums[i + 1] for all valid i, there will no horizontal surface
                if nums[mid] > nums[mid+1] {
                    r = mid;
                } else { // nums[mid] < nums[mid+1], pick larger one, mid+1
                    l = mid+1;
                }
            }
            l as i32
        }
    }
}