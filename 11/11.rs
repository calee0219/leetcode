impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut l, mut r) = (0, height.len()-1);
        let mut ret = 0;
        while l < r {
            // ret = std::cmp::max(ret, (r - l) as i32 * std::cmp::min(height[l], height[r]));
            if height[l] <= height[r] {
                ret = std::cmp::max(ret, (r - l) as i32 * height[l]);
                // l move right
                // let tmp = height[l];
                // while l < r && height[l] <= tmp {
                //     l += 1;
                // }
                l += 1;
            } else {
                ret = std::cmp::max(ret, (r - l) as i32 * height[r]);
                // r move left
                // let tmp = height[r];
                // while l < r && height[r] <= tmp {
                //     r -= 1;
                // }
                r -= 1;
            }
        }
        ret
    }
}
