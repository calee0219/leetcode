impl Solution {
    // Two Sum solution w/ tow pointers
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    	if nums.len() < 3 { return vec![]; }
        let num_len = nums.len();
        let mut nums = nums;
        nums.sort();
        let mut ans = Vec::new();
        // iterate  num[1] and find num[2] & num[3] with two sum solution
        let mut last = 10001; // will not exist in nums as the first value
        for idx in 0..num_len {
            if nums[idx] == last {
                // check duplicate
                continue;
            }
            last = nums[idx];
            // two pointer solution on two sum
            let (mut l, mut r) = (idx+1, num_len-1);
            while l < r {
                // println!("{} {}", l, r);
                if nums[l] + nums[r] == -nums[idx] {
                    ans.push(vec![nums[idx], nums[l], nums[r]]);
                    // shift if nums[l] == nums[l+1]
                    let record = nums[l];
                    while nums[l] == record && l < r {
                        l += 1;
                    }
                }
                if nums[l] + nums[r] < -nums[idx] {
                    l += 1;
                } else {
                    r -= 1;
                }
            }
        }
        ans
    }

    // Map, Set solution
    // pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    //     let num_len = nums.len();
    //     let mut map = std::collections::HashMap::new();
    //     let mut set = std::collections::HashSet::new();
    //     for n in nums.iter() {
    //         *map.entry(n).or_insert(0) += 1;
    //     }
    //     for i in 0..num_len {
    //         *map.entry(&nums[i]).or_insert(0) -= 1;
    //         for j in (i+1)..num_len {
    //             *map.entry(&nums[j]).or_insert(0) -= 1;
    //             let find = - nums[i] - nums[j];
    //             match map.get(&find) {
    //                 None | Some(&0) => (),
    //                 _ => {
    //                     let mut tmp = vec![nums[i], nums[j], find];
    //                     tmp.sort();
    //                     set.insert(tmp);
    //                 },
    //             }
    //             *map.entry(&nums[j]).or_insert(0) += 1;
    //         }
    //         *map.entry(&nums[i]).or_insert(0) += 1;
    //     }
    //     let mut ans = Vec::new();
    //     for s in set {
    //         ans.push(s);
    //     }
    //     ans
    // }
}