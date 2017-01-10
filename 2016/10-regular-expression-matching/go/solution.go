func isMatch(s string, p string) bool {
    ls := len(s)
    lp := len(p)
    return isMatch_r(s, p, 0, 0, ls, lp)
}

func isMatch_r(s string, p string, ss int, sp int, ls int, lp int) bool {
    i := sp
    j := ss    
    if i<lp && j<ls {
        if s[j] == p[i] || p[i] == '.' {
            if i+1 >= lp || p[i+1] != '*'  {
                return isMatch_r(s, p, j+1, i+1, ls, lp)
            } else {
                if isMatch_r(s, p, j+1, i+2, ls, lp){
                    return true
                }
                if isMatch_r(s, p, j, i+2, ls, lp){
                    return true
                }
                return isMatch_r(s, p, j+1, i, ls, lp)
            }
        } else if i+1 < lp && p[i+1] == '*' {
            return isMatch_r(s, p, j, i+2, ls, lp)
        } else {
            return false
        }
    }else if i<lp && j >= ls {
        for i < lp {
            if i+1 >= lp || p[i+1] != '*' {
                return false
            }
            i += 2
        }
        return true
    } else if i >= lp && j < ls {
        return false
    } else {
        return true
    }
}