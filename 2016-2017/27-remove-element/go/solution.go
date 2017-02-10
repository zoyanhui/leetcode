func removeElement(nums []int, val int) int {
    n := len(nums)
    l := 0
    for i:=0; i < n; i++ {
        if nums[i] != val {
            nums[l] = nums[i]
            l++
        }
    }
    return l
}