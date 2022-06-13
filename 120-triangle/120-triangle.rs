impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let mut tri = triangle;
        for dep in (0..tri.len()-1).rev() {
            for idx in 0..tri[dep].len() {
                tri[dep][idx] = std::cmp::min(tri[dep+1][idx], tri[dep+1][idx+1]) + tri[dep][idx];
            }
        }
        tri[0][0]
    }
}