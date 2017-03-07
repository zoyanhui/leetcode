func myPow(x float64, n int) float64 {
    if n < 0{
        n =-n
        x = 1.0/x
    }
    var ret float64
    ret = 1
    for n >= 1 {
        if n & 1 == 1 {
            ret *= x
        } 
        x *= x
        n /= 2
    }
    return ret
}