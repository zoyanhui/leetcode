// this solution has no enough precision (degree of accuracy) for float

func myPow(x float64, n int) float64 {
    if n == 0 {
        return 1
    }
    if x == 0 {
        return 0
    }
    if n < 0{
        n =-n
        x = 1.0/x
    }
    var ret float64
    ret = x
    for n > 1 {
        ret *= ret
        if n & 1 == 1 {
            ret *= x
        } 
        n /= 2
    }
    return ret
}