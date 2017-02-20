import (
    "fmt"
    "strings"
)

func findSubstring(s string, words []string) []int {
    var resultIdx []int
    checkIdx := make(map[int]bool)
    checkWord := make(map[string]bool)
    for wIdx, word := range words {
        if _, ok := checkWord[word]; ok{
            continue
        }
        checkWord[word] = true
        start := 0
        idx := strings.Index(s[start:], word)
        for idx >= 0 {
            idx += start
             if _, ok := checkIdx[start]; !ok{
                swap(words, 0, wIdx)
                findSubstr(s, idx, idx + len(word), words, 1, &resultIdx)
                swap(words, wIdx, 0)  
                checkIdx[start] = true
            }
            start = idx+1
            idx = strings.Index(s[start:], word)
        }
    }
    return resultIdx
}

func swap(words []string, i int, j int) {
    temp := words[i] 
    words[i] = words[j]
    words[j] = temp
}

func findSubstr(s string, start int, curStart int, words []string, wIdx int, resultIdx *[]int) {
    n := len(words)
    if n == wIdx{
        *resultIdx = append(*resultIdx, start)
        return
    } 
    if (n - wIdx) * len(words[0]) > len(s) - curStart || wIdx >= n{
        return
    }
    checkWord := make(map[string]bool)
    for nWIdx := wIdx; nWIdx < n;  nWIdx++ {
        word := words[nWIdx]
        if _, ok := checkWord[word]; ok{
            continue
        }
        checkWord[word] = true
        if s[curStart:curStart+len(word)] == word {
            swap(words, wIdx, nWIdx)
            findSubstr(s, start, curStart + len(word), words, wIdx+1, resultIdx)
            swap(words, nWIdx, wIdx)
        }
       
    }
} 