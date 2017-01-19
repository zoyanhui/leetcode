func generateParenthesis(n int) []string {
    result := []string{""}
    vals:= []int{0}
    for i:=0; i<n; i++{
        for idx, r := range result {
            r += "("
            vals[idx] += 1
            result[idx] = r
            if i == n-1 {
                for j:=0; j<vals[idx]; j++{
                    r += ")"
                }
                result[idx] = r
            }else {
                for j:=0; j<vals[idx]; j++{
                    r += ")"
                    result = append(result, r)
                    vals = append(vals, vals[idx] - 1 -j)
                }
            }
        }
    }
    return result
}