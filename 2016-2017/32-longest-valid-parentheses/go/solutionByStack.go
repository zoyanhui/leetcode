func longestValidParentheses(s string) int {
    stack := []int{-1}
    maxlen := 0
    for idx, val := range s {
        if val =='(' {
            stack = append(stack, idx)
        } else {
            stack = stack[:len(stack)-1]
            if len(stack) == 0 {
                stack = append(stack, idx)
            } else {
                curlen := idx - stack[len(stack) -1]
                if curlen > maxlen {
                    maxlen = curlen
                }
            }
        }
    }
    return maxlen
}