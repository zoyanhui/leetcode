func isValidSudoku(board [][]byte) bool {
    rows := [9][9]bool{}
    cols := [9][9]bool{}
    blocks := [9][9]bool{}
    for r:=0;r<9;r++ {
        for c:=0;c<9;c++ {
            if board[r][c] == '.' {
                continue
            }
            val := board[r][c] - '0' - 1
            b := 3 * (r / 3) + c / 3 
            if rows[r][val] || cols[c][val] || blocks[b][val] {
                return false
            }
            rows[r][val] = true
            cols[c][val] = true
            blocks[b][val] = true
        }
    }
    return true
}