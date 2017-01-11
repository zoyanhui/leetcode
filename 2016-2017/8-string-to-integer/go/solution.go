func myAtoi(str string) int {
    l := len(str)
    if l == 0 {
        return 0
    }
    i := 0
    for str[i] == ' ' {
        i++
    }
    negative := false
    if str[i] == '-' {
        negative = true
        i++
    } else if str[i] == '+'{
        i++
    }
    INT_MAX := 2147483647
    INT_MIN := -2147483648
    result := 0 
    head := true
    for ; i < l; i++ {
        cur := int(str[i] - '0')
        if cur < 0 || cur > 9 {
            if head{
                continue
            } else{
                break
            }
        }
        head = false
        
        if negative {
            if INT_MIN / 10 > result || INT_MIN + cur > result * 10 {
                return INT_MIN
            }
            result = result * 10 - cur
        } else {
            if INT_MAX / 10 < result || INT_MAX -cur < result * 10 {
                return INT_MAX
            }
            result = result * 10 + cur
        }
    }
    return result
}