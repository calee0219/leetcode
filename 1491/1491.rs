impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        let mut max = std::i32::MIN;
        let mut min = std::i32::MAX;
        let mut sum: f64 = salary.iter().fold(0, |acc, &n| {
            max = std::cmp::max(max, n);
            min = std::cmp::min(min, n);
            acc + n
        }) as f64;
        (sum - min as f64 - max as f64) / ((salary.len() - 2) as f64)
    }
}