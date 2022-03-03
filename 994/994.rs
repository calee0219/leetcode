impl Solution {
    pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let mut fresh_cnt = 0;
        let mut stack = vec![];
        for iidx in 0..grid.len() {
            for jidx in 0..grid[0].len() {
                if grid[iidx][jidx] == 1 {
                    fresh_cnt += 1;
                }
                if grid[iidx][jidx] == 2 {
                    stack.push((iidx, jidx));
                }
            }
        }
        let mut min = 0;
        while !stack.is_empty() {
            let mut tmp = vec![];
            for v in stack {
                // println!("{} {}", v.0, v.1);
                if v.0 > 0 && grid[v.0-1][v.1] == 1 {
                    tmp.push((v.0-1, v.1));
                    grid[v.0-1][v.1] = 2;
                    fresh_cnt -= 1;
                }
                if v.1 > 0 && grid[v.0][v.1-1] == 1 {
                    tmp.push((v.0, v.1-1));
                    grid[v.0][v.1-1] = 2;
                    fresh_cnt -= 1;
                }
                if v.0 < grid.len()-1 && grid[v.0+1][v.1] == 1 {
                    tmp.push((v.0+1, v.1));
                    grid[v.0+1][v.1] = 2;
                    fresh_cnt -= 1;
                }
                if v.1 < grid[0].len()-1 && grid[v.0][v.1+1] == 1 {
                    tmp.push((v.0, v.1+1));
                    grid[v.0][v.1+1] = 2;
                    fresh_cnt -= 1;
                }
            }
            if !tmp.is_empty() {
                min += 1;
            }
            stack = tmp;
            // println!("---");
        }
        if fresh_cnt != 0 {
            -1
        } else {
            min
        }
    }
}
