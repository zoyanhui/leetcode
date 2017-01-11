// 91 / 91 test cases passed.
// Status: Accepted
// Runtime: 3 ms

func longestPalindrome(s string) string {
    l := len(s)
    if l <=1 {
        return s
    }
    start := 0
    maxLen := 1
    for center := 0; center < l; {
        if l - center < maxLen / 2 {
            break
        }
        left := center
        right := center
        for right < l-1 && s[right] == s[right+1] { // make all characters the same as center to be a bigger center
            right++
        }
        center = right + 1 // next loop's center is next to right,  no need to check duplicate character again in old center
        for left >= 0 && right <= l -1 && s[left] == s[right] {  // expand from center, odd or even length it's up to left and right
            left--
            right++
        }
        curLen := right - left
        if curLen > maxLen {
            maxLen = curLen
            start = left+1
        }
    }
    return s[start:start+maxLen-1]
}