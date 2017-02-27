func longestValidParentheses(s string) int {
    n := len(s)
    maxlen := 0
    dp := make([]int, n)
    for i:=1;i<n;i++ {
        if s[i] == ')' {
            if s[i-1] == '(' {
                if i >= 2 {
                    dp[i] = dp[i-2] + 2
                } else {
                    dp[i] = 2
                }
            } else {
                pre := i-1-dp[i-1]
                if pre >=0 && s[pre] == '(' {
                    cc := i-2-dp[i-1] 
                    if cc >= 0 {
                        dp[i] = dp[i-1] + 2 + dp[cc]
                    } else {
                        dp[i] = dp[i-1] + 2
                    }
                }
            }
            if dp[i] > maxlen {
                maxlen = dp[i]
            }
        }
    }
    return maxlen
}