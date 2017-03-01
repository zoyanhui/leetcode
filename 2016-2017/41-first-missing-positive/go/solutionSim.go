func firstMissingPositive(nums []int) int {
    l := len(nums)
    for idx := 0;idx < l;idx++ {
        cur := nums[idx]
        for cur >= 0 && cur < l && cur != idx+1 {
            temp:=nums[cur-1]
            nums[cur-1] = cur
            cur = temp
        }
    }
    for i, n := range nums {
        if n != i+1 {
            return i+1
        }
    }
    return l+1
}