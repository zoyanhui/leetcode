func longestCommonPrefix(strs []string) string {
    minLen := -1
    for _, str := range strs {
        l := len(str)
        if l < minLen || minLen < 0 {
            minLen = l
        }
    }
    if minLen <= 0 {
        return ""
    }
    i := 0
    for ; i < minLen; i++ {
        equal := true
        now := strs[0][i]
        for j:=1; j < len(strs); j++ {
            if strs[j][i] != now {
                equal = false
                break
            }
        }
        if !equal {
            break
        }
    }
    if i == 0{
        return ""
    }
    return strs[0][:i]
}