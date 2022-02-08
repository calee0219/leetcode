struct Solution {}

impl Solution {
    fn _gcd(a: i32, b: i32) -> i32 {
        let mut _a = a;
        let mut _b = b;
        while _b != 0 {
            let _tmp: i32 = _b;
            _b = _a % _b;
            _a = _tmp;
        }
        return _a;
    }
    pub fn can_measure_water(jug1_capacity: i32, jug2_capacity: i32, target_capacity: i32) -> bool {
        return jug1_capacity + jug2_capacity >= target_capacity &&
            target_capacity % Solution::_gcd(jug1_capacity, jug2_capacity) == 0;
    }
}

fn main() {
    println!("{}", Solution::can_measure_water(7, 5, 3));
}
