// BFS solution, a good idea

func jump(nums []int) int {
    n := len(nums)
    step := 0
    maxStepBrand := 0
    i := 0
    for maxStepBrand < n -1 {
        step++
        curMaxBrand := 0 
        for ;i<=maxStepBrand && i < n;i++{
            if i + nums[i] > curMaxBrand {
                curMaxBrand = i + nums[i]
            }
        } 
        maxStepBrand = curMaxBrand
    }
    
    return step
}

