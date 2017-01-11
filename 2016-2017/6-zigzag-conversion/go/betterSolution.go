func convert(s string, numRows int) string {
    l := len(s)
    if l <= 2 || numRows <= 1 {
        return s
    }
    zigZagCycle := (numRows - 1) * 2 // 一次zigzag的长度，找出其中循环规律的长度
    var buffer bytes.Buffer
    for row:=0; row<numRows; row++{
    	if row == 0 || row == numRows - 1  {
    		for originIndex:=row; originIndex<l; originIndex+=zigZagCycle {
    			buffer.WriteString(string(s[originIndex]))			
    		}
    	} else {
    		for originIndex:=row; originIndex<l; originIndex+=zigZagCycle {
    			buffer.WriteString(string(s[originIndex]))	
    			siblingIndex := originIndex + zigZagCycle - 2 * row
    			if siblingIndex < l {
    				buffer.WriteString(string(s[siblingIndex]))				
    			}    			
    		}
    	}
    }
    return buffer.String()
}