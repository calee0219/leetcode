impl Solution {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        fn rec(start: i32, end: i32, k: i32, depth: i32, build: &mut Vec<i32>, save: &mut Vec<Vec<i32>>) {
            if depth == k {
                save.push(build.to_vec());
                return;
            }
            for i in start..=end {
                build.push(i);
                rec(i+1, end, k, depth+1, build, save);
                build.pop();
            }
        }
        let mut save: Vec<Vec<i32>> = vec![];
        rec(1, n, k, 0, &mut vec![], &mut save);
        save
    }
}
