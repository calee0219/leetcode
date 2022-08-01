impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        fn dp(cache: &mut Vec<Vec<i32>>, m: usize, n: usize) -> i32 {
            if cache[m][n] != 0 { return cache[m][n]; }
            if n == 0 && m == 0 {
                cache[m][n] = 1;
                1
            } else if n == 0 {
                cache[m][n] = dp(cache, m-1, n);
                cache[m][n]
            } else if m == 0 {
                cache[m][n] = dp(cache, m, n-1);
                cache[m][n]
            } else {
                cache[m][n] = dp(cache, m-1,n) + dp(cache, m, n-1);
                cache[m][n]
            }
        }
        let mut cache = vec![vec![0; n as usize]; m as usize];
        cache[0][0] = 1;
        dp(&mut cache, m as usize - 1, n as usize - 1)
    }
}