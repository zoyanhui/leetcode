func solveSudoku(board [][]byte)  {
    rows := [9][9]bool{}
    cols := [9][9]bool{}
    blocks := [9][9]bool{}
    forward := [81]int{}
    backtrack := [81]int{}
    first := -1
    pre := -1
    for r:=0;r<9;r++ {
        for c:=0;c<9;c++ {
            if board[r][c] == '.' {
                cur := r*9+c
                if first < 0 {
                    first = cur
                }
                backtrack[cur] = pre
                if pre >= 0 {
                    forward[pre] = cur
                }
                pre = cur
                continue
            }
            b := 3 * (r / 3) + c / 3
            val := board[r][c] - '0' - 1
            rows[r][val] = true
            cols[c][val] = true
            blocks[b][val] = true
        }
    }
    forward[pre] = -1
    cur := first
    for cur >= 0 {
        r := cur / 9 
        c := cur % 9 
        b := 3 * (r / 3) + c / 3
        val := board[r][c] - '0' - 1
        if board[r][c] == '.' {
            val = 0
        } else {
            rows[r][val] = false
            cols[c][val] = false
            blocks[b][val] = false
            val++
        }
        if val >= 9 {
            board[r][c] = '.'
            cur = backtrack[cur]
            continue
        } 
        for val < 9 && (rows[r][val] || cols[c][val] || blocks[b][val]) {
            val++
        }
        if val >= 9{
            board[r][c] = '.'
            cur = backtrack[cur]
            continue
        }
        board[r][c] = '0' + 1 + val
        rows[r][val] = true
        cols[c][val] = true
        blocks[b][val] = true
        cur = forward[cur]
        
    }
    
}