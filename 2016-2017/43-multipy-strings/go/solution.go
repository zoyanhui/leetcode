import "bytes"
func multiply(num1 string, num2 string) string {
    maxn := len(num1) + len(num2)
    ret := make([]int, maxn)
    for i:=len(num1)-1;i>=0;i--{
        int1 := (int)(num1[i] - '0')
        for j:=len(num2)-1;j>=0;j--{
            int2 := (int)(num2[j] - '0')
            r := int1 * int2 + ret[i+j+1]
            ret[i+j+1] = r % 10
            ret[i+j] += r/10
            
        }
    }
    var retstr bytes.Buffer
    beginning := true
    for _, i:= range ret {
        if i==0 && beginning{
            continue
        }
        beginning = false
        retstr.WriteRune((rune)(i + '0'))
    }
    if retstr.Len() == 0 {
        return "0"
    }
    return retstr.String()
}