func isPalindrome(x int) bool {
    if x < 0 {
        return false
    } 
    reverseLittle := 0
    for x > reverseLittle{
        reverseLittle *= 10
        reverseLittle *= x % 10
        x /= 10
    }
    return (x == reverseLittle) || (reverseLittle/10 == x)
}