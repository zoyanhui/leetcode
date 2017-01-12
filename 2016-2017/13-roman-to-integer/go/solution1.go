func romanToInt(s string) int {
    romanMap := map[string]int{  
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}  
    n := len(s)
    result := 0
    for i:=0; i<n; i++{
        if s[i] == 'I' {
            if i+1 < n && (s[i+1] == 'V' || s[i+1] == 'X') {
                result -= 1
            } else {
                result += 1
            }
        } else if s[i] == 'X' {
            if i+1 < n && (s[i+1] == 'L' || s[i+1] == 'C') {
                result -= 10
            } else {
                result += 10
            }
        } else if s[i] == 'C' {
            if i+1 < n && (s[i+1] == 'D' || s[i+1] == 'M') {
                result -= 100
            } else {
                result += 100
            }
        } else {
            result += romanMap[string(s[i])]
        }
    }
    return result
}