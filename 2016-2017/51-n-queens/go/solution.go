func solveNQueens(n int) [][]string {
    s := make([]rune, n)
    for i:=0;i<n;i++{
        s[i] = '.'
    }
    colFilled := make([]bool, n)
    leftFilled := make([]bool, n*2-1) // diagonal skew line, right to left
    rightFilled := make([]bool, n*2-1) // diagonal skew line, left to right
    var ret [][]string
    solveNQueensRecursive(n, 0, []string{}, colFilled, leftFilled, rightFilled, &ret, s)
    return ret
}


func solveNQueensRecursive(n int, curidx int, curlist []string, colFilled []bool, leftFilled []bool, rightFilled []bool, ret *[][]string, constRow []rune)  {
    if len(curlist) == n {
        copylist := make([]string, len(curlist))
        copy(copylist, curlist)
        *ret = append(*ret, copylist)
        return
    }
    for i:=0;i<n;i++{
        if colFilled[i] || leftFilled[curidx+i] || rightFilled[n-1-curidx+i] {
            continue
        }
        colFilled[i] = true
        leftFilled[curidx+i]= true
        rightFilled[n-1-curidx+i] = true
        copyRow := make([]rune, n)
        copy(copyRow, constRow)
        copyRow[i] = 'Q'
        s := string(copyRow)
        solveNQueensRecursive(n, curidx + 1, append(curlist, s), colFilled, leftFilled, rightFilled, ret, constRow)
        colFilled[i] = false
        leftFilled[curidx+i]= false
        rightFilled[n-1-curidx+i] = false
    }
    
}