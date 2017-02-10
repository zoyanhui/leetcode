func strStr(haystack string, needle string) int {
    nexti := -1
    for i:=0;i<=len(haystack)-len(needle);{
        if haystack[i] != needle[0] {
            if nexti < 0 {
                i++
            } else {
                i = nexti    
            }            
        }
        j := i+1
        m := 1
        for j < len(haystack) && m < len(needle) {
            if haystack[j] == haystack[i] {
                nexti = j
            }
            if haystack[j] != needle[m] {
                if i <= nexti {
                    i = nexti
                } else {
                    i = j + 1
                }
                break
            }
            j++
            m++
        }
        if j == len(haystack) && m == len(needle) {
            return i
        }
    }   
    return -1
}