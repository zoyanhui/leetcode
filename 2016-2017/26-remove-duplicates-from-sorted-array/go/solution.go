func removeDuplicates(nums []int) int {
    l := 0
    preIdx := -1
    for idx, n := range nums {
        if preIdx < 0 || n != nums[preIdx] {
            l ++
            nums[l-1] = n
            preIdx = idx
        }
    }
    return l
}





func removeDuplicates(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }
    l := 1
    pre := nums[0]
    for i:=1; i < n;  {
        for i < n && nums[i] == pre{
            i++
        }
        if i < n {
            nums[l] = nums[i]
            l++
            pre = nums[i]
            i++
        }
    }
    return l
}




func removeDuplicates(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }
    l := 0
    for i:=1; i < n; i++ {
        if nums[i] != nums[l] {
            nums[l+1] = nums[i]
            l++
        }
    }
    return l+1
}