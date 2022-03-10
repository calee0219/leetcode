impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut ret: Vec<Vec<i32>> = Vec::new();
        for row in 0..num_rows as usize {
            let mut tmp = Vec::new();
            for col in 0..=row {
                // println!("{} {}", row, col);
                if col == 0 {  tmp.push(1); }
                else if col == row { tmp.push(1); }
                else { tmp.push(ret[row-1][col-1] + ret[row-1][col]); }
            }
            ret.push(tmp);
        }
        ret
    }
}