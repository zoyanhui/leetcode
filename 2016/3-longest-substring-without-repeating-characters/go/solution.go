// Sliding Window, whose range indexed by start and end
// use a dict to record the position of appeared character
// every repeat character in sliding window, will resize the sliding window 
//   by jumping start to the next position of appeared character in dict

func lengthOfLongestSubstring(s string) int {
    idxMap := make(map[rune](int))
    start := 0
    end := -1
    maxLen := 0
    for idx, ele := range s {
        if oldIdx, ok := idxMap[ele]; ok{
            idxMap[ele] = idx
            if oldIdx >= start {
                curLen := end - start + 1
                if curLen > maxLen {
                    maxLen = curLen
                }
                start = oldIdx + 1
                end = idx
                continue
            }
        }else{
            idxMap[ele] = idx
        }
        end = idx
    }
    curLen := end - start + 1
    if curLen > maxLen {
        maxLen = curLen
    }
    return maxLen
}