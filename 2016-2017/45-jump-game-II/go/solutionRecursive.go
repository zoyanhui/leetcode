// recursive solution, Time Limit Exceeded

func jump(nums []int) int {
    return jumpRecursive(nums, 0)
}

func jumpRecursive(nums []int, curIdx int) int {
    if curIdx >= len(nums)-1 {
        return 0
    }
    minjump := len(nums)
    for i:=1;i<=nums[curIdx];i++ {
        each := jumpRecursive(nums, curIdx+i)
        if each < minjump {
            minjump = each
        }
    }
    return minjump + 1
}