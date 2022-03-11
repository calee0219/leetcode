impl Solution {
    pub fn check_straight_line(coordinates: Vec<Vec<i32>>) -> bool {
        for idx in 2..coordinates.len() {
            if (coordinates[idx][0] - coordinates[idx-1][0]) *
               (coordinates[idx-1][1] - coordinates[idx-2][1]) !=
               (coordinates[idx][1] - coordinates[idx-1][1]) *
               (coordinates[idx-1][0] - coordinates[idx-2][0]) {
                   return false;
            }
        }
        true
    }
}