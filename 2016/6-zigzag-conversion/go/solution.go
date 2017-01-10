// O(n) time, O(1) space solution
// but code is not simple

func convert(s string, numRows int) string {
    l := len(s)
    if l <= 2 || numRows == 1 {
        return s
    }
    var buffer bytes.Buffer
    buffer.WriteString(string(s[0]))
    preTotalNum := 0
    curRowNum := zaggRowNum(1, l, numRows)
    curRowIndex := 1
    for i := 1; i<l;  {
        originIndex := 0
        curZagg := i - preTotalNum
        if curRowIndex == 1 && i <= curRowNum{
            curZagg *= 2
            originIndex = curZagg * (numRows - 1)
        } else if curRowIndex == numRows {
            curZagg = curZagg * 2 - 1
            originIndex = curZagg * (numRows - 1)
        } else if curZagg <= curRowNum{
            if curZagg % 2 == 0 {
                originIndex = (curZagg-1) * (numRows - 1) + numRows - curRowIndex  
            } else {
                originIndex = (curZagg-1) * (numRows - 1) + curRowIndex - 1
            }
        } else{
            curRowIndex ++
            preTotalNum += curRowNum
            curRowNum = zaggRowNum(curRowIndex, l, numRows)
            continue
        }
        // fmt.Println("index: ", originIndex)
        buffer.WriteString(string(s[originIndex]))    
        i++
    }
    // fmt.Println("#######################")
    return buffer.String()
}


func zaggRowNum(rowIndex int, total int, numRows int) int {
    zaggs := (total-1 ) / (numRows-1)
    if rowIndex == 1 {  // based one
        return zaggs / 2
    }
    if rowIndex == numRows {
        return (zaggs + 1) / 2
    }
    remain := (total -1) % (numRows-1)
    if zaggs % 2 == 0 {
        if remain >= rowIndex - 1 {
            return zaggs + 1
        }    
        return zaggs
    } else {
        if remain >= numRows - rowIndex {
            return zaggs + 1
        }    
        return zaggs
    }
    
}