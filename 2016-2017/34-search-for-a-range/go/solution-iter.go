// avaiable solution, two binary search
func searchRange(nums []int, target int) []int {
    srange := []int{-1, -1}
    srange[0] = binarySearch(nums, target, 0, len(nums) - 1, true)
    if srange[0] >= 0 {
        srange[1] = binarySearch(nums, target, 0, len(nums) - 1, false)
    }
    return srange
}

func binarySearch(nums []int, target int, left int, right int, low bool) int {
    for left <= right {
        mid := (left + right) / 2
        if nums[mid] < target {
            left = mid + 1
        } else if nums[mid] > target  {
            right = mid - 1
        } else {
            if low {
                if mid == 0 || nums[mid-1] < target {
                    return mid
                } else {
                    right = mid - 1
                }
            } else {
                if mid == right || nums[mid+1] > target {
                    return mid
                } else {
                    left = mid + 1
                }
            }
            
        }
    }
    return -1
}