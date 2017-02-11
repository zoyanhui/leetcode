func strStr(haystack string, needle string) int {
    if len(haystack) == 0 {
        if len(needle) == 0{
            return 0
        } else {
            return -1
        }
    }
    if len(needle) == 0{
        return 0
    }
    for i:=0;i<=len(haystack)-len(needle);{
        if haystack[i] != needle[0] {
            i++
            continue
        }
        j := i+1
        m := 1
        for j < len(haystack) && m < len(needle) {
            if haystack[j] != needle[m] {
                i = j + 1
                break
            }
            j++
            m++
        }
        if m == len(needle) {
            return i
        }
    }   
    return -1
}