// This code is simple, but time complexity is bigger, may time limit extended

func longestValidParentheses(s string) int {
    maxLen := 0
    n := len(s)
    for i:=0;i<n;i++ {
        count := 0
        for j:=i;j<n;j++{
            if s[j] == '(' {
                count ++
            } else {
                if count <= 0{
                    break
                } else{
                    count--    
                }
            }
            if count == 0 {
                curLen := j - i + 1
                if maxLen < curLen {
                    maxLen = curLen
                }
            }
        }
    }
    return maxLen
}

// improve above code to:
func longestValidParentheses(s string) int {
    maxLen := 0
    n := len(s)
    count := 0
    start := -1
    for i:=0;i<n;i++ {
        if s[i] == '(' {
            count ++
        } else {
            count--
        }
        if count == 0 {
            curLen := i - start
            if maxLen < curLen {
                maxLen = curLen
            }
        } else if count < 0 {
            count = 0
            start = i
        }
    }
    count = 0
    start = n
    for i:=n-1;i>=0;i-- {
        if s[i] == '(' {
            count ++
        } else {
            count--
        }
        if count == 0 {
            curLen := start - i
            if maxLen < curLen {
                maxLen = curLen
            }
        } else if count > 0 {
            count = 0
            start = i
        }
    }
    return maxLen
}