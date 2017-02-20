func findSubstring(s string, words []string) []int {
    var resultIdx []int
    wordsSize := len(words)
    if wordsSize == 0 {
        return resultIdx
    }
    wordLen := len(words[0])
    wordDict := make(map[string]int)
    for _, w := range words {
        wordDict[w]++
    }
    start := 0
    for start < len(s) - wordLen * wordsSize + 1 {
        word := s[start:start+wordLen]
        if _, ok := wordDict[word]; ok{
            curDict := make(map[string]int)
            curDict[word] = 1
            countWord := 1
            curStart := start+wordLen
            for countWord < wordsSize {
                word = s[curStart:curStart+wordLen]
                curDict[word]++
                c, in := wordDict[word]
                if !in || curDict[word] > c {
                    break
                }
                curStart += wordLen
                countWord++
            }
            if countWord == wordsSize {
                resultIdx = append(resultIdx, start)
            }
        }
        start++
    }
    return resultIdx
}