type Stack []rune

func (s Stack) Push(v rune) Stack {
    return append(s, v)
}

func (s Stack) Pop() (Stack, rune) {
    l := len(s)
    if l == 0 {
        return s, '_'
    }
    return  s[:l-1], s[l-1]
}


func isValid(s string) bool {
    var stack Stack
    var r rune
    for _, c := range s {
        if c == '(' || c == '{' || c == '[' {
            stack = stack.Push(c)
        } else {
            stack, r = stack.Pop()
            if c == ')' && r != '(' {
                return false
            }
            if c == '}' && r != '{' {
                return false
            }
            if c == ']' && r != '[' {
                return false
            }
        }
    }
    return len(stack) == 0
}