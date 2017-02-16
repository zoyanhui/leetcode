func strStr(haystack string, needle string) int {
    pLen := len(needle)
    if pLen == 0 {
        return 0
    }
    if len(haystack) == 0 {
        return -1
    }
    next := make([]int, pLen)
    buildNext(needle, next)
    i := -1
    j := -1
    for i < pLen && j < len(haystack){
        if i == -1 || haystack[j] == needle[i] {
            i++
            j++
        } else {
            i = next[i]
        }
    }
    if i == pLen {
        return j - pLen
    }
    return -1
}


func buildNext(needle string, next []int) {
    pLen := len(needle)
    next[0] = -1
    k := -1
    j := 0
    for j < pLen - 1 {
        if k == -1 || needle[j] == needle[k] {
            j++
            k++
            // compare to kmpSolution, only here is changed
            if needle[j] != needle[k] {
                next[j] = k    
            } else {
                next[j] = next[k]   
            }
        } else {
            k = next[k]
        }
    }
}