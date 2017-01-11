// 递归的方法，Time Limit Exceeded

func longestPalindrome(s string) string {
    l := len(s)
    if l <=1 {
        return s
    }
    paliStr, _ := longestPalindromeRecursive(&s, 0, l-1)
    return paliStr
}

func longestPalindromeRecursive(s *string, start int, end int) (string, bool) {
    if end < start {
        return "", true
    }
    if end - start == 0 {
        return (*s)[start:end+1], true
    }
    var maxPalindrome string
    maxLen := 0
    if (*s)[start] == (*s)[end] {
        if tempStr, isPanl := longestPalindromeRecursive(s, start + 1, end - 1); isPanl {
            return (*s)[start:end+1], true
        }else{
            maxPalindrome, maxLen = tempStr, len(tempStr)
        }
    }
    var tempStr string
    if tempStr, _ = longestPalindromeRecursive(s, start, end - 1); len(tempStr) > maxLen {
        maxPalindrome, maxLen = tempStr, len(tempStr)
    }
    if tempStr, _ = longestPalindromeRecursive(s, start + 1, end); len(tempStr) > maxLen {
        maxPalindrome, maxLen = tempStr, len(tempStr)
    }
    return maxPalindrome, false
}