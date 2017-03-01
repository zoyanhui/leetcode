func firstMissingPositive(nums []int) int {
    l := len(nums)
    idx := 0
    for idx < l {
        cur := idx
        n := -1
        for cur >= 0 && cur < l {
            tempn := nums[cur]
            if n > 0 {
                nums[cur] = n
            }
            n = tempn
            if n == cur + 1{
                break
            }
            cur = n-1
        }
        idx++
    }
    for i, n := range nums {
        if n != i+1 {
            return i+1
        }
    }
    return l+1
}