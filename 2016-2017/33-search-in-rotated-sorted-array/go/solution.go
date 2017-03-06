func search(nums []int, target int) int {
    return searchBinary(nums, target, 0, len(nums) - 1)
}

func searchBinary(nums []int, target int, left int, right int) int {
    if left > right {
        return -1
    }
    mid := (left + right ) / 2
    if target < nums[mid] {
        if nums[mid] < nums[right] {
            return searchBinary(nums, target, left, mid-1)
        } else {
            if target <= nums[right] {
                return searchBinary(nums, target, mid + 1, right)
            } else {
                return searchBinary(nums, target, left, mid-1)
            }
        }
    } else if target > nums[mid] {
        if nums[mid] < nums[right] {
            if target <= nums[right] {
                return searchBinary(nums, target, mid + 1, right)
            } else {
                return searchBinary(nums, target, left, mid-1)
            }            
        } else {
            return searchBinary(nums, target, mid + 1, right)
        }
    } else {
        return mid
    }
}