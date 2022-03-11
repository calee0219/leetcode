impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        fn tar(n: usize) -> usize {
	    n / 3
            // match n {
            //     0|1|2 => 0,
            //     3|4|5 => 1,
            //     6|7|8 => 2,
            //     _ => 3,
            // }
        }
        // using bit map to check if repeat
        // if n exist, save 1<<n to bit map, ex. 5 -> 00..0100000, 5 3 -> 0..0101000
        let mut check: [[u16; 9]; 3] = [[0; 9]; 3];
        // check[0] for row, check[1] for column, check[2] for sub-boxes
        // check row, column, sub-boxes at the same time
        for row in 0..9 {
            for col in 0..9 {
                if board[row][col] == '.' {
                    continue;
                }
                let bit: u16 = 1 << board[row][col] as u8 - '0' as u8;
                let box_idx = tar(row) * 3 + tar(col);
                if bit & check[0][row] != 0 ||
                   bit & check[1][col] != 0 ||
                   bit & check[2][box_idx] != 0 {
                    // println!("{} {}", row, col);
                    return false;
                }
                check[0][row] |= bit;
                check[1][col] |= bit;
                check[2][box_idx] |= bit;
            }
        }
        true
    }
}