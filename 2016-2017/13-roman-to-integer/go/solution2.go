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
        if i+1 < n && romanMap[string(s[i+1])] > romanMap[string(s[i])] {
            result -= romanMap[string(s[i])]
        } else {
            result += romanMap[string(s[i])]
        }
    }
    return result
}