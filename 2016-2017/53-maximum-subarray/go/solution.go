// O(n) solution

func maxSubArray(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    maxsum := nums[0]
    curmaxSum := 0
    for _, n := range nums {
        if curmaxSum < 0 {
            curmaxSum = 0
        }
        curmaxSum += n
        if curmaxSum > maxsum {
            maxsum = curmaxSum
        }
    }
    return maxsum
}