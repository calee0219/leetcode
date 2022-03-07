impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        (high - low) / 2 + ((high | low) & 1)
    }
}