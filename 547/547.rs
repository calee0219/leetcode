impl Solution {
    pub fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {
        // let mut disjoin = [0;  is_connected.len()];
        let mut disjoin = vec![Default::default(); is_connected.len()];
        for idx in 0..is_connected.len() {
            disjoin[idx] = idx;
        }
        for r in 0..is_connected.len() {
            for c in 0..is_connected.len() {
                if r >= c {
                    continue;
                }
                if is_connected[r][c] == 1 {
                    // println!("{} {}", r, c);
                    let mut r_head = r;
                    let mut c_head = c;
                    while disjoin[r_head] != r_head {
                        r_head = disjoin[r_head];
                    }
                    while disjoin[c_head] != c_head {
                        c_head = disjoin[c_head];
                    }
                    disjoin[c_head] = r_head;
                    // println!("{:?}", disjoin);
                }
            }
        }
        // println!("{:?}", disjoin);
        let mut sum = 0;
        for idx in 0..is_connected.len() {
            if disjoin[idx] == idx {
                sum += 1;
            }
        }
        sum
    }
}