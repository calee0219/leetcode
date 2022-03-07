impl Solution {
    pub fn get_ancestors(n: i32, edges: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut graph: Vec<Vec<i32>> = vec![vec![]; n as usize];
        for e in edges.iter() {
            graph[e[1] as usize].push(e[0]);
        }
        let mut ans: Vec<Vec<i32>> = vec![];
        // bfs
        for idx in 0..n {
            let mut tmp: Vec<i32> = vec![];
            let mut visit: Vec<bool> = vec![false; n as usize];
            let mut queue = std::collections::VecDeque::new();
            for i in 0..graph[idx as usize].len() {
                if !visit[graph[idx as usize][i] as usize] {
                    tmp.push(graph[idx as usize][i]);
                    queue.push_back(graph[idx as usize][i]);
                    visit[graph[idx as usize][i] as usize] = true;
                }
            }
            while !queue.is_empty() {
                let c = queue.pop_front().unwrap();
                for i in 0..graph[c as usize].len() {
                    if !visit[graph[c as usize][i] as usize] {
                        queue.push_back(graph[c as usize][i]);
                        tmp.push(graph[c as usize][i]);
                        visit[graph[c as usize][i] as usize] = true;
                    }
                }
            }
            
            tmp.sort();
            ans.push(tmp);
        }
        ans
    }
}