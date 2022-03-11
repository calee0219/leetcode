impl Solution {
    pub fn interval_intersection(first_list: Vec<Vec<i32>>, second_list: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        fn intersection(first: Vec<i32>, second: Vec<i32>) -> (Vec<i32>, usize, usize) {
            if second[1] > first[1] {
                (vec![second[0], first[1]], 1, 0)
            } else if second[1] < first[1] {
                (vec![second[0], second[1]], 0, 1)
            } else {
                (vec![second[0], first[1]], 1, 1)
            }
        }
        let (mut first_idx, mut second_idx) = (0, 0);
        let mut ptr = 0;
        let mut ret = Vec::new();
        while first_idx < first_list.len() && second_idx < second_list.len() {
            if first_list[first_idx][0] <= second_list[second_idx][0]
            && first_list[first_idx][1] >= second_list[second_idx][0] {
                let (tmp, f, s) = intersection(first_list[first_idx].clone(), second_list[second_idx].clone());
                first_idx += f;
                second_idx += s;
                ret.push(tmp);
                continue;
            }
            if second_list[second_idx][0] <= first_list[first_idx][0]
            && second_list[second_idx][1] >= first_list[first_idx][0] {
                let (tmp, s, f) = intersection(second_list[second_idx].clone(), first_list[first_idx].clone());
                first_idx += f;
                second_idx += s;
                ret.push(tmp);
                continue;
            }
            if first_list[first_idx][0] < second_list[second_idx][0] {
                first_idx += 1;
            } else {
                second_idx += 1;
            }
        }
        ret
    }
}
