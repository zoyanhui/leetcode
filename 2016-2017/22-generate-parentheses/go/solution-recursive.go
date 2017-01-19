func generateParenthesis(n int) []string {
    var result []string
    return generateParenthesisRecursive(result, "", n, 0)
}

func generateParenthesisRecursive(result []string, s string, n int, leftn int) []string{
    if n==0 && leftn == 0{
        result = append(result, s)
        return result
    }
    
    if leftn > 0{
        result = generateParenthesisRecursive(result, s + ")", n, leftn - 1)
    }
    if n > 0 {
        result = generateParenthesisRecursive(result, s + "(", n-1, leftn + 1)
    }
    return result
}


