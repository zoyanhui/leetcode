func solveNQueens(n int) [][]string {
    s := make([]rune, n)
    for i:=0;i<n;i++{
        s[i] = '.'
    }
    board := make([]string, n)
    for i:=0;i<n;i++{
        copyRow := make([]rune, n)
        copy(copyRow, s)
        board[i] = string(copyRow)
    }
    var ret [][]string
    solveNQueensRecursive(n, 0, board, &ret)
    return ret
}


func solveNQueensRecursive(n int, curRow int, board []string, ret *[][]string )  {
    if curRow == n {
        copyBoard := make([]string, len(board))
        copy(copyBoard, board)
        *ret = append(*ret, copyBoard)
        return
    }
    for i:=0;i<n;i++{
        if !isValid(board, curRow, i, n) {
            continue
        }
        temp := ([]rune)(board[curRow])
        temp[i] = 'Q'
        board[curRow] = string(temp)
        solveNQueensRecursive(n, curRow + 1, board, ret)
        temp[i] = '.'
        board[curRow] = string(temp)
    }
    
}

func isValid(board []string, curRow int, curCol int, n int) bool {
    for i:=0;i<curRow;i++{
        if board[i][curCol] == 'Q' {
            return false
        }
    }
    for i,j:=curRow-1,curCol-1;i>=0 && j>=0;i,j=i-1,j-1{
        if board[i][j] == 'Q' {
            return false
        }
    }
    for i,j:=curRow-1,curCol+1;i>=0 && j<n;i,j=i-1,j+1{
        if board[i][j] == 'Q' {
            return false
        }
    }
    return true
}