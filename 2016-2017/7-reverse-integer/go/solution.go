func reverse(x int) int {
    negative := false
    if x < 0 {
        negative = true
        x = -x
    }
    INT_MAX := 2147483647
    result := 0
    for x > 0 {
        cur := x%10
        if INT_MAX / 10 < result || INT_MAX - cur < result * 10{
            return 0
        }
        result = result * 10 + x % 10
        x /= 10
    }
    if negative{
        return -result
    }
    return result
}