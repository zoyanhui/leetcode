func countAndSay(n int) string {
    cur := "1"
    for n > 1 {
        pre := cur
        count := 0
        var buffer bytes.Buffer
        c := rune(pre[0])
        for _, x := range pre {
            if x == c {
                count ++
            } else {
                buffer.WriteRune(rune(count) + rune('0') )
                buffer.WriteRune(c)
                count = 1
                c = x
            }
        }
        buffer.WriteRune(rune(count) + rune('0') )
        buffer.WriteRune(c)
        cur = buffer.String()
        n--
    }
    return cur
}