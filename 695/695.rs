struct Solution {}

impl Solution {
    pub fn max_area_of_island(mut grid: Vec<Vec<i32>>) -> i32 {
        fn dfs(graph: &mut Vec<Vec<i32>>, h: usize, w: usize) -> i32 {
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

// impl Solution {
//     pub fn max_area_of_island(grid: Vec<Vec<i32>>) -> i32 {
//         let grid_height = grid.len();
//         let grid_weight = grid[0].len();

//         let mut max: i32 = 0;
//         let mut d = std::collections::VecDeque::new();
//         let mut visited: [[bool; 50]; 50] = [[false; 50]; 50];

//         for h in 0..grid_height {
//             for w in 0..grid_weight {
//                 if grid[h][w] == 1 {
//                     // BFS
//                     d.push_back((h, w));
//                     let mut cnt: i32 = 0;
//                     while !d.is_empty() {
//                         let (ph, pw) = d.pop_front().unwrap();
//                         //println!("{} {}", ph, pw);
//                         if grid[ph][pw] == 0 || visited[ph][pw] {
//                             continue;
//                         }
//                         cnt += 1;
//                         visited[ph][pw] = true;
//                         if ph > 0 {
//                             d.push_back((ph-1, pw));
//                         }
//                         if ph + 1 < grid_height {
//                             d.push_back((ph+1, pw));
//                         }
//                         if pw > 0 {
//                             d.push_back((ph, pw-1));
//                         }
//                         if pw + 1 < grid_weight {
//                             d.push_back((ph, pw+1))
//                         }
//                     }
//                     max = std::cmp::max(max, cnt);
//                 }
//             }
//         }
//         max
//     }
// }
