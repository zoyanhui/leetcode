// time limit extended

func isMatch(s string, p string) bool {
    return match(s, p, 0, 0)
}

func match(s string, p string, sidx int, pidx int) bool {
    if sidx == len(s) && pidx == len(p) {
        return true
    }
    
    if sidx < len(s) && pidx < len(p) {
        if p[pidx] == '?' || p[pidx] == s[sidx] {
            return match(s, p, sidx+1, pidx+1)
        }
        if p[pidx] == '*' {
            for pidx < len(p) && p[pidx] == '*' {
                pidx++
            }
            pidx--
            if match(s, p, sidx, pidx+1) {
                return true
            }
            if match(s, p, sidx+1, pidx) {
                return true
            }
            return false
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