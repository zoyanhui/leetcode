import "bytes"

func intToRoman(num int) string {
    romans_1000 := []string{"", "M", "MM", "MMM"}
    romans_100 := []string{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
    romans_10 := []string{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
    romans_1 :=  []string{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
    romans := [][]string{romans_1000, romans_100, romans_10, romans_1}
    var result bytes.Buffer
    base := 1000
    i := 0
    for base > 0 {
        n := num / base
        result.WriteString(romans[i][n])
        num %= base
        base /= 10
        i++
    }
    return result.String()
}


// or

func intToRoman(num int) string {
    romans_1000 := []string{"", "M", "MM", "MMM"}
    romans_100 := []string{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
    romans_10 := []string{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
    romans_1 :=  []string{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
    return romans_1000[num/1000] + romans_100[(num%1000)/100] + romans_10[(num%100)/10] + romans_1[num%10];
}