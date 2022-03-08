impl Solution {
    pub fn subtract_product_and_sum(n: i32) -> i32 {
        let mut m = n;
        let mut sum = 0;
        let mut product = 1;
        while m != 0 {
            sum += m % 10;
            product *= m % 10;
            m /= 10;
        }
        product - sum
    }
}