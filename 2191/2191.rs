impl Solution {
    pub fn sort_jumbled(mapping: Vec<i32>, nums: Vec<i32>) -> Vec<i32> {
        let mut arr: Vec<(i32, usize)> = Vec::new();
        for (idx, &n) in nums.iter().enumerate() {
            let mut n = n;
            let mut tmp: i32 = 0;
            let mut lev: i32 = 1;
            // println!("{} {}", n, mapping[(n%10) as usize]);
            if n == 0 {
                tmp += mapping[0];
            }
            while n > 0 {
                tmp += mapping[(n%10) as usize] * lev;
                lev *= 10;
                n /= 10;
            }
            // println!("{}", tmp);
            arr.push((tmp, idx));
        }
        arr.sort();
        let mut sorted_arr: Vec<i32> = Vec::new();
        for tuple in arr {
            sorted_arr.push(nums[tuple.1]);
        }
        sorted_arr
    }
}