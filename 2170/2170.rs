impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        // freq[is_odd][first or second] used to record first or second frequence number
        // freq[0][0] for first freq even
        // freq[0][1] for second freq even
        // freq[1][0] for first freq odd
        // freq[1][1] for second freq odd
        let mut freq: [[i32; 2]; 2] = [[0; 2]; 2];
        // count[is_odd][n], count the frequence of odd or even n
        let mut count: [[i32; 100001]; 2] = [[0; 100001]; 2];
        for (idx, &n) in nums.iter().enumerate() {
            let is_odd: usize = (idx & 1) as usize;
            count[is_odd][n as usize] += 1;
            if count[is_odd][n as usize] >= count[is_odd][freq[is_odd][0] as usize] {
                // Check if freq[x][0] should shift to freq[x][1] or not
                if freq[is_odd][0] != n {
                    freq[is_odd][1] = freq[is_odd][0];
                }
                freq[is_odd][0] = n;
            } else if count[is_odd][n as usize] > count[is_odd][freq[is_odd][1] as usize] {
                freq[is_odd][1] = n;
            }
        }
        if freq[0][0] == freq[1][0] {
            if count[0][freq[0][1] as usize] + count[1][freq[1][0] as usize] >
                count[0][freq[0][0] as usize] + count[1][freq[1][1] as usize] {
                    return nums.len() as i32 - count[0][freq[0][1] as usize] - count[1][freq[1][0] as usize];
                }
            return nums.len() as i32 - count[0][freq[0][0] as usize] - count[1][freq[1][1] as usize]
        }
        nums.len() as i32 - count[0][freq[0][0] as usize] - count[1][freq[1][0] as usize]
    }
}
