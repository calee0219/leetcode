struct Solution {}

impl Solution {
    fn dfs(mut v: &mut Vec<Vec<i32>>, sr: usize, sc: usize, new_color: i32, old_color: i32) {
        if (v[sr][sc] != old_color) {
            return;
        }
        (*v)[sr][sc] = new_color;
        if sr < v.len()-1 { Solution::dfs(&mut v, sr+1, sc, new_color, old_color); }
        if sr > 0 { Solution::dfs(&mut v, sr-1, sc, new_color, old_color); }
        if sc < v[0].len()-1 { Solution::dfs(&mut v, sr, sc+1, new_color, old_color); }
        if sc > 0 { Solution::dfs(&mut v, sr, sc-1, new_color, old_color); }
    }

    pub fn flood_fill(image: Vec<Vec<i32>>, sr: i32, sc: i32, new_color: i32) -> Vec<Vec<i32>> {
        let mut v = image.clone();
        let old_color = image[sr as usize][sc as usize];
        if old_color == new_color {
            return v;
        }
        Solution::dfs(&mut v, sr as usize, sc as usize, new_color, old_color);
        v
    }
}
