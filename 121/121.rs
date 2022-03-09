impl Solution {
    // functional version
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        prices.iter().skip(1).fold((0, prices[0]), |(profit, min), &price| {
            (std::cmp::max(profit, price-min), std::cmp::min(min, price))
        }).0 as _
    }
    // normal version
    // pub fn max_profit(prices: Vec<i32>) -> i32 {
    //     let mut min = prices[0];
    //     let mut profit = 0;
    //     for &p in prices.iter().skip(1) {
    //         profit = std::cmp::max(profit, p-min);
    //         min = std::cmp::min(min, p);
    //     }
    //     profit
    // }
}