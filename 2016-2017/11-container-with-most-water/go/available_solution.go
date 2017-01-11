func maxArea(height []int) int {
    n := len(height)
    max:=0
    next := make([]int, n)
    for i:=0; i<n;  {
        next[i] = 0
        for j := i+1; j <n; j++ {
            var cur int
            if height[j] >= height[i] {
                if next[i] == 0 {
                    next[i] = j
                }
                cur = (j - i) * height[i]
            } else {
                cur = (j - i) * height[j]
            }
            if cur > max {
                max = cur
            }
        }
        if next[i] > 0 {
            i = next[i]
        }else{
            i++
        }
    }
    return max
}