func pow(base int, tens int) int {
    result := 1
    for i:=0;i<tens;i++{
        result *= base
    }
    return result
}

func isPalindrome(x int) bool {
    if x < 0 {
        return false
    } 
    numbers := 0
    temp := x
    for temp > 0 {
        temp /= 10
        numbers ++
    }
    bits := numbers/2
    for i:=0; i<bits && x > 0; i++{
        p := pow(10, numbers - 1)
        left := x / p
        remain := x % p
        right := x % 10
        if left != right {
            return false
        }
        x = remain / 10
        numbers -= 2
    }
    return true
}