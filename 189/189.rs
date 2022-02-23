struct Solution {}

impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        /* Juggling Algrothm: In place practice, using shift and save */
        /* Time: O(n), Space: O(1) */
        // let num_len = nums.len();
        // let shift: usize = k as usize % num_len;

        // let mut mov: usize = 0;
        // let mut reserve: i32 = nums[mov];
        // let mut repeat: usize = 0;

        // let mut op_cnt: usize = 0;
        // while op_cnt < num_len {
        //     op_cnt += 1;
        //     let target = (mov + shift) % num_len;
        //     let tmp = nums[target];
        //     nums[target] = reserve;
        //     reserve = tmp;
        //     mov = target;
        //     if mov == repeat {
        //         mov = (mov + 1) % num_len;
        //         reserve = nums[mov];
        //         repeat = mov;
        //     }
        // }
        /* New a vector */
        /* Time: O(n), Space: O(n) */
        // let num_len = nums.len();
        // let k = k as usize % num_len;
        // let mut v = Vec::new();
        // for idx in 0..num_len {
        //     v.push(nums[(idx + num_len - k) % num_len]);
        // }
        // *nums = v;
        /* After some observation, just move last k number to front */
        /* Time: O(n), Space: O(k) */
        // let num_len = nums.len();
        // let k = k as usize % num_len;
        // //let tmp_v = &nums[num_len-k..];
        // let mut tmp_v = Vec::new();
        // for idx in 0..k {
        //     tmp_v.push(nums[num_len - k + idx]);
        // }
        // for idx in (0..num_len-k).rev() {
        //     nums[idx+k] = nums[idx];
        // }
        // for (i, n) in tmp_v.iter().enumerate() {
        //     nums[i] = *n;
        // }
        /* With above observation, we can use inplace solution */
        /* Time: O(n), Space: O(1) !!! attention, we need to use inplace reverse */
        let num_len = nums.len();
        let k = k as usize % num_len;
        // reverse 0..num_len
        nums.reverse();
        // for i in 0..num_len/2 {
        //     let tmp = nums[i];
        //     nums[i] = nums[num_len - 1 - i];
        //     nums[num_len - 1 - i] = tmp;
        // }
        // println!("{:?}", nums);
        // reverse 0..(k-1) // 0-base index
        // with in-place swap tips
        for i in 0..k/2 {
            // let tmp = nums[i];
            // nums[i] = nums[k - i - 1];
            // nums[k-i - 1] = tmp;
            nums[i] ^= nums[k-1-i];
            nums[k-1-i] ^= nums[i];
            nums[i] ^= nums[k-1-i];
        }
        //println!("{:?}", nums);
        // reverse k..(num_len-1)
        for i in 0..(num_len-k)/2 {
            // let tmp = nums[i + k];
            // nums[i + k] = nums[num_len - i - 1];
            // nums[num_len - i - 1] = tmp;
            nums[i+k] ^= nums[num_len-i-1];
            nums[num_len-i-1] ^= nums[i+k];
            nums[i+k] ^= nums[num_len-i-1];
        }
        //println!("{:?}", nums);
    }
}

fn main() {
    let mut v = vec![1,2,3,4,5,6,7,8,9];
    Solution::rotate(&mut v, 2);
    println!("{:?}", v);
}
