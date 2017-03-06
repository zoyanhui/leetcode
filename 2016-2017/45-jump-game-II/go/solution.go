// DP solution, too slow
func jump(nums []int) int {
    minjump := make([]int, len(nums))
    for i:=len(nums)-2;i>=0;i--{
        if i + nums[i] >= len(nums) - 1 {
            minjump[i] = 1
            continue
        }
        minjump[i] = -1
        for j:=1;j<=nums[i];j++{
            if minjump[i+j] < 0 {
                continue
            }
            if minjump[i] < 0 || minjump[i] > 1 + minjump[i+j] {
                minjump[i] = 1 + minjump[i+j]
            }
        }
    }
    return minjump[0]
}

