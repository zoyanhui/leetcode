// 使用动态规划
// 从长度为1的子串开始，一直遍历到长度为len(s)
func longestPalindrome(s string) string {
    l := len(s)
    if l <=1 {
        return s
    }
    var recf [][]int // 动态规划中记录矩阵
    for i :=0; i < l; i++ {
        var tempArr []int
        for j:=0; j < l; j++ {
            if i == j {
                tempArr = append(tempArr, 1)   
            } else {
                tempArr = append(tempArr, 0)   
            }
        }
        recf = append(recf, tempArr)
    }
    maxPlen := 1
    maxPStart :=0
    maxPEnd := 0
    for curlen := 2; curlen<=l; curlen++{
        for start:=0; start<l; start++{
            end := start + curlen - 1
            if end >= l{
                break
            }
            if curlen == 2{
                if s[start] == s[end] {
                    recf[start][end] = 1
                    if curlen > maxPlen {
                        maxPlen = curlen
                        maxPStart, maxPEnd = start, end
                    }
                } else {
                    recf[start][end] = 0
                }
                continue
            }
            if recf[start + 1][end - 1] == 1 && s[start] == s[end]{
                 recf[start][end] = 1
                 if curlen > maxPlen {
                    maxPlen = curlen
                    maxPStart, maxPEnd = start, end
                 }
            } else {
                recf[start][end] = 0
            }
        }
    }
    return s[maxPStart:maxPEnd+1]
}