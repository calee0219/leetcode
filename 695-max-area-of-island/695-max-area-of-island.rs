
impl Solution {
    pub fn max_area_of_island(mut grid: Vec<Vec<i32>>) -> i32 {
        fn dfs(graph: &mut Vec<Vec<i32>>, h: usize, w: usize) -> i32 {
            // println!("{} {}", h, w);
            if graph[h][w] == 0 {
                0
            } else {
                graph[h][w] = 0;
                1 + if h > 0 { dfs(graph, h-1, w) } else { 0 } +
                    if h < graph.len() - 1 { dfs(graph, h+1, w) } else { 0 } +
                    if w > 0 { dfs(graph, h, w-1) } else { 0 } +
                    if w < graph[0].len() - 1 { dfs(graph, h, w+1) } else { 0 }
            }
        }
        let mut max = 0;
        for h in 0..grid.len() {
            for w in 0..grid[0].len() {
                max = std::cmp::max(max, dfs(&mut grid, h, w));
            }
        }
        max
    }
}