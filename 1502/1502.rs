impl Solution {
    // O(n) Solution, using set
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        // find difference
        let max = *arr.iter().max().unwrap();
        let min = *arr.iter().min().unwrap();
        let diff = (max - min) / (arr.len() as i32 - 1);
        let set: std::collections::HashSet<i32> = arr.into_iter().collect();
        // for s in set {
        //     println!("{}", s);
        // }
        let mut curr = min;
        while curr < max {
	    // Don't check max due to the special case of diff == 0
	    // Also max will already be true because if the n-1 is arithmetic, n - n-1 will be diff for sure
            if !set.contains(&curr) {
                // println!("{} {}", curr, diff);
                return false;
            }
            curr += diff;
        }
        true
    }
    // O(nlogn) solution using sort
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        let mut arr = arr;
        arr.sort();
        let diff = arr[1] - arr[0];
        for idx in 2..arr.len() {
            if diff != arr[idx] - arr[idx-1] {
                return false;
            }
        }
        true
    }
}