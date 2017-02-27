func nextPermutation(nums []int)  {
    n := len(nums)
    if n == 0 {
        return
    }
    i := n-1
    for i > 0 && nums[i] <= nums[i-1] {
        i--
    }
    if i == 0 {
        reverse(nums, 0, n -1)
        return
    }
    minIdx := i
    ri := i+1
    for ri <= n-1 {
        if nums[ri] > nums[i-1] && nums[ri] <= nums[minIdx] {
            minIdx = ri
        }
        ri++
    }
    swap(nums, i-1, minIdx)
    reverse(nums, i, n-1)
}

func swap(nums []int, i int, j int) {
    temp := nums[i]
    nums[i] = nums[j]
    nums[j] = temp
}

func reverse(nums []int, start int, end int) {
    for start < end {
        swap(nums, start, end)
        start++
        end--
    }
}