func longestValidParentheses(s string) int {
    var leftIdx []int
    rightIdx := make([]int, len(s))
    var startIdx []int
    for idx, c := range s {
        if c == '(' {
            leftIdx = append(leftIdx, idx)
        } else {
            rIdx := -1
            l := len(leftIdx)
            if l > 0 {
                lIdx := leftIdx[l-1]
                leftIdx = leftIdx[:l-1]
                rIdx = idx
                startIdx = append(startIdx, lIdx)
            }
            rightIdx[idx] = rIdx
        }
    }
    for _, l := range leftIdx {
        rightIdx[l] = -1
    }
    maxPairLen := 0
    curStart := -1
    curEnd := 0
    fmt.Println(rightIdx)
    fmt.Println(startIdx)
    lIdx := 0
    for _, i := range rightIdx {
        if i == -1 {
            if curStart >= 0 && curEnd > curStart {
                curLen := curEnd - curStart + 1
                if curLen > maxPairLen {
                    maxPairLen = curLen
                }
            } 
            curStart = -1
            curEnd = 0
        } else if i == 0 {
            continue
        } else {
            if curStart < 0 {
                curStart = startIdx[lIdx]
                lIdx++
                curEnd = i
            } else{
                if curStart > startIdx[lIdx] {
                    curStart = startIdx[lIdx]
                }
                curEnd = i
                lIdx++
            }
        }
    }
    if curStart >= 0 {
        curLen := curEnd - curStart + 1
        if curLen > maxPairLen {
            maxPairLen = curLen
        }
    }
    return maxPairLen
}