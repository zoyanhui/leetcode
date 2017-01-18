func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }
    alphabetaArr := []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }
    result := []string{""}
    for _, c := range digits{
        num := int(c - '0')
        appends := alphabetaArr[num]
        if len(appends) == 0 {
            continue
        }
        var newResult []string
        for _, org := range result {
            for _, a := range appends {
                newResult = append(newResult, org + string(a))
            }
        }
        result = newResult
    }
    return result
}