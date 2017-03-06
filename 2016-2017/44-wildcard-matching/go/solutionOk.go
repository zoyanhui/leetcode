func isMatch(s string, p string) bool {
    return match(s, p, 0, 0)
}

func match(s string, p string, sidx int, pidx int) bool {
    fmt.Println(sidx, pidx)
    if sidx == len(s) && pidx == len(p) {
        return true
    }
    
    if sidx < len(s) && pidx < len(p) {
        if p[pidx] == '?' || p[pidx] == s[sidx] {
            return match(s, p, sidx+1, pidx+1)
        }
        if p[pidx] == '*' {
            skip := 0
            for pidx < len(p) {
                if p[pidx] == '*' {
                    pidx++  
                } else if p[pidx] == '?' {
                    pidx++
                    skip++
                } else {
                    break
                }
            }
            sidx += skip
            for sidx < len(s) && pidx < len(p)  {
                if s[sidx] != p[pidx] {
                    sidx++
                } else {
                    if match(s,p,sidx+1, pidx+1) {
                        return true
                    } else {
                        sidx++
                    }
                }
            }
            if sidx <= len(s) {
                if pidx >= len(p) {
                    return true
                }
                return match(s,p,sidx+1, pidx+1)
            } else {
                return false
            }
        }
        return false
    } else if sidx == len(s) {
        for i:=pidx;i<len(p);i++{
            if p[i] != '*' {
                return false
            }
        }
        return true
    } else {
        return false
    }
}