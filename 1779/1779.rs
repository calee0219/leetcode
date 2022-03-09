impl Solution {
    pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32 {
        let mut distance = i32::MAX;
        let mut ans: i32 = -1;
        for (idx, point) in points.iter().enumerate() {
	    if point[0] == x || point[1] == y {
                let dis = (point[0] - x).abs() + (point[1] - y).abs();
                if distance > dis {
                    distance = dis;
                    ans = idx as i32;
                }
            }
            // if point[0] == x && (point[1] - y).abs() < distance {
            //     distance = (point[1] - y).abs();
            //     ans = idx as i32;
            // } else if point[1] == y && (point[0] - x).abs() < distance {
            //     distance = (point[0] - x).abs();
            //     ans = idx as i32;
            // }
        }
        ans
    }
}

// function solution
// impl Solution {
//     pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32 {
//         fn manhattan(loc: (i32, i32), point: (i32, i32)) -> i32 {
//             (loc.0 - point.0).abs() + (loc.1 - point.1).abs()
//         }
//         points
//         .iter()
//         .enumerate()
//         .filter(|&(_idx, p)| p[0] == x || p[1] == y)
//         .min_by(|&(_, a), &(_, b)| {
//             let m1 = manhattan((x, y), (a[0], a[1]));
//             let m2 = manhattan((x, y), (b[0], b[1]));
//             m1.cmp(&m2)
//         })
//         .map(|(idx, _)| idx as i32)
//         .unwrap_or(-1)
//     }
// }