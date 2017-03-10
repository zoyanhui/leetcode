func maxSubArray(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }
    return maxSubArrayRecursive(nums, 0, n-1)
}

func maxSubArrayRecursive(nums []int, left int, right int) int {
    if left > right {
        return 0
    }
    mid := (left+right)/2
    leftmax := maxSubArrayRecursive(nums, left, mid-1)
    rightmax := maxSubArrayRecursive(nums, mid+1, right)
    if nums[mid] >= 0 {
        return max(max(leftmax+nums[mid], rightmax+nums[mid]), leftmax+rightmax+nums[mid])
    }else{
        return max(max(leftmax, rightmax), leftmax+rightmax+nums[mid])
    }
}

func max(int a, int b) int{
    if a>b {
        return a
    }
    return b
}