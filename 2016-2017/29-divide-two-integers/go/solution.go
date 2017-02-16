func divide(dividend int, divisor int) int {
    MAX_INT := 1<<31 - 1
    MIN_INT := -1<<31
    fmt.Println(MIN_INT)
    if divisor == 0 || (dividend == MIN_INT && divisor == -1) {
        return MAX_INT
    }   
    ret := 0
    positive := true
    if dividend < 0 {
        positive = !positive
        dividend = -dividend
    }
    if divisor < 0 {
        positive = !positive
        divisor = -divisor
    }
    for dividend >= divisor {
        multiDivisor := divisor << 1
        multi := 1
        for dividend >= multiDivisor {
            multi <<= 1
            multiDivisor <<= 1
        }
        dividend -= multiDivisor >> 1
        ret += multi
    }
    if positive {
        return ret
    } else {
        return -ret
    }
}